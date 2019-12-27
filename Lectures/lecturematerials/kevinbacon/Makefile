CXXFLAGS=-O3 -Wall -pedantic -Wextra -std=c++11 -c
LINKFLAGS=-std=c++11 -Wall -pedantic -Wextra
INCLUDEFLAG=-I/usr/local/Cellar/boost/1.71.0/include/boost

prog: build
	bin/baconexample

build: clean setup baconexample.o
	g++ $(LINKFLAGS) $(INCLUDEFLAG) -o baconexample bin/baconexample.o
	mv baconexample bin/

baconexample.o: src/baconexample.cpp
	g++ $(CXXFLAGS) $(INCLUDEFLAG) src/baconexample.cpp
	mv *.o bin/

setup:
	mkdir bin

clean:
	rm -rf bin/
