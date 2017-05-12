MAINTAINERCLEANFILES=aclocal.m4 config.h.in config.h.in~ config.guess config.log config.status config.sub configure install-sh missing mkinstalldirs Makefile.in depcomp compile ltmain.sh COPYING
SUBDIRS=libltdl doc etc help include lib messages modules servlink src 
ACLOCAL_AMFLAGS=-I m4
EXTRA_DIST = autogen.sh oftc-configure.sh

maintainer-clean-local:
	rm -f ${PACKAGE}-${VERSION}.tar.gz
	rm -rf libltdl

install-data-local:
	$(INSTALL) -d $(DESTDIR)${localstatedir}/log
	$(INSTALL) -d $(DESTDIR)${localstatedir}/run
