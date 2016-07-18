MAINTAINERCLEANFILES=Makefile.in
AM_CPPFLAGS=-I$(top_srcdir)/include -I$(top_srcdir)/lib/pcre $(OPENSSL_INCLUDES)
if USE_SHARED_MODULES
AM_LDFLAGS= -module
pkglib_LTLIBRARIES= m_die.la      \
                    m_join.la     \
                    m_kick.la     \
                    m_kill.la     \
                    m_message.la  \
                    m_mode.la     \
                    m_nick.la     \
                    m_part.la     \
                    m_quit.la     \
                    m_server.la   \
                    m_sjoin.la    \
                    m_squit.la    \
                    spy_admin_notice.la \
                    spy_info_notice.la \
                    spy_links_notice.la \
                    spy_motd_notice.la \
                    spy_stats_notice.la \
                    spy_stats_p_notice.la \
                    spy_trace_notice.la \
                    spy_whois_notice.la
else
AM_LDFLAGS=-static
noinst_LTLIBRARIES= m_die.la      \
                    m_join.la     \
                    m_kick.la     \
                    m_kill.la     \
                    m_message.la  \
                    m_mode.la     \
                    m_nick.la     \
                    m_part.la     \
                    m_quit.la     \
                    m_server.la   \
                    m_sjoin.la    \
                    m_squit.la \
                    spy_admin_notice.la \
                    spy_info_notice.la \
                    spy_links_notice.la \
                    spy_motd_notice.la \
                    spy_stats_notice.la \
                    spy_stats_p_notice.la \
                    spy_trace_notice.la \
                    spy_whois_notice.la
endif

install-exec-local:
	rm -f $(DESTDIR)/$(pkglibdir)/*.la $(DESTDIR)/$(pkblibdir)/*.a $(DESTDIR)/$(pkblibdir)/*.so 
