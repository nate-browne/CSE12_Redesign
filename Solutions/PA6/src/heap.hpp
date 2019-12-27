#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace cse12_ds {

  template <class T>
  class heap {
    std::vector<T> *vec; // the heap itself

    size_t get_parent(size_t i) const {
      return (i - 1) / 2;
    }

    size_t get_left(size_t i) const {
      return 2 * i + 1;
    }

    size_t get_right(size_t i) const {
      return 2 * i + 2;
    }

    void heapify_down_max(size_t i) {
      size_t left = this->get_left(i);
      size_t right = this->get_right(i);

      size_t max = i;

      // Find the largest between the left and right children
      if(left < this->size() && this->vec->at(left) > this->vec->at(i))
        max = left;
      
      if(right < this->size() && this->vec->at(right) > this->vec->at(max))
        max = right;

      // if the max isn't us, swap elements and recursively
      // heapify down
      if(max != i) {
        std::swap((*this->vec)[i], (*this->vec)[max]);
        this->heapify_down_max(max);
      }
    }

    void heapify_down_min(size_t i) {
      size_t left = this->get_left(i);
      size_t right = this->get_right(i);

      size_t min = i;

      // Find the largest between the left and right children
      if(left < this->size() && this->vec->at(left) < this->vec->at(i))
        min = left;
      
      if(right < this->size() && this->vec->at(right) < this->vec->at(min))
        min = right;

      // if the max isn't us, swap elements and recursively
      // heapify down
      if(min != i) {
        std::swap((*this->vec)[i], (*this->vec)[min]);
        this->heapify_down_min(min);
      }
    }

    void heapify_up_max(size_t i) {
      // make sure we're not the root
      // and that the parent violates heap property
      if(i && (*this->vec)[this->get_parent(i)] < this->vec->at(i)) {
        // swap
        std::swap((*this->vec)[i], (*this->vec)[this->get_parent(i)]);
        // recurse
        this->heapify_up_max(this->get_parent(i));
      }
    }

    void heapify_up_min(size_t i) {
      // make sure we're not the root
      // and that the parent violates heap property
      if(i && (*this->vec)[this->get_parent(i)] > this->vec->at(i)) {
        // swap
        std::swap((*this->vec)[i], (*this->vec)[this->get_parent(i)]);
        // recurse
        this->heapify_up_min(this->get_parent(i));
      }
    }
   public:

    heap(void) {
      this->vec = new std::vector<T>();
    }

    ~heap(void) {
      delete this->vec;
    }

    void insert(const T & x, bool max = true) {
      this->vec->push_back(x);
      size_t ind = this->size() - 1; // element is in back of vector

      // restore heap property
      if(max) heapify_up_max(ind);
      else heapify_up_min(ind);
    }

    void remove(bool max = true) {
      if(!this->size()) throw std::out_of_range("Cannot remove from empty heap.");

      // replace first element with last and remove it
      (*this->vec)[0] = this->vec->back();
      this->vec->pop_back();

      if(max) heapify_down_max(0);
      else heapify_down_min(0);
    }

    const T & view(void) const {
      if(!this->size()) throw std::out_of_range("Cannot top from empty heap.");
      return this->vec->at(0);
    }

    size_t size(void) const {
      return this->vec->size();
    }
  };
}


#endif
