#!/bin/sh
# Run this to generate all the initial makefiles, etc.
# Shamelessly stolen from lighttpd - which is licensed under the GPL

LIBTOOLIZE_FLAGS="--automake --ltdl --copy --force"
AUTOMAKE_FLAGS="--add-missing"
ACLOCAL_FLAGS="-I m4 --install"

ARGV0=$0

run() {
	echo "$ARGV0: running \`$@'"
	"$@"
}

## jump out if one of the programs returns 'false'
set -e

## on macosx glibtoolize, others have libtool
if test x$LIBTOOLIZE = x; then
  if test \! x`which glibtoolize` = x; then
    LIBTOOLIZE=glibtoolize
  elif test \! x`which libtoolize-1.5` = x; then
    LIBTOOLIZE=libtoolize-1.5
  elif test \! x`which libtoolize` = x; then
    LIBTOOLIZE=libtoolize
  fi
fi

if test x$ACLOCAL = x; then
  if test \! x`which aclocal-1.14` = x; then
    ACLOCAL=aclocal-1.14
    AUTOMAKE=automake-1.14
  elif test \! x`which aclocal` = x; then
    ACLOCAL=aclocal
    AUTOMAKE=automake
  fi
fi

if test x$AUTOMAKE = x; then
  if test \! x`which automake-1.14` = x; then
    AUTOMAKE=automake-1.14
  elif test \! x`which automake` = x; then
    AUTOMAKE=automake
  fi
fi


## macosx has autoconf-2.59 and autoconf-2.60
if test x$AUTOCONF = x; then
  if test \! x`which autoconf-2.59` = x; then
    AUTOCONF=autoconf-2.59
  elif test \! x`which autoconf` = x; then
    AUTOCONF=autoconf
  fi
fi

if test x$AUTOHEADER = x; then
  if test \! x`which autoheader-2.59` = x; then
    AUTOHEADER=autoheader-2.59
  elif test \! x`which autoheader` = x; then
    AUTOHEADER=autoheader
  fi
fi


run $LIBTOOLIZE $LIBTOOLIZE_FLAGS
run $ACLOCAL $ACLOCAL_FLAGS
run $AUTOHEADER
run $AUTOMAKE $AUTOMAKE_FLAGS
run $AUTOCONF

# update include/serno.h
if [ -d .git ]; then
	REVISION=$(git describe --tags)
	echo "#define SERIALNUM \"$REVISION\"" > include/serno.h.new
	if ! diff include/serno.h.new include/serno.h > /dev/null; then
		mv include/serno.h.new include/serno.h
	fi
	rm -f include/serno.h.new
fi

run ./oftc-configure.sh "$@"
