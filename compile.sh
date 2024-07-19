#!/bin/bash

if [[ neofetch == *"Android"* ]]; then
    os="Android"
else
    os="Linux"
fi

g++ main.cpp DVDStoreManagementSystem.cpp -Wall -O2 -ansi -o "$os" &&
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-origins=yes --log-file=valgrind-out.txt ./$os
