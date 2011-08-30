MAINTAINERCLEANFILES=Makefile.in
sbin_PROGRAMS=ircd
ircd_SOURCES=balloc.c channel.c channel_mode.c client.c config.c conf_general.c conf_serverinfo.c conf_admin.c conf_logging.c conf_channel.c conf_serverhide.c conf_modules.c csvlib.c dbuf.c dynlink.c event.c fdlist.c fileio.c getopt.c hash.c hook.c hostmask.c irc_string.c ircd.c ircd_signal.c levent.c list.c listener.c m_error.c match.c memory.c modules.c motd.c numeric.c packet.c parse.c s_conf.c restart.c resv.c rsa.c s_auth.c s_bsd.c s_log.c s_misc.c s_serv.c s_user.c send.c sprintf_irc.c tools.c version.c watch.c whowas.c ircd_parser.y ircd_lexer.l
if HAVE_CRYPT
ircd_SOURCES+=crypt.c
endif
ircd_LDFLAGS=@LIBLTDL@ -export-dynamic
ircd_CFLAGS=-I$(top_srcdir)/include -I$(top_srcdir)/lib/pcre -I$(top_srcdir)/libevent/include -I$(top_srcdir)/json-c
INCLUDES=@INCLTDL@
if USE_SHARED_MODULES
ircd_LDADD=
else
ircd_LDADD=$(top_srcdir)/modules/libmodules.la
endif
ircd_LDADD+=$(top_srcdir)/lib/pcre/libpcre.a $(top_srcdir)/libevent/libevent.la $(top_srcdir)/json-c/libjson.la
AM_YFLAGS=-d
