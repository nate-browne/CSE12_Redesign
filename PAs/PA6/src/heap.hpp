#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <stdexcept>

namespace cse12_ds {

  template <class T>
  class heap {
    // composed objects go here (if relevant to you)

    // you may also want some private helper functions
    // to make your code easier to read. If so,
    // define and implement them here

   public:

    heap(void) {
    }

    ~heap(void) {
    }

    void insert(const T & x, bool max = true) {
    }

    void remove(bool max = true) {
      if(!this->size()) throw std::out_of_range("Cannot remove from empty heap.");

    }

    const T & view(void) const {
      if(!this->size()) throw std::out_of_range("Cannot top from empty heap.");
    }

    size_t size(void) const {
    }
  };
}


#endif

