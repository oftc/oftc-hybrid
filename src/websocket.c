#include "stdinc.h"
#include "tools.h"
#include "ircd.h"
#include "listener.h"
#include "libwebsockets.h"
#include "client.h"
#include "s_bsd.h"
#include "packet.h"

enum hybrid_protocols {
  IRC,
  PROTOCOL_COUNT,
};

struct WebSocketData {
  struct Listener *listener;
  struct Client *client;
};

static int
websocket_protocol_callback(struct libwebsocket *wsi,
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
    NULL, NULL, -1, -1, 0);
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
websocket_protocol_callback(struct libwebsocket *wsi,
  enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
{
  struct WebSocketData *wsd = user;
  switch(reason) {
    case LWS_CALLBACK_ESTABLISHED:
      {
        /* TODO XXX FIXME Flood and Dline Detection */
        dlink_node *ptr;
        struct Listener *listener = NULL;
        const struct libwebsocket_protocols *proto = libwebsockets_get_protocol(wsi);
        DLINK_FOREACH(ptr, ListenerPollList.head) {
          listener = ptr->data;
          if(IsWebsocket(listener) && listener->wsc == proto->owning_server)
          {
            int fd = libwebsocket_get_socket_fd(wsi);
            struct irc_ssaddr addr;
            socklen_t addrlen = sizeof(struct irc_ssaddr);

            getpeername(fd, (struct sockaddr *)&addr, &addrlen);
            addr.ss_len = addrlen;

            wsd->listener = listener;
            add_connection(listener, (struct irc_ssaddr *)&addr, fd, &wsd->client);
            wsd->client->localClient->wsi = wsi;
            wsd->client->localClient->fd.websocket = 1;
            break;
          }
        }
      }
      break;
    case LWS_CALLBACK_CLOSED:
      exit_client(wsd->client, &me, "Remote host closed the connection");
      break;
    case LWS_CALLBACK_RECEIVE:
      {
        execute_callback(iorecv_cb, wsd->client, len, in);
        if(wsd->client->flags & FLAGS_FINISHED_AUTH)
        {
          if (wsd->client->lasttime < CurrentTime)
            wsd->client->lasttime = CurrentTime;
          if (wsd->client->lasttime > wsd->client->since)
            wsd->client->since = CurrentTime;
          ClearPingSent(wsd->client);
          parse_client_queued(wsd->client);
          /* TODO XXX FIXME Flood Detection */
        }
      }
      break;
    case LWS_CALLBACK_HTTP:
      /* TODO XXX FIXME probably drop this client */
      exit_client(wsd->client, &me, "Remote host sent invalid command -- HTTP");
      break;
    default:
      break;
  }

  return 0;
}

void
websocket_write(struct Client *client, const char *oldbuf, size_t len)
{
  /* TODO XXX FIXME This seems pretty optimistic */
  unsigned char *buf = MyMalloc(LWS_SEND_BUFFER_PRE_PADDING + len + LWS_SEND_BUFFER_POST_PADDING);
  memcpy(&buf[LWS_SEND_BUFFER_PRE_PADDING], oldbuf, len);
  libwebsocket_write(client->localClient->wsi, &buf[LWS_SEND_BUFFER_PRE_PADDING], len, LWS_WRITE_TEXT);
  MyFree(buf);
}

void
websocket_close(struct Client *client)
{
  /* TODO XXX FIXME this is probably going to nullref sometime */
  /* this probably shouldn't be in the private externs send upstream */
  libwebsocket_close_and_free_session(client->localClient->wsi);
}
