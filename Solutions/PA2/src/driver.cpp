#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>

#include "vector.hpp"

void clrbuf(char c) {
  while(c != '\n') c = fgetc(stdin);
}

int main(void) {

  cse12_ds::vector<int> vec;

  while(true) {
    char command = '\0';
    std::cout << "Please enter a command: (e(m)pty, (s)ize, element (a)t, (f)ront, (b)ack," << 
    " (p)ush back, p(o)p back, (i)nsert, (e)rase, (c)lear): ";
    if((command = fgetc(stdin)) == EOF) {
      break;
    }
    clrbuf(command);

    switch(command) {
      case 'm':
        if(vec.empty()) {
          std::cout << "Vector is empty" << std::endl;
        } else {
          std::cout << "Vector is not empty" << std::endl;
        }
        break;
      case 's':
        std::cout << "Number of elements in vector is: " << vec.size();
        break;
    }
  }

  return EXIT_SUCCESS;
}