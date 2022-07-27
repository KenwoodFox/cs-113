#!/bin/bash

# Written by Joe
# If you do not have bash (or zsh or, something)
# You can invoke cmake as ususal per your system
# See the readme at the root of this repo.

cmake . -B_build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

projName=$(pwd | awk -F / '{print $NF}') # Get project name

if [[ $* == *--test* ]]
then
    cd _build && make
    python ../test.py | sed 's/\x1B\[[0-9;]\{1,\}[A-Za-z]//g' &> results.txt # Pipe the test results to a file (Also strips the color codes with sed)

    # Build the docs
    cp ../*.tex .
	cp ../*.sty .
	find . -name '*.tex' -exec latexmk --shell-escape -pdf {} \;

    # Stage and zip
    mkdir -p bin
    cp *_binary bin/

    tar -zcvf $projName.tar.gz bin/ Writeup.pdf
else
    cd _build && make && ./*_binary # Expects make
fi

