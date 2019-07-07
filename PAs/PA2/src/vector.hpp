#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <exception>

#define DEFAULT_SIZE 10

namespace cse12_ds {

  template <class T>
  class vector {
   private:
    T *arr; // the array itself
    size_t _size; // size of the array
    size_t num_elems; // Number of elements in the array
   public:

    vector(void) {
      /*
       * TODO: Finish this constructor
       */
    }

    ~vector(void) {
      /*
       * TODO: Finish this destructor
       */
    }

    size_t size(void) {
      /*
       * TODO: Finish size
       */
    }

    size_t capacity(void) {
      /*
       * TODO: Finish capacity
       */
    }

    bool empty(void) {
      /*
       * TODO: Finish empty
       */
    }

    T & operator[](int pos) {
      /*
       * TODO: Finish operator []
       */
    } 

    T & at(unsigned int pos) {
      /*
       * TODO: Finish at
       */
    }

    T & front(void) {
      /*
       * TODO: Finish front
       */
    }

    T & back(void) {
      /*
       * TODO: Finish back
       */
    }

    void push_back(const T & elem) {
      /*
       * TODO: Finish push_back
       */
    }

    void pop_back(void) {
      /*
       * TODO: Finish pop_back
       */
    }

    void insert(int position, const T & item) {
      /*
       * TODO: Finish insert
       */
    }

    void erase(int position) {
      /*
       * TODO: Finish erase
       */
    }

    void erase(int start, int end) {
      /*
       * TODO: Finish ranged erase
       */
    }

    void clear() noexcept {
      /*
       * TODO: Finish clear
       */
    }
  };
}

#endif