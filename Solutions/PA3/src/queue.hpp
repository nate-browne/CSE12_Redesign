#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "vector.hpp"

namespace cse12_ds {
  template <class T>
  class queue {
   private:
    cse12_ds::vector<T> _queue;
   public:

    queue(void) { }
    ~queue(void) { }

    bool empty(void) {
      return _queue.empty();
    }

    size_t size(void) {
      return _queue.size();
    }

    T & front(void) {
      return _queue.front();
    }

    T & back(void) {
      return _queue.back();
    }

    void push(const T & val) {
      _queue.push_back(val);
    }

    void pop(void) {
      _queue.erase(0);
    }
  };
}

#endif
