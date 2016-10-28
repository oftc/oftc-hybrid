MAINTAINERCLEANFILES=Makefile.in
SUBDIRS=opers users
ohelpdir=$(datadir)/@PACKAGE@/help/opers
uhelpdir=$(datadir)/@PACKAGE@/help/users

SYMLINKS=topic accept cmode admin names links away whowas \
	version kick who invite quit join list nick oper part \
	time motd userhost users whois ison lusers user help \
	challenge map pass error knock ping pong

install-exec-hook:
	chmod u+w $(uhelpdir) # work around write-protected directory in "make distcheck"
	@set -e; for link in $(SYMLINKS); do \
		rm -f $(uhelpdir)/$$link; \
		ln -s $(ohelpdir)/$$link $(uhelpdir); \
	done
