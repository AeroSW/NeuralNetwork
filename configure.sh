#!/bin/sh

make clean
make
clear
export LD_LIBRARY_PATH=./lib:LD_LIBRARY_PATH
