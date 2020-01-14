#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>

namespace test_utils {

  template <class T>
  inline bool test(const T & got, const T & expected) {
    if(got == expected) {
      std::cout << "OK; expected \"" << expected << "\" got \"" << got << "\"" << std::endl;
      return true;
    } else {
      std::cout << "FAILED; expected \"" << expected << "\" got \"" << got << "\"" << std::endl;
      return false;
    }
  }
}

#endif

