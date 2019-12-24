#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>
#include <exception>

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
      if(!this->empty())
        this->clear();
    }

    bool empty(void) const {
      return size() == 0;
    }

    size_t size(void) const {
      return num_elements;
    }

    const T & front(void) const {
      return this->_front->data;
    }

    const T & back(void) const {
      return this->_back->data;
    }

    void push_front(const T & val) {
      node *tmp = new node(val);

      if(!_front) {
        this->_front = tmp;
      } else {
        tmp->next = this->_front;
        this->_front->pre = tmp;
        this->_front = tmp;
      }
      ++num_elements;
      if(this->size() == 1) this->_back = this->_front;
    }

    void pop_front(void) {
      node *tmp = this->_front;
      this->_front = this->_front->next;
      delete tmp;
      --num_elements;
      if(this->size())
        this->_front->pre = nullptr;
      else
        this->_front = this->_back = nullptr;
    }

    void push_back(const T & val) {
      node *tmp = new node(val);

      if(!_back) {
        this->_back = tmp;
      } else {
        this->_back->next = tmp;
        tmp->pre = this->_back;
        this->_back = tmp;
      }
      ++num_elements;
      if(this->size() == 1) this->_front = this->_back;
    }

    void pop_back(void) {
      node *tmp = this->_back;
      this->_back = this->_back->pre;
      delete tmp;
      --num_elements;
      if(this->size())
        this->_back->next = nullptr;
      else
        this->_front = this->_back = nullptr;
    }

    void insert(const size_t position, const T & val) {
      node *finder;
      node *tmp;

      if(!position || position == this->size() - 1) {
        tmp = new node(val);
        switch(position) {
          case 0:
            tmp->next = this->_front;
            this->_front->pre = tmp;
            this->_front = tmp;
            break;
          default:
            tmp->pre = this->_back;
            this->_back->next = tmp;
            this->_back = tmp;
            break;
        }
        return;
      } else {
        if(start_from_back(position)) {
          size_t counter = 0;
          finder = this->_back;
          for( ; counter < position; counter++) {
            finder = finder->pre;
          }
        } else {
          size_t counter = 0;
          finder = this->_front;
          for( ; counter < position; counter++) {
            finder = finder->next;
          }
        }

        tmp = new node(val);
        tmp->next = finder;
        tmp->pre = finder->pre;
        finder->pre->next = tmp;
        finder->pre = tmp;
      }
    }

    T & erase(const size_t position) {
      if(!position || position == this->size() - 1) {
        switch(position) {
          case 0:
            this->_front = this->_front->next;
            delete this->_front->pre;
            this->_front->pre = nullptr;
            break;
          default:
            this->_back = this->_back->pre;
            delete this->_back->next;
            this->_back->next = nullptr;
            break;
        }
        --num_elements;
        return (position == 0) ? this->_front->data : this->_back->data;
      } else {
        node *finder;
        if(start_from_back(position)) {
          size_t counter = 0;
          finder = this->_back;
          for( ; counter < position; ++counter)
            finder = finder->pre;
        } else {
          size_t counter = 0;
          finder = this->_front;
          for( ; counter < position; ++counter)
            finder = finder->next;
        }

        T & data = finder->next->data;
        finder->next->pre = finder->pre;
        finder->pre->next = finder->next;
        delete finder;
        return data;
      }
    }

    void clear(void) noexcept {
      node *tmp = this->_front;
      node *nt = this->_front->next;
      while(tmp) {
        delete tmp;
        tmp = nt;
        nt = (nt) ? nt->next : nullptr;
      }

      this->_back = this->_front = nullptr;
      this->num_elements = 0;
    }
  };
}

#endif
