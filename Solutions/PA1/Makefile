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


new:
	make clean
	make test

test: setup check.o
	g++ $(LINKFLAGS) -o test_runner $(LDFLAGS) bin/check.o bin/pa1.o
	mv test_runner bin/
	bin/test_runner

setup:
	mkdir bin

check.o: src/pa1.cpp src/pa1.hpp src/util.hpp test/check.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) src/pa1.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) test/check.cpp
	mv *.o bin/

clean:
	rm -rf bin/