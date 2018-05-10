#!/usr/bin/env bash
make clean;make; while Build/repro; do touch reprolib/reprolib.hpp;make;done