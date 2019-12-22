#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>

#include "list.hpp"

#define LIST_STR "Please enter a command ((a)llocate, (d)eallocate, (c)lear, (f)ront, (b)ack,\
 (s)ize, pus(h)_front, p(u)sh_back, (i)nsert, p(o)p_back, (p)op_front, (e)rase): "

#define NULL_STR "\n\tERROR: Cannot %s a null list.\n"

inline void clrbuf(void) {
  char c = '\0';
  while(c != '\n') c = fgetc(stdin);
}

int main(void) {

  cse12_ds::list<std::string> *lst = nullptr;

  while(true) {
    std::string elem;
    char buf[BUFSIZ];
    int pos;
    char command = '\0';

    std::cout << std::endl << LIST_STR;

    if((command = fgetc(stdin)) == EOF) break;
    clrbuf();

    switch(command) {
      case 'a':
        lst = new cse12_ds::list<std::string>();
        std::cout << "\n\tList allocated." << std::endl;
        break;
      case 'd':
        if(lst) {
          delete lst;
          lst = nullptr;
          std::cout << "\n\tList deallocated." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "deallocate");
        }
        break;
      case 'c':
        if(lst) {
          lst->clear();
          std::cout << "\n\tList has been cleared." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "clear");
        }
        break;
      case 'f':
        if(lst) {
          elem = lst->front();
          std::cout << "\n\tElement at front of list is \"" << elem << "\"" << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "get element at front of");
        }
        break;
      case 'b':
        if(lst) {
          elem = lst->back();
          std::cout << "\n\tElement at back of list is \"" << elem << "\"" << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "get element at back of");
        }
        break;
      case 's':
        if(lst) {
          size_t sz = lst->size();
          std::cout << "\n\tList has " << sz << " elements in it." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "get size of");
        }
        break;
      case 'h':
        if(lst) {
          std::cout << "Enter a string to insert at the front: ";
          std::cin >> buf;
          elem = std::string(buf);
          clrbuf();
          lst->push_front(elem);
          std::cout << "\n\tElement inserted." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "push to front of");
        }
        break;
      case 'u':
        if(lst) {
          std::cout << "Enter a string to insert at the back: ";
          std::cin >> buf;
          elem = std::string(buf);
          clrbuf();
          lst->push_back(elem);
          std::cout << "\n\tElement inserted." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "push to back of");
        }
        break;
      case 'i':
        if(lst) {
          std::cout << "Enter a position to insert between [0, size()): ";
          std::cin >> pos;

          std::cout << "Enter a string to insert: ";
          std::cin >> buf;
          elem = std::string(buf);
          clrbuf();
          lst->insert(pos, elem);
          std::cout << "\n\tElement inserted." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "insert into");
        }
        break;
      case 'o':
        if(lst) {
          lst->pop_back();
          std::cout << "\n\tLast element removed." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "pop from back of");
        }
        break;
      case 'p':
        if(lst) {
          lst->pop_front();
          std::cout << "\n\tFirst element removed." << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "pop from front of");
        }
        break;
      case 'e':
        if(lst) {
          std::cout << "Enter a position to erase between [0, size()): ";
          std::cin >> pos;

          elem = lst->erase(pos);
          std::cout << "\n\tItem following erased item is \"" << elem << "\"" << std::endl;
        } else {
          fprintf(stderr, NULL_STR, "erase item from");
        }
        break;
      default:
        std::cerr << "\n\tCommand '" << command << "' is invalid." << std::endl;
        break;
    }
  }

  if(lst) delete lst;
  return EXIT_SUCCESS;
}
