#!/bin/bash

# Written by Joe
# If you do not have bash (or zsh or, something)
# You can invoke cmake as ususal per your system
# See the readme at the root of this repo.

cmake . -B_build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

if [[ $* == *--test* ]]
then
    cd _build && make
    python ../test.py
else
    cd _build && make && ./$PROJ_NAME\_binary # Expects make
fi
