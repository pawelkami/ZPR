#!/bin/bash

g++ Game.cpp GameList.cpp test.cpp -o test -std=c++14 -fPIC -Wall -pedantic -pthread -fprofile-arcs -ftest-coverage -lgcov
./test --log_level=test_suite > testresult.txt
gcov Game.cpp > coverGame.txt
gcov GameList.cpp > coverGameList.txt
