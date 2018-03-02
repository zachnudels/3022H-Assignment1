all: driver databaseDriver.o
	./driver

databaseDriver.o: databaseDriver.cpp students.o
	g++ -c databaseDriver.cpp -std=c++11

students.o: students.cpp
	g++ -c students.cpp -std=c++11

driver: databaseDriver.o
	g++  -o driver databaseDriver.o students.o -std=c++11 -o driver
