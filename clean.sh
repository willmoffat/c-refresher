#! /bin/bash

set -eu 

find . -name "main" -or -name "*.a" -or -name "*~" -or -name "*.out" -or -name "*.o" -or -name "*.s" -or -name "*.lst" | xargs rm -f
