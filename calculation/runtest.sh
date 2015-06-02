#!/bin/bash

scons 1>/dev/null
./test --log_level=test_suite >> testresult.txt
