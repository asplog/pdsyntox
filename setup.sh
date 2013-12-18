#!/usr/bin/env bash
SYNTOX=$1
pushd ${SYNTOX}
./configure
make clean
make
popd
./genmake.sh ${SYNTOX} > ./Makefile
