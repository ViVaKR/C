#!/bin/sh

if [[ $# -eq 1 ]] ; then
    kill $1
    ./run.sh
fi

