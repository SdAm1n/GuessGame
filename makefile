Guess Game: main.o utils.o
	g++ main.o utils.o -o 'Guess Game'

main.o: main.cpp
	g++ -c main.cpp

utils.o: utils.cpp
	g++ -c utils.cpp

clean:
	rm *.o 'Guess Game'