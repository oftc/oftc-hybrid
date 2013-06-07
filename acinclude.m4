dnl Inspired by work Copyright (C) 2006 Luca Filipozzi
dnl vim: set fdm=marker sw=2 ts=2 et si:
dnl {{{ ax_check_lib_ipv4
AC_DEFUN([AX_CHECK_LIB_IPV4],[
  AC_CHECK_FUNC(getaddrinfo, [], AC_SEARCH_LIBS(getaddrinfo, nsl))
  AC_CHECK_FUNC(getnameinfo, [], AC_SEARCH_LIBS(getnameinfo, nsl))
  AC_SEARCH_LIBS([socket],[socket],,[AC_MSG_ERROR([socket library not found])])
  AC_CHECK_TYPES([struct sockaddr_in, struct sockaddr_storage, struct addrinfo],,,[#include <sys/types.h>
   #include <sys/socket.h>
   #include <netdb.h>
  ])
  AC_CHECK_MEMBERS([struct sockaddr_in.sin_len],,,[#include <sys/types.h>
  <sys/socket.h>])
])dnl }}}
dnl {{{ ax_arg_disable_block_alloc
AC_DEFUN([AX_ARG_DISABLE_BLOCK_ALLOC],[
  AC_ARG_ENABLE([block-alloc],[AC_HELP_STRING([--disable-block-alloc],[Disable block alloc.])],[block_alloc="$enableval"],[block_alloc="yes"])
  if test "$block_alloc" = "no" ; then
    use_block_alloc=0
  else
    use_block_alloc=1
  fi
  AC_DEFINE_UNQUOTED([USE_BLOCK_ALLOC],[$use_block_alloc],[use block alloc])
])dnl }}}
dnl {{{ ax_arg_enable_halfops
AC_DEFUN([AX_ARG_ENABLE_HALFOPS],[
  AC_ARG_ENABLE([halfops],[AS_HELP_STRING([--enable-halfops],[Enable halfops support.])],[halfops="$enableval"],[halfops="no"])
  if test "$halfops" = "yes" ; then
    AC_DEFINE([HALFOPS],[1],[Define to 1 if you want halfops support.])
  fi
])dnl }}}
dnl {{{ ax_arg_enable_debugging
AC_DEFUN([AX_ARG_ENABLE_DEBUGGING],[
  AC_ARG_ENABLE([debugging],[AS_HELP_STRING([--enable-debugging],[Enable debugging.])],[debugging="$enableval"],[debugging="no"])
  if test "$debugging" = "yes" ; then
    CFLAGS="-Werror -Wall -g -O0"
  fi
])dnl }}}
dnl {{{ ax_arg_enable_warnings
AC_DEFUN([AX_ARG_ENABLE_WARNINGS],[
  AC_ARG_ENABLE([warnings],[AS_HELP_STRING([--enable-warnings],[Enable compiler warnings.])],[warnings="$enableval"],[warnings="no"])
  if test "$warnings" = "yes" ; then
    CFLAGS="-Werror -Wall -Wextra -Wno-unused -Wcast-qual -Wcast-align -Wbad-function-cast -Wmissing-declarations -Wmissing-prototypes -Wnested-externs -Wredundant-decls -Wshadow -Wwrite-strings -Wundef"
  fi
])dnl }}}
dnl {{{ ax_arg_enable_efence
AC_DEFUN([AX_ARG_ENABLE_EFENCE],[
  AC_ARG_ENABLE([efence],[AC_HELP_STRING([--enable-efence],[Enable compilation with ElectricFence.])],[efence="$enableval"],[efence="no"])
  if test "$efence" = "yes" ; then
    AC_SEARCH_LIBS([malloc],[efence],,[AC_MSG_ERROR([efence library not found])])
  fi
])dnl }}}
dnl {{{ ac_define_dir
dnl http://autoconf-archive.cryp.to/ac_define_dir.html
AC_DEFUN([AC_DEFINE_DIR], [
  prefix_NONE=
  exec_prefix_NONE=
  test "x$prefix" = xNONE && prefix_NONE=yes && prefix=$ac_default_prefix
  test "x$exec_prefix" = xNONE && exec_prefix_NONE=yes && exec_prefix=$prefix
  eval ac_define_dir="\"[$]$2\""
  eval ac_define_dir="\"$ac_define_dir\""
  AC_SUBST($1, "$ac_define_dir")
  AC_DEFINE_UNQUOTED($1, "$ac_define_dir", [$3])
  test "$prefix_NONE" && prefix=NONE
  test "$exec_prefix_NONE" && exec_prefix=NONE
])dnl }}}
]) dnl }}}

dnl {{{ ax_Arg_with_services_name
  AC_DEFUN([AX_ARG_WITH_SERVICS_NAME],[
      AC_ARG_WITH([services-name],[AC_HELP_STRING([--with-services-name=SERVICES_NAME],[Set the name of your
          services server])],[services_name="$withval"],[services_name="services.oftc.net"])
      AC_DEFINE_UNQUOTED(SERVICES_NAME,"$services_name",[Name of the services
        server.])
      ]) dnl }}}
