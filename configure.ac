# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_PREREQ(2.59)
AC_INIT([oftc-hybrid],[1.7.3])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([libltdl/config])

AC_USE_SYSTEM_EXTENSIONS

AM_INIT_AUTOMAKE([subdir-objects])
AM_SILENT_RULES([yes])
LT_INIT([dlopen])
AC_CONFIG_HEADERS([include/setup.h])
AM_MAINTAINER_MODE
LT_CONFIG_LTDL_DIR([libltdl])
LTDL_INIT([convenience])
AC_LIBTOOL_DLOPEN
AM_ENABLE_SHARED

# Checks for programs.


AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_PROFILING

C_FLAGS_CHECK([-Weverything])
C_FLAGS_CHECK([-Wno-maybe-uninitialized])

AC_PROG_INSTALL
AC_GNU_SOURCE
AC_PROG_CC_C99
  AS_IF([test "$ac_cv_prog_cc_c99" = "no"],
    [AC_MSG_ERROR([no C99 compiler found. Aborting.])])
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
    [AC_CHECK_FUNC([EVP_bf_cfb], [AC_DEFINE([HAVE_EVP_BF_CFB], [1],
      [Define if EVP_bf_cfb exists.])])]
    [AC_CHECK_FUNC([EVP_bf_cfb64], [AC_DEFINE([HAVE_EVP_BF_CFB], [1],
      [Define if EVP_bf_cfb64 exists.])])]
    [AC_CHECK_FUNC([EVP_cast5_cfb], [AC_DEFINE([HAVE_EVP_CAST5_CFB], [1],
      [Define if EVP_cast5_cfb exists.])])]
    [AC_CHECK_FUNC([EVP_cast5_cfb64], [AC_DEFINE([HAVE_EVP_CAST5_CFB], [1],
      [Define if EVP_cast5_cfb64 exists.])])]
    [AC_CHECK_FUNC([EVP_idea_cfb], [AC_DEFINE([HAVE_EVP_IDEA_CFB], [1],
      [Define if EVP_idea_cfb exists.])])]
    [AC_CHECK_FUNC([EVP_idea_cfb64], [AC_DEFINE([HAVE_EVP_IDEA_CFB], [1],
      [Define if EVP_idea_cfb64 exists.])])]
    [AC_CHECK_FUNC([EVP_rc5_32_12_16_cfb], [AC_DEFINE([HAVE_EVP_RC5_32_12_16_CFB], [1],
      [Define if EVP_rc5_32_12_16_cfb exists.])])]
    [AC_CHECK_FUNC([EVP_rc5_32_12_16_cfb64], [AC_DEFINE([HAVE_EVP_RC5_32_12_16_CFB], [1],
      [Define if EVP_rc5_32_12_16_cfb64 exists.])])]
    [AC_CHECK_FUNC([EVP_des_ede3_cfb], [AC_DEFINE([HAVE_EVP_DES_EDE3_CFB], [1],
      [Define if EVP_des_ede3_cfb exists.])])]
    [AC_CHECK_FUNC([EVP_des_ede3_cfb64], [AC_DEFINE([HAVE_EVP_DES_EDE3_CFB], [1],
      [Define if EVP_des_ede3_cfb64 exists.])])]
    [AC_CHECK_FUNC([EVP_des_cfb], [AC_DEFINE([HAVE_EVP_DES_CFB], [1],
      [Define if EVP_des_ede3_cfb exists.])])]
    [AC_CHECK_FUNC([EVP_des_cfb64], [AC_DEFINE([HAVE_EVP_DES_CFB], [1],
      [Define if EVP_des_ede3_cfb exists.])])]
  )], 
  [AC_MSG_RESULT(no - OpenSSL support disabled) 
    cf_enable_openssl="no"]
)

AX_CHECK_LIB_IPV4
AX_CHECK_LIB_IPV6
AX_CHECK_LIB_CRYPT
AX_CHECK_LIB_Z

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
AC_CHECK_FUNC([socketpair],[AC_DEFINE([HAVE_SOCKETPAIR],[1],[Define to 1 if you have the socketpair() function.])])

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

dnl Only put CFLAGS here because configure checks can fail otherwise
CFLAGS="-ggdb3 -O2 -fvar-tracking-assignments -fno-omit-frame-pointer \
	-Wall -Wextra -Werror \
	-Wno-unused-parameter -Wno-implicit-fallthrough -Wno-int-in-bool-context \
	-Wno-format-truncation -Wno-maybe-uninitialized \
	-Wno-error=deprecated-declarations -Wno-error=stringop-overflow \
	$CFLAGS"

AC_DEFINE_DIR([PREFIX],[prefix],[Set to prefix.])
AC_DEFINE_DIR([SYSCONFDIR],[sysconfdir],[Set to sysconfdir.])
AC_DEFINE_DIR([LIBDIR],[libdir],[Set to libdir.])
AC_DEFINE_DIR([MODULEDIR],[moduledir],[Set to moduledir.])
AC_DEFINE_DIR([DATADIR],[datadir],[Set to datadir.])
AC_DEFINE_DIR([LOCALSTATEDIR],[localstatedir],[Set to localstatedir.])
AC_DEFINE_DIR([UHELPDIR], [uhelpdir],[Set to uhelpdir.])
AC_DEFINE_DIR([OHELPDIR], [ohelpdir],[Set to ohelpdir.])

AC_CONFIG_FILES(                
       Makefile                 \
       etc/Makefile             \
       servlink/Makefile        \
       contrib/Makefile         \
       contrib/help/Makefile    \
       src/Makefile             \
       messages/Makefile        \
       modules/Makefile         \
       modules/core/Makefile    \
       doc/Makefile             \
       help/Makefile            \
       help/opers/Makefile      \
       help/users/Makefile      \
       include/Makefile         \
       lib/Makefile             \
       lib/pcre/Makefile
)

AC_OUTPUT
