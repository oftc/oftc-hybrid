# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_PREREQ(2.67)
AC_INIT([oftc-hybrid],[1.7.0-alpha1])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([include/config.h])
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
    [AC_MSG_ERROR([no suitable C99 compiler found. Aborting.])])
AC_PROG_INSTALL

LIBTOOL="$LIBTOOL --silent"
AM_PROG_LEX
AC_PROG_LIBTOOL
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

# Checks for typedefs, structures, and compiler characteristics.
AC_C_VOLATILE
AC_C_BIGENDIAN

AC_CONFIG_MACRO_DIR([m4])

# Checks for library functions.
AC_CHECK_FUNCS_ONCE(lrand48     \
                    srand48     \
                    mmap        \
                    strtok_r    \
                    usleep      \
                    strlcat     \
                    strlcpy)

# Checks for header files.
AC_CHECK_HEADERS_ONCE(crypt.h        \
                      sys/resource.h \
                      sys/param.h    \
                      types.h        \
                      socket.h       \
                      sys/wait.h     \
                      wait.h)

AC_SEARCH_LIBS(crypt, crypt)

AH_TEMPLATE([HAVE_LIBCRYPTO], [If we support ssl])

AM_CONDITIONAL(ENABLE_SSL, [test "$ac_cv_lib_ssl_SSL_connect" = yes])

AC_ARG_ENABLE(assert, AS_HELP_STRING([--enable-assert], 
                                     [Enable assert() statements]),
  [assert=$enableval], [assert=no])

AS_IF([test "$assert" = "no"],
  [AC_DEFINE(NDEBUG, 1, [Define to disable assert() statements.])])


AC_DEFINE([NICKNAMEHISTORYLENGTH], 32768, [Size of the WHOWAS array.])
AC_DEFINE([CHANNEL_HEAP_SIZE], 1024, [Size of the channel heap.])
AC_DEFINE([BAN_HEAP_SIZE], 1024, [Size of the ban heap.])
AC_DEFINE([CLIENT_HEAP_SIZE], 1024, [Size of the client heap.])
AC_DEFINE([LCLIENT_HEAP_SIZE], 512, [Size of the local client heap.])
AC_DEFINE([DNODE_HEAP_SIZE], 1024, [Size of the dlink_node heap.])
AC_DEFINE([DBUF_HEAP_SIZE], 512, [Size of the dbuf heap.])
AC_DEFINE([AUTH_HEAP_SIZE], 256, [Size of the auth heap.])
AC_DEFINE([DNS_HEAP_SIZE], 256, [Size of the dns heap.])
AC_DEFINE([WRITE_REQ_HEAP_SIZE], 64, [Size of the write request heap.])
AC_DEFINE([TCP_HANDLE_HEAP_SIZE], 64, [Size of the TCP handle heap.])
AC_DEFINE([UDP_HANDLE_HEAP_SIZE], 64, [Size of the UDP handle heap.])
AC_DEFINE([UDP_SEND_HANDLE_HEAP_SIZE], 64, [Size of the UDP send handle heap.])
AC_DEFINE([BUFFER_HEAP_SIZE], 64, [Size of the read buffer heap.])

# Argument processing.
AX_ARG_DISABLE_BLOCK_ALLOC
AX_ARG_ENABLE_HALFOPS
AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_WARNINGS

AC_DEFINE_DIR([PREFIX],[prefix],[Set to prefix.])
AC_DEFINE_DIR([SYSCONFDIR],[sysconfdir],[Set to sysconfdir.])
AC_DEFINE_DIR([LIBDIR],[libdir],[Set to libdir.])
AC_DEFINE_DIR([MODULEDIR],[moduledir],[Set to moduledir.])
AC_DEFINE_DIR([DATADIR],[datadir],[Set to datadir.])
AC_DEFINE_DIR([LOCALSTATEDIR],[localstatedir],[Set to localstatedir.])

AC_CONFIG_FILES(               \
       Makefile                \
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
       tools/Makefile)

AC_OUTPUT
