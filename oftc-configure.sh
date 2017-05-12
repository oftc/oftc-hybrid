#!/bin/sh

if [ -z "$*" ]; then
  set -- --prefix=/home/oftc/oftc/testnet-hybrid
fi

set -x

./configure \
  --enable-openssl \
  --disable-profile \
  --enable-assert \
  --enable-zlib \
  --with-nicklen=30 \
  --with-topiclen=390 \
  --disable-halfops \
  --enable-shared-modules \
  "$@"
