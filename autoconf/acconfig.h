/*
 * $Id$
 */

/* Define if you have the poll() system call.  */
#undef USE_POLL

/* Define with our select type */
#undef SELECT_TYPE

/* Define if we are going to use /dev/poll for network IO */
#undef HAVE_DEVPOLL

#undef USE_DEVPOLL

/* Using kqueue */
#undef USE_KQUEUE

/* Using poll */
#undef USE_POLL

/* Using select */
#undef USE_SELECT

/* Using devpoll */
#undef USE_DEVPOLL

/* Using sigio */
#undef USE_SIGIO

/* Define if we have socklen_t */
#undef HAVE_SOCKLEN_T

/* Define if we have uintptr_t */
#undef HAVE_UINTPTR_T

/* Define if we need HAVE_SHL_LOAD - HPUX */
#undef HAVE_SHL_LOAD

/* Define based upon RLIMIT value is found in sys/resource.h */
/* By default, we assume nothing is found. */
#undef RLIMIT_FD_MAX

/* Define if we can include both string.h and strings.h */
#undef STRING_WITH_STRINGS

/* This is a string containing any extra underscores that must be prepended
 * to symbols loaded from modules.
 */
#undef SYMBOL_PREFIX

/* IPv6 support */
#undef IPV6

/* u_int32_t */
#undef u_int32_t

/* static modules */
#undef STATIC_MODULES

/* No block allocator */
#undef NOBALLOC

/* Gettext support */
#undef HAVE_GETTEXT

/* nanosleep */
#undef HAVE_NANOSLEEP

/* nicklen */
#undef NICKLEN

/* max_clients */
#undef MAX_CLIENTS

/* topiclen */
#undef TOPICLEN

/* EFNET */
#undef EFNET

