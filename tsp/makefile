CC = g++
CFLAGS = -g -Wall -std=c++11

all: tsp 

tsp: main.o City.o GA.o Population.o Tour.o TourManager.o
	$(CC) $(CFLAGS) -o tsp main.o City.o GA.o Population.o Tour.o TourManager.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

City.o: City.cpp
	$(CC) $(CFLAGS) -c City.cpp

GA.o: GA.cpp
	$(CC) $(CFLAGS) -c GA.cpp

Population.o: Population.cpp
	$(CC) $(CFLAGS) -c Population.cpp

Tour.o: Tour.cpp
	$(CC) $(CFLAGS) -c Tour.cpp

TourManager.o: TourManager.cpp
	$(CC) $(CFLAGS) -c TourManager.cpp

clean:
	$(RM) tsp *.o *~
