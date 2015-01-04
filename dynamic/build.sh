#! /bin/bash

set -eu

function compile_main {
  gcc -Wall ../main.c -o main -L. -lfunc
}

function compile_static {
  gcc -Wall -c ../func.c
  ar -cvq libfunc.a func.o
}

function compile_main_runtime {
 gcc -Wall ../main_runtime.c -o main -ldl -rdynamic
}

rm -rf build
mkdir build
cd build

#compile_static; compile_main

#../compile_dll.sh; compile_main
# LD_LIBRARY_PATH=. ./main

../compile_dll.sh; compile_main_runtime

./main
