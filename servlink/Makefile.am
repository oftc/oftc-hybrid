MAINTAINERCLEANFILES=Makefile.in

AM_CPPFLAGS=$(OPENSSL_INCLUDES)o

bin_PROGRAMS=servlink

servlink_LDFLAGS=-export-dynamic $(OPENSSL_LDFLAGS)
servlink_LDADD=$(OPENSSL_LIBS)

servlink_SOURCES=servlink.c io.c control.c
