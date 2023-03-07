all: main
main: main.cpp
	g++ -Wall -Wextra -o $@ $^