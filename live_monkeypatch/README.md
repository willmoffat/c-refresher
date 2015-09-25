# Monkey-patching a server written in C

```
./build.sh
build/main
```

Edit `swappable.c` and re-run `./build.sh`
Observe that `main` reads in the new library and calls the first function immediately!

## What's the point?

Slow compliations kills me. Especially when working on embedded systems when you have to reflash and reboot every time you change a printf.

## Limitations?

Probably a lot, So far I know:

* You can't call a library function that wasn't already compiled into your main. (Because the PLA needs to be upated). 