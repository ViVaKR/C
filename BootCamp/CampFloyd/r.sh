#! /usr/bin/env zsh

clang -std=c17 -g Entry.c -o ./build/Floyd && ./build/Floyd
