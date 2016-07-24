MAINTAINERCLEANFILES=Makefile.in
SUBDIRS=opers users
ohelpdir=$(datadir)/@PACKAGE@/help/opers
uhelpdir=$(datadir)/@PACKAGE@/help/users

SYMLINKS=topic accept cmode admin names links away whowas \
	version kick who invite quit join list nick oper part \
	time motd userhost users whois ison lusers user help \
	challenge map pass error knock ping pong

install-exec-hook:
	@for link in $(SYMLINKS); do \
		rm -f $(uhelpdir)/$$link; \
		ln -s $(ohelpdir)/$$link $(uhelpdir); \
	done