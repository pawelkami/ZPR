all: start

start: main gra
	g++ -Wall -std=c++11 main.o gra.o -o start

main: main.cpp
	g++ -Wall -c -std=c++11 main.cpp -o main.o

gra: gra.cpp
	g++ -Wall -c -std=c++11 gra.cpp -o gra.o

clean:
	rm *~ *.o start
