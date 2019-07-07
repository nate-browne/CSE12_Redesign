#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace cse12_ds {
  template <class T>
  class stack {
   private:
    cse12_ds::vector<T> _stack;
   public:

    stack(void) { }
    ~stack(void) { }

    bool empty(void) {
      return _stack.empty();
    }

    size_t size(void) {
      return _stack.size();
    }

    T & top(void) {
      return _stack.back();
    }

    void push(const T & elem) {
      _stack.push_back(elem);
    }

    void pop(void) {
      _stack.pop_back();
    }
  };
}

#endif
