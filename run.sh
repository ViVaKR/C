#!/bin/bash

$(which clang) -o main main.c
"./main" $1
