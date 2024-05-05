#! /usr/bin/env zsh

clang -g vivakr.c -o ./debug/vivakr && lldb ./debug/vivakr

