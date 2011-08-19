dnl Inspired by work Copyright (C) 2006 Luca Filipozzi
dnl vim: set fdm=marker sw=2 ts=2 et si:
dnl {{{ ax_check_crypt
AC_DEFUN([AX_CHECK_LIB_CRYPT],[
	AC_SEARCH_LIBS(crypt, [crypt descrypt],,)
  AM_CONDITIONAL([HAVE_CRYPT],[test "$ac_cv_search_crypt" = "none required"])
])dnl }}}
dnl {{{ ax_check_lib_openssl
AC_DEFUN([AX_CHECK_LIB_OPENSSL],[
  AC_CHECK_HEADER([openssl/sha.h],,[AC_MSG_ERROR([openssl header files not found])])
  AC_CHECK_LIB([ssl],[SHA_Init],,[AC_MSG_ERROR([openssl library not found])])
  AC_CHECK_LIB([crypto],[EVP_MD_CTX_init],,[AC_MSG_ERROR([openssl library not found])])
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
dnl {{{ ax_arg_disable_shared_modules (FIXME)
AC_DEFUN([AX_ARG_DISABLE_SHARED_MODULES],[
  AC_ARG_ENABLE([shared-modules],[AC_HELP_STRING([--disable-shared-modules],[Disable shared modules.])],[shared_modules="$enableval"],[shared_modules="yes"])
  AC_CHECK_HEADERS([dlfcn.h link.h])
  AC_CHECK_FUNCS([dlopen dlinfo])
  if test "$shared_modules" = "yes" ; then
    use_shared_modules="yes"
    AC_CHECK_LIB([dl],[dlopen],,[AC_MSG_ERROR([dl library not found])])
    AC_DEFINE([USE_SHARED_MODULES],[1],[Define to 1 if you want to use shared modules.])
  else
    use_shared_modules="no"
    AC_MSG_WARN([shared module support has been disabled per supplied configure option])
  fi
  AM_CONDITIONAL([USE_SHARED_MODULES],[test "$shared_modules" = "yes"])
])dnl }}}
dnl {{{ ax_arg_with_topiclen
AC_DEFUN([AX_ARG_WITH_TOPICLEN],[
  AC_ARG_WITH([topiclen],[AC_HELP_STRING([--with-topiclen=<value>],[Set topic length (default 160).])],[topiclen="$withval"],[topiclen="160"])
  AC_DEFINE_UNQUOTED([TOPICLEN],[($topiclen+1)],[Length of topics.]) 
])dnl }}}
dnl {{{ ax_arg_with_nicklen
AC_DEFUN([AX_ARG_WITH_NICKLEN],[
  AC_ARG_WITH([nicklen],[AC_HELP_STRING([--with-nicklen=<value>],[Set nickname length (default 9).])],[nicklen="$withval"],[nicklen="9"])
  AC_DEFINE_UNQUOTED([NICKLEN],[($nicklen+1)],[Length of nicknames.]) 
])dnl }}}
dnl {{{ ax_arg_with_userlen
AC_DEFUN([AX_ARG_WITH_USERLEN],[
  AC_ARG_WITH([userlen],[AC_HELP_STRING([--with-userlen=<value>],[Set username length (default 9).])],[userlen="$withval"],[userlen="9"])
  AC_DEFINE_UNQUOTED([USERLEN],[($userlen+1)],[Length of nicknames.]) 
])dnl }}}
dnl {{{ ax_arg_with_hostlen
AC_DEFUN([AX_ARG_WITH_HOSTLEN],[
  AC_ARG_WITH([hostlen],[AC_HELP_STRING([--with-hostlen=<value>],[Set username length (default 62).])],[hostlen="$withval"],[hostlen="62"])
  AC_DEFINE_UNQUOTED([HOSTLEN],[($hostlen+1)],[Length of nicknames.]) 
])dnl }}}
dnl {{{ ax_arg_with_lclient_heap_size
AC_DEFUN([AX_ARG_WITH_LCLIENT_HEAP_SIZE],[
  AC_ARG_WITH([lclient-heap-size],[AC_HELP_STRING([--lclient-heap-size=<value>],[Set local client heap size (default 256).])],[lclient_heap_size="$withval"],[lclient_heap_size="256"])
  AC_DEFINE_UNQUOTED([LCLIENT_HEAP_SIZE],[$lclient_heap_size],[Size of the local client heap.])
])dnl }}}
dnl {{{ ax_arg_with_nickname_history_length
AC_DEFUN([AX_ARG_WITH_NICKNAME_HISTORY_LENGTH],[
  AC_ARG_WITH([nickname-history-length],[AC_HELP_STRING([--nickname-history-length=<value>],[Set length of nickname history list (default 1500).])],[nickname_history_length="$withval"],[nickname_history_length="1500"])
  AC_DEFINE_UNQUOTED([NICKNAMEHISTORYLENGTH],[$nickname_history_length],[Size of the nickname history list.])
])dnl }}}
dnl {{{ ax_arg_with_client_heap_size
AC_DEFUN([AX_ARG_WITH_CLIENT_HEAP_SIZE],[
  AC_ARG_WITH([client-heap-size],[AC_HELP_STRING([--client-heap-size=<value>],[Set client heap size (default 256).])],[client_heap_size="$withval"],[client_heap_size="256"])
  AC_DEFINE_UNQUOTED([CLIENT_HEAP_SIZE],[$client_heap_size],[Size of the client heap.])
])dnl }}}
dnl {{{ ax_arg_with_channel_heap_size
AC_DEFUN([AX_ARG_WITH_CHANNEL_HEAP_SIZE],[
  AC_ARG_WITH([channel-heap-size],[AC_HELP_STRING([--channel-heap-size=<value>],[Set channel heap size (default 256).])],[channel_heap_size="$withval"],[channel_heap_size="256"])
  AC_DEFINE_UNQUOTED([CHANNEL_HEAP_SIZE],[$channel_heap_size],[Size of the channel heap.])
])dnl }}}
dnl {{{ ax_arg_with_dbuf_heap_size
AC_DEFUN([AX_ARG_WITH_DBUF_HEAP_SIZE],[
  AC_ARG_WITH([dbuf-heap-size],[AC_HELP_STRING([--dbuf-heap-size=<value>],[Set dbuf heap size (default 64).])],[dbuf_heap_size="$withval"],[dbuf_heap_size="64"])
  AC_DEFINE_UNQUOTED([DBUF_HEAP_SIZE],[$dbuf_heap_size],[Size of the dbuf heap.])
])dnl }}}
dnl {{{ ax_arg_with_dnode_heap_size
AC_DEFUN([AX_ARG_WITH_DNODE_HEAP_SIZE],[
  AC_ARG_WITH([dnode-heap-size],[AC_HELP_STRING([--dnode-heap-size=<value>],[Set dnode heap size (default 256).])],[dnode_heap_size="$withval"],[dnode_heap_size="256"])
  AC_DEFINE_UNQUOTED([DNODE_HEAP_SIZE],[$dnode_heap_size],[Size of the dlink_node heap.])
])dnl }}}
dnl {{{ ax_arg_with_ban_heap_size
AC_DEFUN([AX_ARG_WITH_BAN_HEAP_SIZE],[
  AC_ARG_WITH([ban-heap-size],[AC_HELP_STRING([--ban-heap-size=<value>],[Set ban heap size (default 128).])],[ban_heap_size="$withval"],[ban_heap_size="128"])
  AC_DEFINE_UNQUOTED([BAN_HEAP_SIZE],[$ban_heap_size],[Size of the ban heap.])
])dnl }}}
dnl {{{ ax_arg_with_topic_heap_size
AC_DEFUN([AX_ARG_WITH_TOPIC_HEAP_SIZE],[
  AC_ARG_WITH([topic-heap-size],[AC_HELP_STRING([--topic-heap-size=<value>],[Set topic heap size (default 256).])],[topic_heap_size="$withval"],[topic_heap_size="256"])
  AC_DEFINE_UNQUOTED([TOPIC_HEAP_SIZE],[$topic_heap_size],[Size of the topic heap.])
])dnl }}}
dnl {{{ ax_arg_with_ircd_heap_size
AC_DEFUN([AX_ARG_WITH_IRCD_HEAP_SIZE],[
  AC_ARG_WITH([ircd-heap-size],[AC_HELP_STRING([--ircd-heap-size=<value>],[Set ircd heap size (default 8).])],[ircd_heap_size="$withval"],[ircd_heap_size="8"])
  AC_DEFINE_UNQUOTED([IRCD_HEAP_SIZE],[$ircd_heap_size],[Size of the ircd heap.])
])dnl }}}
dnl {{{ ax_arg_with_mqueue_heap_size
AC_DEFUN([AX_ARG_WITH_MQUEUE_HEAP_SIZE],[
  AC_ARG_WITH([mqueue-heap-size],[AC_HELP_STRING([--mqueue-size=<value>],[Set mqueue heap size (default 256).])],[mqueue_heap_size="$withval"],[mqueue_heap_size="256"])
  AC_DEFINE_UNQUOTED([MQUEUE_HEAP_SIZE],[$mqueue_heap_size],[Size of the floodserv mqueue heap.])
])dnl }}}
dnl {{{ ax_arg_with_fmsg_heap_size
AC_DEFUN([AX_ARG_WITH_FMSG_HEAP_SIZE],[
  AC_ARG_WITH([fmsg-heap-size],[AC_HELP_STRING([--fmsg-size=<value>],[Set fmsg heap size (default 256).])],[fmsg_heap_size="$withval"],[fmsg_heap_size="256"])
  AC_DEFINE_UNQUOTED([FMSG_HEAP_SIZE],[$fmsg_heap_size],[Size of the floodserv fmsg heap.])
])dnl }}}
dnl {{{ ax_Arg_with_services_name
AC_DEFUN([AX_ARG_WITH_SERVICS_NAME],[
	AC_ARG_WITH([services-name],[AC_HELP_STRING([--with-services-name=SERVICES_NAME],[Set the name of your services server])],[services_name="$withval"],[services_name="services.oftc.net"])
	AC_DEFINE_UNQUOTED(SERVICES_NAME,"$services_name",[Name of the services
	server.])
]) dnl }}}
dnl {{{ ax_arg_enable_efnet
AC_DEFUN([AX_ARG_ENABLE_EFNET],[
  AC_ARG_ENABLE([efnet],[AC_HELP_STRING([--enable-efnet],[For IRCDs running on EFnet.])],[efnet="$enableval"],[efnet="no"])
  if test "$efnet" = "yes" ; then
		use_efnet="yes"
    AC_DEFINE([EFNET],[1],[Define to 1 if this server will be an EFnet server.])
		AC_DEFINE([TS5_ONLY],[1],[If Defined to 1 server links to your network must have a minimum of TS5.])
	else
		AC_DEFINE([INVARIANTS],[1],[Miscellaneous sanity checks for the IRCd. Makes it slightly slower])
		use_efnet="no"
  fi
  AM_CONDITIONAL([EFNET],[test "$use_efnet" = "yes"])
])dnl }}}
dnl {{{ ax_arg_enable_halfops
AC_DEFUN([AX_ARG_ENABLE_HALFOPS],[
  AC_ARG_ENABLE([halfops],[AC_HELP_STRING([--enable-halfops],[Enable halfops support.])],[halfops="$enableval"],[halfops="no"])
  if test "$halfops" = "yes" ; then
    AC_DEFINE([HALFOPS],[1],[Define to 1 if you want halfops support.])
  fi
])dnl }}}
dnl {{{ ax_arg_enable_debugging
AC_DEFUN([AX_ARG_ENABLE_DEBUGGING],[
  AC_ARG_ENABLE([debugging],[AC_HELP_STRING([--enable-debugging],[Enable debugging.])],[debugging="$enableval"],[debugging="no"])
  if test "$debugging" = "yes" ; then
    AC_DEFINE([DEBUG],[1],[Define to 1 to enable debugging.])
    CFLAGS="$CFLAGS -Wall -g -O0"
  else
    AC_DEFINE([NDEBUG],[1],[Define to 1 to disable debugging.])
  fi
])dnl }}}
dnl {{{ ax_arg_enable_warnings
AC_DEFUN([AX_ARG_ENABLE_WARNINGS],[
  AC_ARG_ENABLE([warnings],[AC_HELP_STRING([--enable-warnings],[Enable compiler warnings.])],[warnings="$enableval"],[warnings="no"])
  if test "$warnings" = "yes" ; then
    CFLAGS="-Wcast-qual -Wmissing-declarations -Wmissing-prototypes -Wnested-externs -Wredundant-decls -Wshadow -Wwrite-strings -Wno-unused"
  fi
])dnl }}}
dnl {{{ ax_arg_enable_efence
AC_DEFUN([AX_ARG_ENABLE_EFENCE],[
  AC_ARG_ENABLE([efence],[AC_HELP_STRING([--enable-efence],[Enable compilation with ElectricFence.])],[efence="$enableval"],[efence="no"])
  if test "$efence" = "yes" ; then
    AC_SEARCH_LIBS([malloc],[efence],,[AC_MSG_ERROR([efence library not found])])
  fi
])dnl }}}
dnl {{{ ax_arg_enable_syslog
AC_DEFUN([AX_ARG_ENABLE_SYSLOG],[
  AC_CHECK_HEADERS([syslog.h sys/syslog.h])
  AC_ARG_ENABLE([syslog],[AC_HELP_STRING([--enable-syslog="EVENTS"],[Enable syslog for events: users oper (space separated in quotes; default: disabled).])],[syslog="$enableval"],[syslog="no"])
  if test "$enableval" != "no" ; then
    for option in $enableval ; do
      case "$option" in
        users) AC_DEFINE([SYSLOG_USERS],[1],[Send user log stuff to syslog.]) ;;
        oper) AC_DEFINE([SYSLOG_OPER],[1],[Send oper log stuff to syslog.]) ;;
        yes) : ;;
        *) AC_MSG_ERROR([invalid value for --enable-syslog: $option]) ;;
      esac
    done
    AC_DEFINE([USE_SYSLOG],[1],[Define to 1 if you want to use syslog.])
  fi
])dnl }}}
dnl {{{ ax_arg_with_syslog_facility
AC_DEFUN([AX_ARG_WITH_SYSLOG],[
  AC_ARG_WITH([syslog-facility],[AC_HELP_STRING([--with-syslog-facility=LOG],[Define the syslog facility to use (default: LOG_LOCAL4)])],[syslog_facility="$withval"],[syslog_facility="LOG_LOCAL4"])
  AC_DEFINE_UNQUOTED([LOG_FACILITY],[$syslog_facility],[Set to syslog facility to use.])
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
