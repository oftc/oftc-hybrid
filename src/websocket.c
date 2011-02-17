#include "stdinc.h"

#ifdef WEBSOCKETS

#include "tools.h"
#include "ircd.h"
#include "listener.h"
#include "libwebsockets.h"
#include "client.h"
#include "s_bsd.h"
#include "packet.h"
#include "send.h"
#include "s_stats.h"
#include "s_conf.h"

enum hybrid_protocols {
  IRC,
  PROTOCOL_COUNT,
};

struct WebSocketData {
  struct Client *client;
};

static int
websocket_protocol_callback(struct libwebsocket_context *, struct libwebsocket *,
  enum libwebsocket_callback_reasons, void *, void *, size_t len);

static struct libwebsocket_protocols protocols[] = {
  [IRC] = {
    .name = "irc",
    .callback = websocket_protocol_callback,
    .per_session_data_size = sizeof(struct WebSocketData),
  },
  [PROTOCOL_COUNT] = {
    .callback = NULL,
  }
};

void
websocket_add(struct Listener *listener, const char *vhost)
{
  /* TODO FIXME XXX libwebsockets doesn't support bound ip yet */
  listener->wsc = libwebsocket_create_context(listener->port, protocols,
    ServerInfo.ssl_certificate_file,
    ServerInfo.rsa_private_key_file, -1, -1, 0);
}

void
websocket_poll()
{
  dlink_node *ptr;
  struct Listener *listener = NULL;
  DLINK_FOREACH(ptr, ListenerPollList.head) {
    listener = ptr->data;
    if(IsWebsocket(listener)) {
      libwebsocket_service(listener->wsc, 0);
    }
  }
}

static int
websocket_protocol_callback(struct libwebsocket_context *wsc, struct libwebsocket *wsi,
  enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
{
  struct WebSocketData *wsd = user;
  switch(reason) {
    case LWS_CALLBACK_FILTER_NETWORK_CONNECTION:
      {
        struct irc_ssaddr addr;
        socklen_t addrlen = sizeof(addr);
        int fd = (int)user;
        int pe;
        dlink_node *ptr;
        struct Listener *listener = NULL;

        DLINK_FOREACH(ptr, ListenerPollList.head)
        {
          listener = ptr->data;
          if(IsWebsocket(listener) && listener->wsc == wsc && !listener->active)
            return 1;
        }

        getpeername(fd, (struct sockaddr *)&addr, &addrlen);
        addr.ss_len = addrlen;

        if (number_fd > hard_fdlimit - 10)
        {
          ++ServerStats->is_ref;
          return 1;
        }

        if ((pe = conf_connect_allowed(&addr, addr.ss.ss_family)) != 0)
        {
          ++ServerStats->is_ref;
          return 1;
        }
      }
      break;
    case LWS_CALLBACK_CLOSED:
      if(wsd && wsd->client)
        exit_client(wsd->client, &me, "Remote host closed the connection");
      break;
    case LWS_CALLBACK_ESTABLISHED:
      {
        dlink_node *ptr;
        struct Listener *listener = NULL;
        DLINK_FOREACH(ptr, ListenerPollList.head) {
          listener = ptr->data;
          if(IsWebsocket(listener) && listener->wsc == wsc)
          {
            int fd = libwebsocket_get_socket_fd(wsi);
            struct irc_ssaddr addr;
            socklen_t addrlen = sizeof(struct irc_ssaddr);

            getpeername(fd, (struct sockaddr *)&addr, &addrlen);
            addr.ss_len = addrlen;

            ++ServerStats->is_ac;
            add_connection(listener, (struct irc_ssaddr *)&addr, fd, &wsd->client);
            wsd->client->localClient->fd.websocket = wsi;
            break;
          }
        }
      }
      break;
    case LWS_CALLBACK_RECEIVE:
      if(wsd && wsd->client)
      {
        execute_callback(iorecv_cb, wsd->client, len, in);
        if(wsd->client->flags & FLAGS_FINISHED_AUTH)
          finish_client_read(wsd->client);
      }
      break;
    case LWS_CALLBACK_HTTP:
      if(ConfigFileEntry.websocket_redirect &&
         strlen(ConfigFileEntry.websocket_redirect) > 0)
      {
        char buf[512];
        size_t len = snprintf(buf, sizeof(buf),
          "HTTP/1.0 301 Moved Permanently\x0d\x0a"
          "Location: %s\x0d\x0a"
          "\x0d\x0a",
          ConfigFileEntry.websocket_redirect);
        libwebsocket_write(wsi, (unsigned char *)buf, len, LWS_WRITE_HTTP);
      }
      break;
    default:
      break;
  }

  return 0;
}

int
websocket_write(struct Client *client, const char *oldbuf, size_t len)
{
  if(!IsDead(client) || !IsSendqBlocked(client))
  {
    int ret;
    unsigned char *buf = MyMalloc(LWS_SEND_BUFFER_PRE_PADDING + len + LWS_SEND_BUFFER_POST_PADDING);
    memcpy(&buf[LWS_SEND_BUFFER_PRE_PADDING], oldbuf, len);
    ret = libwebsocket_write(client->localClient->fd.websocket, &buf[LWS_SEND_BUFFER_PRE_PADDING], len, LWS_WRITE_TEXT);
    MyFree(buf);
    if(ret == 0) {
      ret = 1;
    }
    return ret;
  }
  return 0;
}

void
websocket_close(struct Client *client)
{
  if(client->localClient->fd.websocket)
    libwebsockets_hangup_on_client(client->localClient->listener->wsc, client->localClient->fd.fd);
}

void
websocket_close_listener(struct Listener *listener)
{
  if (IsWebsocket(listener) && listener->wsc)
    libwebsocket_context_destroy(listener->wsc);
}

#endif
