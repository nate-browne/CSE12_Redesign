#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <getopt.h>
#include <unistd.h>

#include "priority_queue.hpp"

#define PROMPT "Enter a command ((e)mpty, (s)ize, p(u)sh, (p)op, (t)op): "

static struct option longopts[] = {
  {"min", no_argument, NULL, 'm'},
  {NULL, 0, NULL, 0}
};

static void die(const char *reason) {
  fprintf(stderr, "%s\n", reason);
  exit(1);
}

static void clrbuf(void) {
  char ch;
  do {
    ch = fgetc(stdin);
  } while(ch != '\n');
}

void handle_args(int argc, char *argv[], bool & b) {
  int opt;
  while((opt = getopt_long(argc, argv, "m", longopts, NULL)) != EOF) {
    switch(opt) {
      case 'm':
        b = true; // user wants a min heap
        break;
      default:
        die("Invalid argument given to program.");
    }
  }
}

int main(int argc, char *argv[]) {

  bool min_heap = false; // assume user wants a max heap PQ
  char opt;
  uint32_t val;
  uint32_t intr;

  handle_args(argc, argv, min_heap);

  // min_heap == false --> max heap wanted
  // min_heap == true --> min heap wanted
  // our constructor assumes that the param being false means
  // we want a min heap, so we have to invert it
  cse12_ds::priority_queue<uint32_t> pq(!min_heap);

  while(true) {
    std::cout << std::endl << PROMPT;

    // ending condition
    if((opt = fgetc(stdin)) == EOF) break;

    clrbuf();

    switch(opt) {
      case 'e':
        std::cout << std::endl << "\tPriority queue " <<
          (pq.empty() ? "is" : "is not") << " empty." << std::endl;
        break;
      case 's':
        std::cout << std::endl << "\tPriority queue has "
          << pq.size() << " elements." << std::endl;
        break;
      case 'u':
        std::cout << "Enter a value to push: ";
        std::cin >> val;
        clrbuf();
        pq.push(val);
        std::cout << std::endl << "\tValue " << val << " pushed." << std::endl;
        break;
      case 'p':
        pq.pop();
        std::cout << std::endl << "\tTop value removed." << std::endl;
        break;
      case 't':
        errno = 0;
        intr = pq.top();

        if(!errno)
          std::cout << std::endl << "\tValue at top: " << intr << std::endl;
        break;
      default:
        std::cout << "Command '" << opt << "' is not valid." << std::endl;
        break;
    }
  }

  return EXIT_SUCCESS;
}

