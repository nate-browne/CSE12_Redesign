CXXFLAGS=
LDFLAGS=
LINKFLAGS=-std=c++11 -Wall -pedantic -Wextra

ifeq ($(type),opt)
 	CXXFLAGS=-O3 -Wall -pedantic -Wextra -std=c++11 -c
	LDFLAGS=
else
	CXXFLAGS=-Wall -pedantic -Wextra -std=c++11 -c
	LDFLAGS=-g
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
	@make clean
	@make prog

debug: build
	$(DEBUGGER) bin/driver

memcheck: build
	$(LEAKER) bin/driver $(MAX)

prog: build
	@bin/driver

build: setup driver.o
	@g++ $(LINKFLAGS) -o driver $(LDFLAGS) bin/driver.o
	@echo "Compilation finished! Moving program to `bin`..."
	@mv driver bin/

driver.o: src/driver.cpp src/list.hpp src/utils.hpp
	@g++ $(CXXFLAGS) $(LDFLAGS) src/driver.cpp
	@mv *.o bin/

setup:
	@mkdir bin

clean:
	@echo "Cleaning up..."
	@rm -rf bin/
	@echo "Clean."

