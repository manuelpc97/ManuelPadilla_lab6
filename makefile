lab: user.o games.o main.o
	g++ user.o games.o main.o -o lab
main.o: main.cpp user.h games.h
	g++ -c main.cpp
user.o: user.cpp user.h
	g++ -c user.cpp
games.o: games.cpp games.h
	g++ -c games.cpp
