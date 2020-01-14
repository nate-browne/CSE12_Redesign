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

    bool empty(void) const {
      return _queue.empty();
    }

    size_t size(void) const {
      return _queue.size();
    }

    T & front(void) const {
      return _queue.front();
    }

    T & back(void) const {
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

