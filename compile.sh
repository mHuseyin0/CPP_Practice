#!/bin/bash

function printDash() {
    echo "-------------------------------------------------------------------------"
}

function compileCode() {
    fastOut=$(fastfetch)

    if [[ $fastOut == *"Android"* ]]; then
        os="Android"
    else
        os="Linux"
    fi

    echo "Compiling for $os."

    g++ -std=c++17 *.cpp -Wall -O -o "$os" &&
        if [[ $os == "Android" ]]; then
            echo "Valgrind will not be executed since you are on android. Finishing."
            return 0
        fi

    echo "Valgrind is running. Please wait."
    printDash

    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-origins=yes --log-file=valgrind-out.txt ./$os
    printDash
    #cat valgrind-out.txt

    printDash
    echo "Valgrind output saved in valgrind-out.txt. Finishing."
    return 0
}

compileCode
