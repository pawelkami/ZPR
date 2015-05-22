all: start

start: main
	g++ -Wall -std=c++11 main.o -L .. -lcppGame -Wl,-rpath=.. -o start
main: main.cpp
	g++ -Wall -c -std=c++11 main.cpp -o main.o

clean:
	rm *~ *.o start
