#! /usr/bin/env zsh

as hello.asm -o hello.o && ld hello.o -o hello -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _start -arch arm64 && ./hello
