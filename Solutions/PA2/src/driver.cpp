#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>
#include <exception>

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
      case 'm': {
        if(vec.empty()) {
          std::cout << "Vector is empty" << std::endl;
        } else {
          std::cout << "Vector is not empty" << std::endl;
        }
        break;
      }
      case 's': {
        std::cout << "Number of elements in vector is: " << vec.size() << std::endl;
        break;
      }
      case 'a': {
        unsigned int pos;
        std::cout << "Enter a position: ";
        std::cin >> pos;
        clrbuf(command);
        try {
          std::cout << "Element at position " << pos << " is " << vec.at(pos) << std::endl;
        } catch(std::out_of_range) {
          std::cerr << "Attempted to access element out of bounds!" << std::endl;
        }
        break;
      }
      case 'f': {
        if(vec.empty())
          std::cout << "No element at front" << std::endl;
        else
          std::cout << "Element at front is " << vec.front() << std::endl;
        break;
      }
      case 'b': {
        if(vec.empty())
          std::cout << "No element at back" << std::endl;
        else
          std::cout << "Element at back is " << vec.back() << std::endl;
        break;
      }
      case 'p': {
        int elem;
        std::cout << "Please enter element to insert: ";
        std::cin >> elem;
        clrbuf(command);
        vec.push_back(elem);
        break;
      }
      case 'o':
        if(vec.empty())
          std::cout << "No element to remove." << std::endl;
        else {
          int item = vec.back();
          vec.pop_back();
          std::cout << "Element at the back is " << item << std::endl;
        }
        break;
      case 'i': {
        std::cout << "Current capacity: " << vec.capacity();
        int item, position;
        std::cout << "Please enter an item to insert: ";
        std::cin >> item;
        clrbuf(command);

        std::cout << "Please enter a position. Note that an invalid position (e.g. one larger" <<
          " than the current capacity) will cause undefinied behavior: ";
        std::cin >> position;
        clrbuf(command);
        vec.insert(position, item);
        break;
      }
      case 'e': {
        fprintf(stdout, "(p)osition or (r)ange? ");
        int pos, start = 0, end = 0;
        char selection = fgetc(stdin);
        clrbuf(selection);
        if(selection == 'p') {
          std::cout << "Enter a position: ";
          std::cin >> pos;
          clrbuf(command);
          vec.erase(pos);
        } else if(selection == 'r') {
          std::cout << "Enter a starting position: ";
          std::cin >> start;
          clrbuf(command);
          std::cout << "Enter an ending position: ";
          std::cin >> end;
          clrbuf(command);
          vec.erase(start, end);
        }
        break;
      }
      case 'c': {
        vec.clear();
        std::cout << "Vector is emptied." << std::endl;
        break;
      }
    }
  }

  return EXIT_SUCCESS;
}