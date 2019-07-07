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
      this->_size = DEFAULT_SIZE; // Start off with default size.
      this->arr = new T[_size];
      this->num_elems = 0;
    }

    ~vector(void) {
      for(size_t i = 0; i < size(); ++i) {
        this->arr[i].~T();
      }
      delete [] this->arr;
    }

    size_t size(void) {
      return this->num_elems;
    }

    size_t capacity(void) {
      return this->_size;
    }

    bool empty(void) {
      return this->num_elems == 0;
    }

    T & operator[](int pos) {
      return this->arr[pos];
    } 

    T & at(unsigned int pos) {
      if(pos < 0 || pos >= this->size()) throw std::out_of_range("Accessing element out of range of vector");
      return this->arr[pos];
    }

    T & front(void) {
      return this->arr[0];
    }

    T & back(void) {
      return this->arr[this->size() - 1];
    }

    void push_back(const T & elem) {
      if(size() == capacity()) {
        this->_size = this->_size * 2;
        T *n = new T[this->_size];
        for(size_t i = 0; i < size(); ++i) {
          n[i] = this->arr[i];
          this->arr[i].~T();
        }
        delete [] this->arr;
        this->arr = n;
      }
      this->arr[num_elems++] = elem;
    }

    void pop_back(void) {
      this->arr[num_elems - 1].~T();
      num_elems--;
    }

    void insert(int position, const T & item) {
      if(size() == capacity()) {
        this->_size = this->_size * 2;
        T *n = new T[this->_size];
        for(size_t i = 0; i < size(); ++i) {
          n[i] = this->arr[i];
          this->arr[i].~T();
        }
        delete [] this->arr;
        this->arr = n;
      }

      for(int i = size() - 1; i >= position; --i) {
        this->arr[i + 1] = this->arr[i];
      }
      this->arr[position] = item;
      num_elems++;
    }

    void erase(int position) {
      this->arr[position].~T();
      for(size_t i = position + 1; i < num_elems; ++i) {
        this->arr[i - 1] = this->arr[i];
      }
      num_elems--;
    }

    void erase(int start, int end) {
      for(int i = start; i < end; ++i) {
        this->arr[i].~T();
      }
      for(size_t i = end, counter = 0; i < num_elems; ++i, ++counter) {
        this->arr[start + counter] = this->arr[i];
      }
      num_elems = num_elems - (end - start); // decrement number of elements in vector
    }

    void clear() noexcept {
      for(size_t i = 0; i < size(); ++i) {
        this->arr[i].~T();
      }
      this->num_elems = 0;
    }
  };
}

#endif