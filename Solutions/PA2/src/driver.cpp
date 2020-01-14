#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>

#include "vector.hpp"

inline void clrbuf(void) {
  char c;
  do {
    c = fgetc(stdin);
  } while(c != '\n');
}

int main(void) {

  cse12_ds::vector<int> vec;

  while(true) {
    char command = '\0';
    std::cout << "Please enter a command (e(m)pty, (s)ize, element (a)t, (f)ront, (b)ack," << 
    " (p)ush back, p(o)p back, (i)nsert, (e)rase, (c)lear): ";
    if((command = fgetc(stdin)) == EOF) {
      break;
    }
    clrbuf();

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
        clrbuf();
        try {
          std::cout << "Element at position " << pos << " is " << vec.at(pos) << std::endl;
        } catch(std::out_of_range & ex) {
          std::cerr << ex.what() << std::endl;
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
        clrbuf();
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
        std::cout << "Current capacity: " << vec.capacity() << std::endl;
        int item, position;
        std::cout << "Please enter an item to insert: ";
        std::cin >> item;
        clrbuf();

        std::cout << "Please enter a position. Note that an invalid position (e.g. one larger" <<
          " than the current capacity) will cause undefinied behavior: ";
        std::cin >> position;
        clrbuf();
        vec.insert(position, item);
        break;
      }
      case 'e': {
        fprintf(stdout, "(p)osition or (r)ange? ");
        int pos, start = 0, end = 0;
        char selection = fgetc(stdin);
        clrbuf();
        if(selection == 'p') {
          std::cout << "Enter a position: ";
          std::cin >> pos;
          clrbuf();
          vec.erase(pos);
        } else if(selection == 'r') {
          std::cout << "Enter a starting position: ";
          std::cin >> start;
          clrbuf();
          std::cout << "Enter an ending position: ";
          std::cin >> end;
          clrbuf();
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

