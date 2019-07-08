#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>

#include <exception>

#define HALF 2

namespace cse12_ds {

  template <class T>
  class node {
   public:
    node *pre, *next;
    T & data;
    node(const T & data) : pre(nullptr), next(nullptr) {
      this->data = data;
    }
    ~node(void) { }
  };

  template <class T>
  class list {
   private:
    node *front, *back;
    size_t num_elements;

    bool start_from_back(int position) {
      return position >= num_elements / HALF;
    }
   public:

    list(void) {
      next = pre = nullptr;
      num_elements = 0;
    }

    ~list(void) {
      node *tmp = front;
      while(tmp) {
        delete tmp;
        tmp = tmp->next;
      }
    }

    bool empty(void) {
      return num_elements == 0;
    }

    size_t size(void) {
      return num_elements;
    }

    T & front(void) {
      return this->front->data;
    }

    T & back(void) {
      return this->back->data;
    }

    void push_front(const T & val) {
      node *tmp = new node(val);
      tmp->next = this->front;
      this->front->pre = tmp;
      this->front = tmp;
      ++num_elements;
    }

    void pop_front(void) {
      this->front = this->front->next;
      delete this->front->pre;
      this->front->pre = nullptr;
      --num_elements;
    }

    void push_back(const T & val) {
      node *tmp = new node(val);
      this->back->next = tmp;
      tmp->pre = this->back;
      this->back = tmp;
      ++num_elements;
    }

    void pop_back(void) {
      this->back = this->back->pre;
      delete this->back->next;
      this->back->next = nullptr;
      --num_elements;
    }

    void insert(int position, const T & val) {}

    T & erase(int position) {}
    T & erase(int start, int end) {}
    void clear(void) noexcept {}
  };
}


#endif
