#ifndef INCLUDED_websocket_h
#define INCLUDED_websocket_h

#include "listener.h"
#include "client.h"

extern void websocket_add(struct Listener *, const char *);
extern void websocket_poll();
extern void websocket_write(struct Client *, char *, int);
extern void websocket_close(struct Client *);

#endif //INCLUDED_websocket_h
