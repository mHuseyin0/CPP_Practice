#!/bin/bash

function compileCode() {
  fastOut=$(fastfetch)

  if [[ $fastOut == *"Android"* ]]; then
    os="Android"
  else
    os="Linux"
  fi

  echo "Compiling for $os."
  g++ *.cpp -Wall -O -ansi -o "$os" &&
    if [[ $os == "Android" ]]; then
      echo "Valgrind will not be executed since you are on android. Finishing."
      return 0
    fi

  echo "Valgrind is running. Please wait."
  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-origins=yes --log-file=valgrind-out.txt ./$os

  echo "Valgrind output saved in valgrind-out.txt. Finishing."
  return 0
}
compileCode
