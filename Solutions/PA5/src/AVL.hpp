#ifndef AVL_HPP
#define AVL_HPP

#include "BST.hpp"

#define THRESHOLD 1

namespace cse12_ds {

  template <class T>
  class AVL : public BST<T> {
    void balance(typename BST<T>::BSTNode *& t) override;
    void rotate_left(typename BST<T>::BSTNode *& t);
    void double_left(typename BST<T>::BSTNode *& t);
    void rotate_right(typename BST<T>::BSTNode *& t);
    void double_right(typename BST<T>::BSTNode *& t);
    void insert(const T & x, typename BST<T>::BSTNode *& t) override;
    void remove(const T & x, typename BST<T>::BSTNode *& t) override;
  public:
    AVL(void);
    AVL(const BST<T> & rhs);
    void insert(const T & x) override;
    void remove(const T & x) override;
  };

  template <class T>
  void AVL<T>::balance(typename BST<T>::BSTNode *& t) {
    if(!t) return;

    if(this->height(t->left) - this->height(t->right) > THRESHOLD) {
      if(this->height(t->left->left) >= this->height(t->left->right))
        this->rotate_left(t);
      else
        this->double_left(t);
    } else if(this->height(t->right) - this->height(t->left) > THRESHOLD) {
      if(this->height(t->right->right) >= this->height(t->right->left))
        this->rotate_right(t);
      else
        this->double_right(t);
    }

    t->height = std::max(this->height(t->left), this->height(t->right)) + 1;
  }

  template <class T>
  void AVL<T>::rotate_left(typename BST<T>::BSTNode *& t) {
    typename BST<T>::BSTNode *l = t->left;
    t->left = l->right;
    l->right = t;
    t->height = std::max(this->height(t->left), this->height(t->right)) + 1;
    l->height = std::max(this->height(l->left), this->height(l->right)) + 1;
    t = l;
  }

  template <class T>
  void AVL<T>::double_left(typename BST<T>::BSTNode *& t) {
    this->rotate_right(t->left);
    this->rotate_left(t);
  }

  template <class T>
  void AVL<T>::rotate_right(typename BST<T>::BSTNode *& t) {
    typename BST<T>::BSTNode *r = t->right;
    t->right = r->left;
    r->left = t;
    t->height = std::max(this->height(t->left), this->height(t->right)) + 1;
    r->height = std::max(this->height(r->left), this->height(r->right)) + 1;
    t = r;
  }

  template <class T>
  void AVL<T>::double_right(typename BST<T>::BSTNode *& t) {
    this->rotate_left(t->right);
    this->rotate_right(t);
  }

  template <class T>
  void AVL<T>::insert(const T & x, typename BST<T>::BSTNode *& t) {
    if(!t) t = new typename BST<T>::BSTNode(x, nullptr, nullptr);
    else if(x < t->element) this->insert(x, t->left);
    else if(t->element < x) this->insert(x, t->right);

    this->balance(t);
  }

  template <class T>
  void AVL<T>::remove(const T & x, typename BST<T>::BSTNode *& t) {
    if(!t) return;

    if(x < t->element) this->remove(x, t->left);
    else if(t->element < x) this->remove(x, t->right);
    else if(t->left && t->right) {
      t->element = this->find_max(t->left)->element;
      this->remove(t->element, t->left);
    } else {
      typename BST<T>::BSTNode *old = t;
      t = (t->left) ? t->left : t->right;
      delete old;
    }

    this->balance(t);
  }

  template <class T>
  AVL<T>::AVL(const BST<T> & rhs) {
    this->root = nullptr;
    this->root = this->clone(rhs.get_root());
  }

  template <class T>
  AVL<T>::AVL(void) {
    this->root = nullptr;
  }

  template <class T>
  void AVL<T>::insert(const T & x) {
    this->insert(x, this->root);
  }

  template <class T>
  void AVL<T>::remove(const T & x) {
    this->remove(x, this->root);
  }
}

#endif
