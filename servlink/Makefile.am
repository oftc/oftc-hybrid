MAINTAINERCLEANFILES=Makefile.in

AM_CPPFLAGS=$(OPENSSL_INCLUDES) -I$(top_srcdir)/include

bin_PROGRAMS=servlink

servlink_LDFLAGS=-export-dynamic $(OPENSSL_LDFLAGS)
servlink_LDADD=$(OPENSSL_LIBS)

servlink_SOURCES=servlink.c io.c control.c

noinst_HEADERS=servlink.h io.h control.h
