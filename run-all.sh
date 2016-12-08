#!/bin/bash
make
echo "RUNNING: g++ O2"
./main-o2-gpp

echo "RUNNING: g++ O3"
./main-o3-gpp

echo "RUNNING: g++ Ofast"
./main-ofast-clang

echo "RUNNING: clang++ O2"
./main-o2-clang

echo "RUNNING: clang++ O3"
./main-o3-clang

echo "RUNNING: clang++ Ofast"
./main-ofast-clang
