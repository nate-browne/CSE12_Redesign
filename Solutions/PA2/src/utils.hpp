#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdio>
#include <cstdlib>

inline static void die(const char *reason) {
  fprintf(stderr, "%s\n", reason);
  exit(1);
}

inline static void clrbuf(void) {
  char c;
  do {
    c = fgetc(stdin);
  } while(c != '\n');
}

#endif

