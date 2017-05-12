MAINTAINERCLEANFILES=Makefile.in
SUBDIRS=core
AM_CPPFLAGS=-I$(top_srcdir)/lib/pcre -I$(top_srcdir)/include $(OPENSSL_INCLUDES)

moduledir=$(pkglibdir)/autoload

if USE_SHARED_MODULES
AM_LDFLAGS= -module
module_LTLIBRARIES= m_accept.la       \
                    m_admin.la        \
                    m_away.la         \
                    m_capab.la        \
                    m_cap.la          \
                    m_capture.la      \
                    m_cburst.la       \
                    m_certfp.la       \
                    m_challenge.la    \
                    m_close.la        \
                    m_connect.la      \
                    m_cryptlink.la    \
                    m_drop.la         \
                    m_encap.la        \
                    m_eob.la          \
                    m_etrace.la       \
                    m_gline.la        \
                    m_gnotice.la      \
                    m_hash.la         \
                    m_help.la         \
                    m_info.la         \
                    m_invite.la       \
                    m_ison.la         \
                    m_kline.la        \
                    m_knock.la        \
                    m_links.la        \
                    m_list.la         \
                    m_lljoin.la       \
                    m_llnick.la       \
                    m_locops.la       \
                    m_log.la          \
                    m_lusers.la       \
                    m_map.la          \
                    m_motd.la         \
                    m_names.la        \
                    m_nburst.la       \
                    m_omotd.la        \
                    m_oper.la         \
                    m_operwall.la     \
                    m_pass.la         \
                    m_ping.la         \
                    m_pong.la         \
                    m_post.la         \
                    m_realhost.la     \
                    m_rehash.la       \
                    m_restart.la      \
                    m_resv.la         \
                    m_rkline.la       \
                    m_rxline.la       \
                    m_set.la          \
                    m_shedding.la     \
                    m_stats.la        \
                    m_services.la     \
                    m_svinfo.la       \
                    m_svscloak.la     \
                    m_svsjoin.la      \
                    m_svsmode.la      \
                    m_tburst.la       \
                    m_testline.la     \
                    m_testmask.la     \
                    m_time.la         \
                    m_topic.la        \
                    m_trace.la        \
                    m_user.la         \
                    m_userhost.la     \
                    m_users.la        \
                    m_version.la      \
                    m_wallops.la      \
                    m_who.la          \
                    m_whois.la        \
                    m_whowas.la       \
                    m_xline.la        \
                    m_webirc.la       \
                    #soft_reboot.la
else
AM_LDFLAGS=-static
noinst_LTLIBRARIES= m_accept.la       \
                    m_admin.la        \
                    m_away.la         \
                    m_capab.la        \
                    m_cap.la          \
                    m_capture.la      \
                    m_cburst.la       \
                    m_certfp.la       \
                    m_challenge.la    \
                    m_close.la        \
                    m_connect.la      \
                    m_cryptlink.la    \
                    m_drop.la         \
                    m_encap.la        \
                    m_eob.la          \
                    m_etrace.la       \
                    m_gline.la        \
                    m_gnotice.la      \
                    m_hash.la         \
                    m_help.la         \
                    m_info.la         \
                    m_invite.la       \
                    m_ison.la         \
                    m_kline.la        \
                    m_knock.la        \
                    m_links.la        \
                    m_list.la         \
                    m_lljoin.la       \
                    m_llnick.la       \
                    m_locops.la       \
                    m_log.la          \
                    m_lusers.la       \
                    m_map.la          \
                    m_motd.la         \
                    m_names.la        \
                    m_nburst.la       \
                    m_omotd.la        \
                    m_oper.la         \
                    m_operwall.la     \
                    m_pass.la         \
                    m_ping.la         \
                    m_pong.la         \
                    m_post.la         \
                    m_realhost.la     \
                    m_rehash.la       \
                    m_restart.la      \
                    m_resv.la         \
                    m_rkline.la       \
                    m_rxline.la       \
                    m_set.la          \
                    m_shedding.la     \
                    m_stats.la        \
                    m_services.la     \
                    m_svinfo.la       \
                    m_svscloak.la     \
                    m_svsmode.la      \
                    m_tburst.la       \
                    m_testline.la     \
                    m_testmask.la     \
                    m_time.la         \
                    m_topic.la        \
                    m_trace.la        \
                    m_user.la         \
                    m_userhost.la     \
                    m_users.la        \
                    m_version.la      \
                    m_wallops.la      \
                    m_who.la          \
                    m_whois.la        \
                    m_whowas.la       \
                    m_xline.la        \
                    m_webirc.la       \
                    #soft_reboot.la

endif

AM_LDFLAGS+=$(OPENSSL_LDFLAGS)

install-exec-local:
	rm -f $(DESTDIR)/$(moduledir)/*.la $(DESTDIR)/$(moduledir)/*.a $(DESTDIR)/$(moduledir)/*.so
