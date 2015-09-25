#! /bin/sh

set -eu

mkdir -p build || true
cd build

# TODO(wdm) Investigate -fpic.

gcc -g -Wall -c ../swappable.c

# swappable is included at a fixed location in the linkerscript.
gcc -T ../linkerscript -g -Wall ../main.c -o main

objdump -s -d main > main.objdump.txt

# TODO(wdm) Can we upate the plt?
#           --only-section=.got   --only-section=.got.plt
# TODO(wdm) Warn if plt has changed.
objcopy --only-section=.swappable -O binary main swappable.bin
# hexdump swappable.bin

echo "Now run"
echo "  ./build/main"
echo "And then make changes to swappable.c and recompile"
