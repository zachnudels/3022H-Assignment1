all: driver databaseDriver.o
	./driver

databaseDriver.o: databaseDriver.cpp
	g++ -c databaseDriver.cpp -std=c++11

driver: databaseDriver.o
	g++  -o driver databaseDriver.o -std=c++11 -o driver
