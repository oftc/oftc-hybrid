# $Id$

all: respond

respond: respond.c
	gcc -g -O2 -Wall -o respond respond.c -lcrypto -ggdb

clean:
	rm -f respond *.core *~
