CXXFLAGS=
LDFLAGS=
LINKFLAGS=-std=c++11 -Wall -pedantic -Wextra
LEAKER=
MAX=

ifeq ($(type),opt)
 	CXXFLAGS=-O3 -Wall -pedantic -Wextra -std=c++11 -c
	LDFLAGS=
else
	CXXFLAGS=-Wall -pedantic -Wextra -std=c++11 -c
	LDFLAGS=-g
endif

ifeq ($(dir),max)
	MAX=
else
ifeq ($(dir),min)
	MAX=--min
endif
endif

UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
	DEBUGGER=gdb
	LEAKER=valgrind --leak-check=full --read-var-info=yes --show-reachable=yes
else
ifeq ($(UNAME),Darwin)
	DEBUGGER=lldb
	LEAKER=leaks -quiet -atExit --
endif
endif

new:
	make prog

debug: build
	$(DEBUGGER) bin/driver

memcheck: build
	$(LEAKER) bin/driver $(MAX)

prog: build 
	bin/driver $(MAX)

build: clean setup driver.o
	g++ $(LINKFLAGS) -o driver $(LDFLAGS) bin/driver.o
	mv driver bin/

driver.o: src/driver.cpp src/priority_queue.hpp src/heap.hpp
	g++ $(CXXFLAGS) $(LDFLAGS) src/driver.cpp
	mv *.o bin/

setup:
	mkdir bin

clean:
	rm -rf bin/
