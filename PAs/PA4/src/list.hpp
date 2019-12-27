#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>

#define HALF 2

namespace cse12_ds {

  template <class T>
  class list {
   private:
    struct node {
      node *pre, *next;
      T data;
      node(const T & data) : pre(nullptr), next(nullptr) {
        this->data = data;
      }
      ~node(void) { }
    };

    node *_front, *_back;
    size_t num_elements;

    bool start_from_back(size_t position) {
      return position >= num_elements / HALF;
    }
   public:

    list(void) : _front(nullptr), _back(nullptr) {
      num_elements = 0;
    }

    ~list(void) {
    }
  };
}

#endif
