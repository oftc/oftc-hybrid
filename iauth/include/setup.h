#ifndef INCLUDED_setup_h
#define INCLUDED_setup_h

/*
 * CONFFILE - Path to IAuth configuration file
 * LOGFILE  - Path to the IAuth log file
 */

#define CONFFILE     "iauth.conf"
#define LOGFILE      "iauth.log"

#undef SPOOF_FREEFORM
#define DEBUGMODE

/* CONNECTTIMEOUT -
 * Number of seconds to wait for a connect(2) call to complete.
 * NOTE: this must be at *LEAST* 10.  When a client connects, it has
 * CONNECTTIMEOUT - 10 seconds for its host to respond to an ident lookup
 * query and for a DNS answer to be retrieved.
 */
#define CONNECTTIMEOUT  30      /* Recommended value: 30 */

#endif /* INCLUDED_setup_h */
