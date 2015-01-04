#! /bin/bash 

set -eu

# Should be run from inside the ./build directory.
gcc -Wall -c ../func.c
gcc -shared -Wl,-soname,libfunc.so -o libfunc.so func.o

