#include <cstdio>
#include <cstdlib>

#include <string>
#include <iostream>

#include "queue.hpp"
#include "stack.hpp"

#define QUEUE_STR "Please enter a command: (e(m)pty, (s)ize, (f)ront, (b)ack, (p)ush, p(o)p): ";
#define STACK_STR "Please enter a command: (e(m)pty, (s)ize, (t)op, (p)ush, p(o)p): ";

void clrbuf(char c) {
  while(c != '\n') c = fgetc(stdin);
}

int main(void) {

  char dec;
  cse12_ds::queue<std::string> *queue = nullptr;
  cse12_ds::stack<std::string> *stack = nullptr;
  std::cout << "(q)ueue or (s)tack? ";
  dec = fgetc(stdin);
  clrbuf(dec);

  switch(dec) {
    case 'q':
      queue = new cse12_ds::queue<std::string>();
      break;
    case 's':
      stack = new cse12_ds::stack<std::string>();
      break;
    default:
      std::cerr << "Invalid option: " << dec << "." << std::endl;
      exit(1);
  }

  while(true) {
    char command = '\0';
    if(queue) {
      std::cout << QUEUE_STR;
    } else {
      std::cout << STACK_STR;
    }

    if((command = fgetc(stdin)) == EOF) {
      break;
    }
    clrbuf(command);

    switch(command) {
      case 'm': {
        if(queue) {
          if(queue->empty()) {
            std::cout << "Queue is empty" << std::endl;
          } else {
            std::cout << "Queue is not empty" << std::endl;
          }
        } else {
          if(stack->empty()) {
            std::cout << "Stack is empty" << std::endl;
          } else {
            std::cout << "Stack is not empty" << std::endl;
          }
        }
        break;
      }
      case 's': {
        if(queue) {
          std::cout << "Number of elements in queue is: " << queue->size() << std::endl;
        } else {
          std::cout << "Number of elements in stack is: " << stack->size() << std::endl;
        }
        break;
      }
      case 'f': {
        if(queue) {
          if(queue->empty())
            std::cout << "No element at front" << std::endl;
          else
            std::cout << "Element at front is " << queue->front() << std::endl;
        }
        break;
      }
      case 'b': {
        if(queue) {
          if(queue->empty())
            std::cout << "No element at back" << std::endl;
          else
            std::cout << "Element at back is " << queue->back() << std::endl;
        }
        break;
      }
      case 'p': {
        char buffer[BUFSIZ], *nl;
        std::cout << "Please enter string to insert: ";
        fgets(buffer, BUFSIZ, stdin);
        nl = strchr(buffer, '\n');
        if(nl) *nl = '\0';
        std::string elem(buffer);
        if(queue) {
          queue->push(buffer);
        } else {
          stack->push(buffer);
        }
        break;
      }
      case 'o':
        if(queue) {
          if(queue->empty())
            std::cout << "No element to remove." << std::endl;
          else {
            std::string item = queue->front();
            queue->pop();
            std::cout << "Element removed is " << item << std::endl;
          }
        } else {
          if(stack->empty())
            std::cout << "No element to remove." << std::endl;
          else {
            std::string item = stack->top();
            stack->pop();
            std::cout << "Element popped is " << item << std::endl;
          }
        }
        break;
      case 't': {
        if(stack) {
          if(stack->empty())
            std::cout << "No item to top." << std::endl;
          else {
            std::string item = stack->top();
            std::cout << "Item topped is " << item << std::endl;
          }
        }
        break;
      }
    }
  }

  delete queue;
  delete stack;
  return EXIT_SUCCESS;
}