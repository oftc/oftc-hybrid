# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_REVISION([$Id$])

AC_PREREQ(2.63)
AC_INIT([ircd-hybrid], [7.2.4])
AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE
AC_CONFIG_HEADER(config.h)
AC_CONFIG_SRCDIR(src/ircd.c)


# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AM_PROG_LEX
AC_PROG_INSTALL


#ltdl stuff
LT_INIT([dlopen])
LTDL_INIT
LIBTOOL="$LIBTOOL --silent"


# Checks for libraries.
AX_CHECK_LIB_IPV4
AX_CHECK_LIB_IPV6


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
AC_CHECK_FUNCS_ONCE(snprintf  \
                    vsnprintf \
                    lrand48   \
                    srand48   \
                    mmap      \
                    strtok_r  \
                    usleep    \
                    strlcat   \
                    strlcpy   \
                    basename)

# Checks for header files.
AC_CHECK_HEADERS_ONCE(crypt.h        \
                      inttypes.h     \
                      stdint.h       \
                      sys/resource.h \
                      sys/param.h    \
                      errno.h        \
                      sys/syslog.h   \
                      stddef.h       \
                      libgen.h       \
                      types.h        \
                      socket.h       \
                      sys/wait.h     \
                      wait.h         \
                      link.h)

dnl check for /dev/null so we can use it to hold evil fd's
AC_MSG_CHECKING([for /dev/null])
if test -c /dev/null ; then
  AC_DEFINE(PATH_DEVNULL, "/dev/null", [Path to /dev/null])
  AC_MSG_RESULT(yes)
else
  AC_DEFINE(PATH_DEVNULL, "devnull.log", [Path to /dev/null])
  AC_MSG_RESULT(no - using devnull.log)
fi


AC_SEARCH_LIBS(crypt, [crypt descrypt],,)
AM_CONDITIONAL([HAVE_CRYPT], [test "$ac_cv_search_crypt" = "none required"])


AC_ARG_WITH(zlib-path,
AC_HELP_STRING([--with-zlib-path=DIR], [Path to libz.so for ziplinks support.]),
[LDFLAGS="-L$withval $LDFLAGS"],)

AC_ARG_ENABLE(zlib, AC_HELP_STRING([--disable-zlib],[Disable ziplinks support]),
[zlib=$enableval],[zlib=yes])

if test "$zlib" = yes; then
  AC_CHECK_HEADER(zlib.h, [AC_CHECK_LIB(z, zlibVersion,
    [
      LIBS="-lz $LIBS"
      AC_DEFINE(HAVE_LIBZ, 1, [Define to 1 if zlib (-lz) is available.])
    ], zlib=no)
  ], zlib=no)
fi


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
    AC_DEFINE(HAVE_LIBCRYPTO, 1, [If we support ssl])
  else
    AC_MSG_RESULT(not found.  Please check your path.)
    cf_enable_openssl="no"
  fi
  unset cf_openssl_basedir
else
  dnl If --disable-openssl was specified
  AC_MSG_RESULT(disabled)
fi
AM_CONDITIONAL(ENABLE_SSL, [test "$cf_enable_openssl" = yes])


AC_ARG_ENABLE(assert, AC_HELP_STRING([--enable-assert], [Enable assert() statements]),
  [assert=$enableval], [assert=no])
if test "$assert" = no; then
  AC_DEFINE(NDEBUG, 1, [Define to disable assert() statements.])
fi


AC_ARG_ENABLE(small-net,
AC_HELP_STRING([--enable-small-net],[Enable small network support.]),
[small_net=$enableval], [small_net=no])

if test "$small_net" = yes; then
  AC_DEFINE([NICKNAMEHISTORYLENGTH], 1500, [Size of the WHOWAS array.])
  AC_DEFINE([CHANNEL_HEAP_SIZE], 256, [Size of the channel heap.])
  AC_DEFINE([BAN_HEAP_SIZE], 128, [Size of the ban heap.])
  AC_DEFINE([CLIENT_HEAP_SIZE], 256, [Size of the client heap.])
  AC_DEFINE([LCLIENT_HEAP_SIZE], 128, [Size of the local client heap.])
  AC_DEFINE([DNODE_HEAP_SIZE], 256, [Size of the dlink_node heap.])
  AC_DEFINE([TOPIC_HEAP_SIZE], 256, [Size of the topic heap.])
  AC_DEFINE([DBUF_HEAP_SIZE], 64, [Size of the dbuf heap.])
else
  AC_DEFINE([NICKNAMEHISTORYLENGTH], 15000, [Size of the WHOWAS array.])
  AC_DEFINE([CHANNEL_HEAP_SIZE], 1024, [Size of the channel heap.])
  AC_DEFINE([BAN_HEAP_SIZE], 1024, [Size of the ban heap.])
  AC_DEFINE([CLIENT_HEAP_SIZE], 1024, [Size of the client heap.])
  AC_DEFINE([LCLIENT_HEAP_SIZE], 512, [Size of the local client heap.])
  AC_DEFINE([DNODE_HEAP_SIZE], 1024, [Size of the dlink_node heap.])
  AC_DEFINE([TOPIC_HEAP_SIZE], 1024, [Size of the topic heap.])
  AC_DEFINE([DBUF_HEAP_SIZE], 512, [Size of the dbuf heap.])
fi


# Argument processing.
AX_ARG_ENABLE_IOLOOP_MECHANISM
AX_ARG_WITH_NICKLEN
AX_ARG_WITH_TOPICLEN
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

AC_CONFIG_FILES(              \
       Makefile               \
       etc/Makefile           \
       etc/example.conf       \
       etc/example.conf.quick \
       etc/example.efnet.conf \
       servlink/Makefile      \
       contrib/Makefile       \
       contrib/help/Makefile  \
       src/Makefile           \
       messages/Makefile      \
       modules/Makefile       \
			 modules/core/Makefile	\
       doc/Makefile           \
       help/Makefile          \
			 help/opers/Makefile		\
			 help/users/Makefile    \
       lib/Makefile           \
       lib/pcre/Makefile      \
       tools/Makefile
)

AC_OUTPUT
