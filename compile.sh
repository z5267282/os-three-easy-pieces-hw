#!/usr/bin/env bash

[ -d build ] && rm -r build;
mkdir build
for hw in [0-9][0-9]-*; do mkdir "./build/${hw}"; done

gcc "${1}" -o "./build/${1%.c}"
