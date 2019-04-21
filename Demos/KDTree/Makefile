# A simple makefile for CSE 100 P1

# === Directories ===
SRC=src
TEST=test
BUILD=build
OBJ=$(BUILD)/obj


# === Compiler options ===
# use g++ for everything
CC=g++

# MMD: automatically resolve included files
# g: include debugging symbols in the generated object file
# Wall: enable all warnings
# std: language standard to compile for
CXXFLAGS=-MMD -g -Wall -std=c++11

# g: include debugging symbols in the generated executable
LDFLAGS=-g


# === Build targets ===
default: init main main2

main: init src_object.main
	$(call make_executable_from_object_file,main,$(SRC)/main.o)
main2: init src_object.main2
	$(call make_executable_from_object_file,main2,$(SRC)/main2.o)
clean:
	rm -rf $(BUILD)

init:
	mkdir -p $(BUILD)/$(TEST)
	mkdir -p $(OBJ)/$(SRC)
	mkdir -p $(OBJ)/$(TEST)

src_object.%:
	# if build target is src_object.xyz then $@ == src_object.xyz, we want to extract filename xyz.
	$(call make_object_file_from_cpp_file,$(SRC)/$(call get_filename_from_object_target,$@))

test_object.%:
	$(call make_object_file_from_cpp_file,$(TEST)/$(call get_filename_from_object_target,$@))

# === Utility functions ===
make_object_file_from_cpp_file=$(CC) $(CXXFLAGS) -c $1.cpp -o $(OBJ)/$1.o
make_executable_from_object_file=$(shell $(CC) $(LDFLAGS) -o $(BUILD)/$1 $(OBJ)/$2)
get_filename_from_object_target=$(shell echo $1 | cut -d'.' -f2)
