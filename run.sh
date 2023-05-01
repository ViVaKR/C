#!/bin/bash

clear

read -p "Press [Enter] key to start"
$(which gcc-13) -o main main.c
/Users/vivabm/GitProjects/C/main $1
# kill %-1
