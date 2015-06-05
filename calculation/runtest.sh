#!/bin/bash

echo "Compiling"
scons 1>/dev/null && echo "Running tests"
./test --log_level=test_suite > testresult.txt
