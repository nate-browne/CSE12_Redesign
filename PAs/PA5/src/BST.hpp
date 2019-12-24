#ifndef BST_HPP
#define BST_HPP

#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <exception>

namespace cse12_ds {

  template <class T>
  class BST {
  protected:
    struct BSTNode {
      T element;
      BSTNode *left, *right;
      int height;
      BSTNode(const T & el, BSTNode *lt, BSTNode *rt, int height = 0) : element(el), left(lt), right(rt) {
        this->height = height;
      }
      ~BSTNode(void) { }
    };

    BSTNode *root;
    virtual void insert(const T & x, BSTNode *& t);
    virtual void remove(const T & x, BSTNode *& t);
    virtual BSTNode * find_min(BSTNode *t) const;
    virtual BSTNode * find_max(BSTNode *t) const;
    virtual bool contains(const T & x, BSTNode *t) const;
    virtual void print(std::ostream & out, BSTNode *t) const;
    virtual void empty(BSTNode *& t);
    virtual BSTNode * clone(BSTNode *t) const;
  public:
    BST(void);
    BST(const BST & rhs);
    virtual ~BST(void);

    virtual BSTNode * get_root(void) const;
    virtual const T & find_min(void) const;
    virtual const T & find_max(void) const;
    virtual bool contains(const T & x) const;
    virtual bool is_empty(void) const;
    virtual void print(std::ostream & out = std::cout) const;
    virtual void empty(void);
    virtual void insert(const T & x);
    virtual void remove(const T & x);
  };

  template <class T>
  void BST<T>::insert(const T & x, BSTNode *& t) {
  }

  template <class T>
  void BST<T>::remove(const T & x, BSTNode *& t) {
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::find_min(BSTNode *t) const {
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::find_max(BSTNode *t) const {
  }

  template <class T>
  bool BST<T>::contains(const T & x, BSTNode *t) const {
  }

  template <class T>
  void BST<T>::print(std::ostream & out, BSTNode *t) const {
    if(!t) return;
    this->print(out, t->left);
    out << "height: " << t->height << " element: " << t->element << std::endl;
    this->print(out, t->right);
  }

  template <class T>
  void BST<T>::empty(BSTNode *& t) {
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::clone(BSTNode *t) const {
  }

  template <class T>
  BST<T>::BST(void) : root(nullptr) { }

  template <class T>
  BST<T>::BST(const BST & rhs) : root(nullptr) {
  }

  template <class T>
  BST<T>::~BST(void) {
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::get_root(void) const {
  }

  template <class T>
  const T & BST<T>::find_min(void) const {
    if(this->root) return this->find_min(this->root)->element;
    else throw std::out_of_range("Tree has no elements");
  }

  template <class T>
  const T & BST<T>::find_max(void) const {
    if(this->root) return this->find_max(this->root)->element;
    else throw std::out_of_range("Tree has no elements");
  }

  template <class T>
  bool BST<T>::contains(const T & x) const {
  }

  template <class T>
  bool BST<T>::is_empty(void) const {
  }

  template <class T>
  void BST<T>::print(std::ostream & out) const {
  }

  template <class T>
  void BST<T>::empty(void) {
  }

  template <class T>
  void BST<T>::insert(const T & x) {
  }

  template <class T>
  void BST<T>::remove(const T & x) {
  }
}

#endif
