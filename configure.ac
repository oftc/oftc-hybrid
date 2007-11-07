# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_PREREQ(2.59)
AC_INIT([ircd-hybrid],[7.2.4])
AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE
AC_CONFIG_HEADER(config.h)
AC_CONFIG_SRCDIR(src/ircd.c)

#ltdl stuff
AC_LIBLTDL_CONVENIENCE
AC_SUBST(INCLTDL)
AC_SUBST(LIBLTDL)
AC_LIBTOOL_DLOPEN
AM_DISABLE_STATIC
AM_ENABLE_SHARED

# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AM_PROG_LEX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
LIBTOOL="$LIBTOOL --silent"

# Checks for libraries.
AX_CHECK_LIB_IPV4
AX_CHECK_LIB_IPV6
AX_CHECK_LIB_CRYPT

# Checks for header files.
AC_CHECK_HEADERS([sys/resource.h]) # ick

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_C_BIGENDIAN

AC_CHECK_SIZEOF(int64_t)
AC_CHECK_SIZEOF(long long)

if test "$ac_cv_sizeof_int64_t" = 8; then
  AC_CHECK_TYPE(uint64_t)
  AC_CHECK_TYPE(int64_t)
elif test "$ac_cv_sizeof_long_long" = 8; then
  AC_CHECK_TYPE(uint64_t, unsigned long long)
  AC_CHECK_TYPE(int64_t, long long)
else
  AC_MSG_ERROR([Your system doesn't appear to have 64 bit integers.  Aborting.])
fi


# Checks for library functions.
AC_CHECK_FUNCS_ONCE(snprintf,  \
                    vsnprintf, \
                    lrand48,   \
                    srand48,   \
                    mmap,      \
                    strtok_r,  \
                    usleep,    \
                    strlcat,   \
                    strlcpy,   \
                    basename)

AC_CHECK_HEADERS_ONCE(crypt.h        \
                      inttypes.h     \
                      stdint.h       \
                      sys/resource.h \
                      sys/param.h    \
                      errno.h        \
                      sys/syslog.h   \
                      stddef.h       \
                      libgen.h       \
                      sys/wait.h     \
                      wait.h         \
                      link.h)

dnl Openssl checks
AC_ARG_ENABLE(openssl,
[  --enable-openssl[=DIR]       Enable OpenSSL support (DIR optional).
  --disable-openssl            Disable OpenSSL support. ],
[ cf_enable_openssl=$enableval ],
[ cf_enable_openssl="auto" ])
AC_MSG_CHECKING(for OpenSSL)
if test "$cf_enable_openssl" != "no"; then
  cf_openssl_basedir=""
  if test "$cf_enable_openssl" != "auto" &&
     test "$cf_enable_openssl" != "yes"; then
     dnl Support for --enable-openssl=/some/place
     cf_openssl_basedir="${cf_enable_openssl}"
  else
    dnl Do the auto-probe here.  Check some common directory paths.
    for dirs in /usr/local/ssl /usr/pkg /usr/local /usr/lib /usr/lib/ssl\
                /opt /opt/openssl /usr/local/openssl; do
      if test -f "${dirs}/include/openssl/opensslv.h"; then
        cf_openssl_basedir="${dirs}"
        break
      fi
    done
    unset dirs
  fi

  dnl Now check cf_openssl_found to see if we found anything.
  if test ! -z "$cf_openssl_basedir"; then
    if test -f "${cf_openssl_basedir}/include/openssl/opensslv.h"; then
      CPPFLAGS="-I${cf_openssl_basedir}/include $CPPFLAGS"
      LDFLAGS="-L${cf_openssl_basedir}/lib $LDFLAGS"
    else
      dnl OpenSSL wasn't found in the directory specified.  Naughty
      dnl administrator...
      cf_openssl_basedir=""
    fi
  else
    dnl Check for stock FreeBSD 4.x and 5.x systems, since their files
    dnl are in /usr/include and /usr/lib.  In this case, we don't want to
    dnl change INCLUDES or LIBS, but still want to enable OpenSSL.
    dnl We can't do this check above, because some people want two versions
    dnl of OpenSSL installed (stock FreeBSD 4.x/5.x and /usr/local/ssl)
    dnl and they want /usr/local/ssl to have preference.
    if test -f "/usr/include/openssl/opensslv.h"; then
      cf_openssl_basedir="/usr"
    fi
  fi

  dnl If we have a basedir defined, then everything is okay.  Otherwise,
  dnl we have a problem.
  if test ! -z "$cf_openssl_basedir"; then
    LIBS="-lcrypto -lssl $LIBS"
    AC_MSG_RESULT($cf_openssl_basedir)
    cf_enable_openssl="yes"
    AC_DEFINE(HAVE_LIBCRYPTO)
  else
    AC_MSG_RESULT(not found.  Please check your path.)
    cf_enable_openssl="no"
  fi
  unset cf_openssl_basedir
else
  dnl If --disable-openssl was specified
  AC_MSG_RESULT(disabled)
fi
AM_CONDITIONAL(ENABLE_SSL, [test x"$cf_enable_openssl" = xyes])


# Argument processing.
AX_ARG_ENABLE_IOLOOP_MECHANISM
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
AX_ARG_ENABLE_EFNET
AX_ARG_ENABLE_HALFOPS
AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_WARNINGS
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
       etc/example.conf        \
       etc/example.conf.quick  \
       etc/example.efnet.conf  \
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
       lib/Makefile            \
       lib/pcre/Makefile
)

AC_OUTPUT
