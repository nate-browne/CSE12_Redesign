# Makefile for use with this project
CXXFLAGS=
LDFLAGS=
LINKFLAGS=-std=c++11 -Wall -pedantic -Wextra

ifeq ($(type),opt)
	CXXFLAGS=-O3 -Wall -Wextra -pedantic -std=c++11 -c
	LDFLAGS=
else
	CXXFLAGS=-Wall -Wextra -pedantic -std=c++11 -c
	LDFLAGS=-g
endif

all: driver

driver: driver.o
	g++ $(LINKFLAGS) -o driver $(LDFLAGS) src/driver.o
	mv driver bin/

driver.o: src/driver.cpp  src/RST.hpp
	g++ $(CXXFLAGS) $(LDFLAGS) src/driver.cpp
	mv driver.o src/

valgrind_driver: driver
	valgrind --leak-check=full --read-var-info=yes --show-reachable=yes \
	bin/driver $(DEBUG)

clean:
	rm -f src/*.o bin/* src/*.dSYM

new:
	make clean
	make all
