#!/bin/bash

SOURCE=$PWD
BUILD=$PWD/build
mkdir -p $BUILD && cd $BUILD

export LANG=C
# in embedded export TARGET=
export TARGET="arm-kos"
export PKG_CONFIG=""
export SDK_PREFIX="/opt/KasperskyOS-Community-Edition-1.0.1.4"
#BUILD_SIM_TARGET=y # but in embedded it's uncomment
export PATH="$SDK_PREFIX/toolchain/bin:$PATH"

BUILD_HOST=$BUILD/host
mkdir -p host 

cd $BUILD && cmake -G "Unix Makefiles" \
      -DFORTE_ARCHITECTURE=kos -DFORTE_COM_ETH=OFF -DFORTE_COM_FBDK=OFF -DFORTE_COM_LOCAL=OFF -DFORTE_TESTS=OFF -DFORTE_TESTS_INC_DIRS=${forte_boost_test_inc_dirs} -DFORTE_TESTS_LINK_DIRS=${forte_boost_test_inc_dirs} -DFORTE_MODULE_CONVERT=ON -DFORTE_MODULE_IEC61131=ON -DFORTE_MODULE_UTILS=ON ../ \
      -D CMAKE_BUILD_TYPE:STRING=Debug \
      -D CMAKE_INSTALL_PREFIX:STRING=$BUILD/../install \
      -D CMAKE_TOOLCHAIN_FILE=$SDK_PREFIX/toolchain/share/toolchain-arm-kos.cmake ../

$SDK_PREFIX/common/prepare_hdd_img.sh -d $SOURCE/resources/files/ -img einit/hdd.img -f fat32 -s 128
# make sim
make kos-image
