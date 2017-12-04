#!/bin/bash

cd openssl-1.0.2m/

source ../env.txt
export MAKE_INSTALL_DIR=$(pwd)/openssl
export PATH=$CROSS_COMPILE_PATH:$PATH
export TARGETMACH=$CROSS_ARCH
export BUILDMACH=i686-pc-linux-gnu
export CROSS=$CROSS_ARCH
export CC=${CROSS}-gcc
export LD=${CROSS}-ld		
export AS=${CROSS}-as
export AR=${CROSS}-ar

./Configure linux-generic32 shared -DOPENSSL_NO_HEARTBEATS -DL_ENDIAN --prefix=${MAKE_INSTALL_DIR} --openssldir=${MAKE_INSTALL_DIR}
make
make install

cd ..
