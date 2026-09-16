#!/usr/bin/env bash

# usage: ./compile.sh ??-${dir}/${file}.cpp

[ -d build ] || mkdir build

dir="$(dirname "${1}")"
file="$(basename "${1}")"

gcc "${1}" -o "./build/${dir}-${file%.c}"
