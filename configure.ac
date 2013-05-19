# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_PREREQ(2.59)
AC_INIT([oftc-hybrid],[1.7.0])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([include/setup.h])
AM_MAINTAINER_MODE

#ltdl stuff
AC_LIBTOOL_DLOPEN
AC_LIBLTDL_CONVENIENCE
AC_SUBST(INCLTDL)
AC_SUBST(LIBLTDL)

# Checks for programs.
AC_PROG_INSTALL
AC_GNU_SOURCE
AC_PROG_CC
AC_PROG_RANLIB
AC_PROG_LIBTOOL
LIBTOOL="$LIBTOOL --silent"
AM_PROG_LEX
AC_PROG_YACC
AC_PROG_AWK
AC_PROG_EGREP
AC_PATH_PROG([TAIL],[tail])
AM_PROG_CC_C_O

# Checks for libraries.
AX_CHECK_LIB_OPENSSL
AX_CHECK_LIB_IPV4
AX_CHECK_LIB_IPV6
AX_CHECK_LIB_CRYPT

# Checks for header files.
AC_CHECK_HEADERS([sys/resource.h]) # ick

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE
AC_C_BIGENDIAN

# Checks for library functions.
AC_CHECK_FUNC([snprintf],[AC_DEFINE([HAVE_SNPRINTF],[1],[Define to 1 if you have the snprintf() function.])])
AC_CHECK_FUNC([vsnprintf],[AC_DEFINE([HAVE_VSNPRINTF],[1],[Define to 1 if you have the vsnprintf() function.])])
AC_CHECK_FUNC([lrand48],[AC_DEFINE([HAVE_LRAND48],[1],[Define to 1 if you have the lrand48() function.])])
AC_CHECK_FUNC([srand48],[AC_DEFINE([HAVE_LRAND48],[1],[Define to 1 if you have the srand48() function.])])
AC_CHECK_FUNC([mmap],[AC_DEFINE([HAVE_MMAP],[1],[Define to 1 if you have the mmap() function.])])
AC_CHECK_FUNC([strtok_r],[AC_DEFINE([HAVE_STRTOK_R],[1],[Define to 1 if you have the strtok_r() function.])])
AC_CHECK_FUNC([usleep],[AC_DEFINE([HAVE_USLEEP],[1],[Define to 1 if you have the usleep() function.])])
AC_CHECK_FUNC([strlcat],[AC_DEFINE([HAVE_STRLCAT],[1],[Define to 1 if you have the strlcat() function.])])
AC_CHECK_FUNC([strlcpy],[AC_DEFINE([HAVE_STRLCPY],[1],[Define to 1 if you have the strlcpy() function.])])
AC_CHECK_FUNC([basename],[AC_DEFINE([HAVE_BASENAME],[1],[Define to 1 if you have the basename() function.])])

# Argument processing.
AX_ARG_ENABLE_IOLOOP_MECHANISM
AX_ARG_DISABLE_BLOCK_ALLOC
AX_ARG_DISABLE_SHARED_MODULES
AX_ARG_WITH_NICKLEN
AX_ARG_WITH_USERLEN
AX_ARG_WITH_HOSTLEN
AX_ARG_WITH_TOPICLEN
AX_ARG_WITH_LCLIENT_HEAP_SIZE
AX_ARG_WITH_CLIENT_HEAP_SIZE
AX_ARG_WITH_CHANNEL_HEAP_SIZE
AX_ARG_WITH_DBUF_HEAP_SIZE
AX_ARG_WITH_DNODE_HEAP_SIZE
AX_ARG_WITH_BAN_HEAP_SIZE
AX_ARG_WITH_TOPIC_HEAP_SIZE
AX_ARG_WITH_IRCD_HEAP_SIZE
AX_ARG_WITH_MQUEUE_HEAP_SIZE
AX_ARG_WITH_FMSG_HEAP_SIZE
AX_ARG_WITH_NICKNAME_HISTORY_LENGTH
AX_ARG_WITH_SYSLOG
AX_ARG_WITH_SERVICS_NAME
AX_ARG_ENABLE_EFNET
AX_ARG_ENABLE_HALFOPS
AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_WARNINGS
AX_ARG_ENABLE_EFENCE
AX_ARG_ENABLE_SYSLOG

AC_DEFINE_DIR([PREFIX],[prefix],[Set to prefix.])
AC_DEFINE_DIR([SYSCONFDIR],[sysconfdir],[Set to sysconfdir.])
AC_DEFINE_DIR([LIBDIR],[libdir],[Set to libdir.])
AC_DEFINE_DIR([DATADIR],[datadir],[Set to datadir.])
AC_DEFINE_DIR([LOCALSTATEDIR],[localstatedir],[Set to localstatedir.])
AC_CONFIG_SUBDIRS(libltdl)

AC_CONFIG_FILES(               \
       Makefile                \
       etc/Makefile            \
       servlink/Makefile       \
       contrib/Makefile        \
       contrib/help/Makefile   \
       src/Makefile            \
       messages/Makefile       \
       modules/Makefile        \
			 modules/core/Makefile	 \
       doc/Makefile            \
       help/Makefile           \
			 help/opers/Makefile		 \
			 help/users/Makefile     \
			 include/Makefile        \
       lib/Makefile            \
       lib/pcre/Makefile
)

AC_OUTPUT
