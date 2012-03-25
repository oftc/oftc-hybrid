MAINTAINERCLEANFILES=Makefile.in
sbin_PROGRAMS=ircd
ircd_SOURCES=balloc.c channel.c channel_mode.c client.c csvlib.c dbuf.c event.c fdlist.c fileio.c getopt.c hash.c hook.c hostmask.c irc_res.c irc_reslib.c irc_string.c ircd.c ircd_signal.c list.c listener.c match.c memory.c modules.c motd.c numeric.c packet.c parse.c conf.c s_bsd_epoll.c s_bsd_poll.c s_bsd_sigio.c s_bsd_devpoll.c s_bsd_kqueue.c s_bsd_select.c restart.c resv.c rsa.c s_auth.c s_bsd.c s_gline.c log.c s_misc.c s_serv.c s_user.c send.c sprintf_irc.c version.c whowas.c conf_parser.y conf_lexer.l messages.tab watch.c

ircd_LDFLAGS=-export-dynamic $(OPENSSL_LDFLAGS)
AM_CPPFLAGS=$(LTDLINCL) -I$(top_srcdir)/include $(OPENSSL_INCLUDES)

if USE_SHARED_MODULES
ircd_LDADD=$(LIBLTDL)
ircd_DEPENDENCIES=$(LTDLDEPS)
else
ircd_LDADD=$(top_srcdir)/modules/libmodules.la
endif
ircd_LDADD+=$(OPENSSL_LIBS)
AM_YFLAGS=-d
