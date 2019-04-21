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

all: driver int_driver

driver: driver.o
	g++ $(LINKFLAGS) -o driver $(LDFLAGS) src/driver.o
	mv driver bin/

driver.o: src/driver.cpp src/avl_tree.cpp src/avl_tree.h src/driver.h
	g++ $(CXXFLAGS) $(LDFLAGS) src/driver.cpp
	mv driver.o src/

int_driver: int_driver.o
	g++ $(LINKFLAGS) -o intdriver $(LDFLAGS) src/int_driver.o
	mv intdriver bin/

int_driver.o: src/int_driver.cpp src/avl_tree.cpp src/avl_tree.h
	g++ $(CXXFLAGS) $(LDFLAGS) src/int_driver.cpp
	mv int_driver.o src/

valgrind_driver: driver
	valgrind --leak-check=full --read-var-info=yes \
		--show-reachable=yes bin/driver $(DEBUG)

valgrind_intdriver: int_driver
	valgrind --leak-check=full --read-var-info=yes \
		--show-reachable=yes bin/intdriver $(DEBUG)

clean:
	rm -f src/*.o bin/* src/*.dSYM

new:
	make clean
	make all
