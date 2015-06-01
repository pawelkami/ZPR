#!/bin/bash

scons
./test --log_level=test_suite >> testresult.txt
