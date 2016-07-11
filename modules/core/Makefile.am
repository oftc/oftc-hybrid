MAINTAINERCLEANFILES=Makefile.in
AM_CPPFLAGS=-I$(top_srcdir)/include -I$(top_srcdir)/lib/pcre
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
                    m_squit.la
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
                    m_squit.la
endif

install-exec-local:
	rm -f $(DESTDIR)/$(pkglibdir)/*.la $(DESTDIR)/$(pkblibdir)/*.a $(DESTDIR)/$(pkblibdir)/*.so 
