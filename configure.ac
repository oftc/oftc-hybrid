# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_PREREQ(2.63)
AC_INIT([oftc-hybrid],[1.7.0-alpha1])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([include/setup.h])
AM_MAINTAINER_MODE

AC_USE_SYSTEM_EXTENSIONS


#ltdl stuff
LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([dlopen])
LTDL_INIT([convenience])
AC_LIBTOOL_DLOPEN
AM_ENABLE_SHARED

# Checks for programs.
AC_PROG_INSTALL
AC_GNU_SOURCE
AC_PROG_CC_C99
  AS_IF([test "$ac_cv_prog_cc_c99" = "no"],
    [AC_MSG_ERROR([no C99 compiler found. Aborting.])])
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
AX_CHECK_OPENSSL([AC_CHECK_LIB(crypto, RSA_free)
        AS_IF([test "$ac_cv_lib_crypto_RSA_free" = "yes"],
          [AC_CHECK_FUNCS(EVP_bf_cfb           \
                          EVP_cast5_cfb        \
                          EVP_idea_cfb         \
                          EVP_rc5_32_12_16_cfb \
                          EVP_des_ede3_cfb     \
                          EVP_des_cfb)])], [AC_MSG_RESULT(no - OpenSSL support disabled)
  cf_enable_openssl="no"])
AX_CHECK_LIB_IPV4
AX_CHECK_LIB_IPV6


# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE
AC_C_BIGENDIAN

AC_CONFIG_MACRO_DIR([m4])

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


AC_SEARCH_LIBS(crypt, crypt)


AC_ARG_WITH(zlib-path,
AS_HELP_STRING([--with-zlib-path=DIR], [Path to libz.so for ziplinks support.]),
[LDFLAGS="-L$withval $LDFLAGS"],)

AC_ARG_ENABLE(zlib, AS_HELP_STRING([--disable-zlib],[Disable ziplinks support]),
[zlib=$enableval],[zlib=yes])

if test "$zlib" = yes; then
  AC_CHECK_HEADER(zlib.h, [AC_CHECK_LIB(z, zlibVersion,
    [
      LIBS="-lz $LIBS"
      AC_DEFINE(HAVE_LIBZ, 1, [Define to 1 if zlib (-lz) is available.])
    ], zlib=no)
  ], zlib=no)
fi


AH_TEMPLATE([HAVE_LIBCRYPTO], [If we support ssl])

AM_CONDITIONAL(ENABLE_SSL, [test "$cf_enable_openssl" = yes])

AC_ARG_ENABLE(assert, AS_HELP_STRING([--enable-assert], 
                                     [Enable assert() statements]),
  [assert=$enableval], [assert=no])
if test "$assert" = no; then
  AC_DEFINE(NDEBUG, 1, [Define to disable assert() statements.])
fi

AC_ARG_ENABLE(small-net, AS_HELP_STRING([--enable-small-net],
                                        [Enable small network support.]),
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
AX_ARG_DISABLE_BLOCK_ALLOC
AX_ARG_DISABLE_SHARED_MODULES
AX_ARG_WITH_NICKLEN
AX_ARG_WITH_TOPICLEN
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
AC_DEFINE_DIR([MODULEDIR],[moduledir],[Set to moduledir.])
AC_DEFINE_DIR([DATADIR],[datadir],[Set to datadir.])
AC_DEFINE_DIR([LOCALSTATEDIR],[localstatedir],[Set to localstatedir.])

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
       lib/pcre/Makefile      \
       tools/Makefile
)

AC_OUTPUT
