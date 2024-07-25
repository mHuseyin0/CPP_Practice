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

    current=$(date)
    sed -i "1s/^/$(date) \n/" valgrind-out.txt

    cat valgrind-out.txt
    ./$os >cpp-out.txt

    printDash
    echo "Valgrind output saved in valgrind-out.txt."
    echo "C++ output saved in cpp-out.txt."
    echo "Finishing."
    return 0
}

compileCode
