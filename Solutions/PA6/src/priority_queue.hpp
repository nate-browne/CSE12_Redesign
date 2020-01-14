#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <cerrno>

#include "heap.hpp"

namespace cse12_ds {
  template <class T>
  class priority_queue {
    cse12_ds::heap<T> *hp;
    bool max;
   public:

    priority_queue(bool mx = true) : max(mx) {
      this->hp = new cse12_ds::heap<T>();
    }

    ~priority_queue(void) {
      delete this->hp;
    }

    bool empty(void) const {
      return !this->hp->size();
    }

    size_t size(void) const {
      return this->hp->size();
    }

    void push(const T & x) {
      this->hp->insert(x, this->max);
    }

    void pop(void) {
      try {
        this->hp->remove(this->max);
      } catch(std::out_of_range & ex) {
        std::cerr << std::endl << "\tcse12_ds::priority_queue exception: "
          << ex.what() << std::endl;
      }
    }

    const T top(void) {
      try {
        return this->hp->view();
      } catch(std::out_of_range & ex) {
        std::cerr << std::endl << "\tcse12_ds::priority_queue exception: "
          << ex.what() << std::endl;
        errno = 1;
      }
      return 0;
    }
  };
}

#endif

