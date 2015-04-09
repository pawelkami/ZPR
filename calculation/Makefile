all: start

start: main Game
	g++ -Wall -std=c++11 main.o Game.o -o start

main: main.cpp
	g++ -Wall -c -std=c++11 main.cpp -o main.o

Game: Game.cpp
	g++ -Wall -c -std=c++11 Game.cpp -o Game.o

clean:
	rm *~ *.o start
