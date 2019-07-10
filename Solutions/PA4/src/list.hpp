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
    T data;
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
      node *nt = tmp->next;
      while(tmp) {
        delete tmp;
        tmp = nt;
        nt = nt->next;
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

    void insert(int position, const T & val) {
      node *finder;
      node *tmp;

      if(position == 0 || position == this->size() - 1) {
        tmp = new node(val);
        switch(position) {
          case 0:
            tmp->pre = nullptr;
            tmp->next = this->front;
            this->front->pre = tmp;
            break;
          case this->size() - 1:
            tmp->next = nullptr;
            tmp->pre = this->back;
            this->back->next = tmp;
            break;
        }
      } else {
        if(start_from_back(position)) {
          int counter = 0;
          finder = this->back;
          for( ; counter < position; counter++) {
            finder = tmp->pre;
          }
        } else {
          int counter = 0;
          finder = this->front;
          for( ; counter < position; counter++) {
            finder = tmp->next;
          }
        }

        tmp = new node(val);
        tmp->next = finder;
        tmp->pre = finder->pre;
        finder->pre->next = tmp;
        finder->pre = tmp;
      }
    }

    T & erase(int position) {
      node *tmp;
      if(position == 0 || position == size() - 1) {

      } else {

        if(start_from_back(position)) {
          int counter = 0;
          tmp = this->back;
          for( ; counter < position; counter++) {
            tmp = tmp->pre;
          }
        } else {

        }
      }
    }
    T & erase(int start, int end) {}

    void clear(void) noexcept {
      node *tmp = this->front;
      node *nt = this->front->next;
      while(tmp) {
        delete tmp;
        tmp = nt;
        nt = nt->next;
      }
    }
  };
}

#endif
