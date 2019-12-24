#ifndef BST_HPP
#define BST_HPP

#include <cstdio>
#include <cstdlib>

#include <algorithm>

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
    virtual int height(BSTNode *t) const;
    virtual void balance(BSTNode *& t);
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
  int BST<T>::height(BSTNode *t) const {
    return (t) ? t->height : -1;
  }

  template <class T>
  void BST<T>::balance(BSTNode *& t) {
    if(!t) return;

    t->height = std::max(this->height(t->left), this->height(t->right)) + 1;
  }

  template <class T>
  void BST<T>::insert(const T & x, BSTNode *& t) {
    if(!t) t = new BSTNode(x, nullptr, nullptr);
    else if(x < t->element) this->insert(x, t->left);
    else if(t->element < x) this->insert(x, t->right);

    this->balance(t);
  }

  template <class T>
  void BST<T>::remove(const T & x, BSTNode *& t) {
    if(!t) return;
    if(x < t->element) this->remove(x, t->left);
    else if(t->element < x) this->remove(x, t->right);
    else if(t->left && t->right) {
      t->element = this->find_max(t->left)->element;
      this->remove(t->element, t->left);
    } else {
      BSTNode *old = t;
      t = (t->left) ? t->left : t->right;
      delete old;
    }

    this->balance(t);
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::find_min(BSTNode *t) const {
    if(!t) return nullptr;
    if(!t->left) return t;
    return this->find_min(t->left);
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::find_max(BSTNode *t) const {
    if(t) {
      while(t->right) t = t->right;
    }
    return t;
  }

  template <class T>
  bool BST<T>::contains(const T & x, BSTNode *t) const {
    if(!t) return false;
    if(x < t->element) return this->contains(x, t->left);
    if(t->element < x) return this->contains(x, t->right);
    return true;
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
    if(t) {
      this->empty(t->left);
      this->empty(t->right);
      delete t;
    }
    t = nullptr;
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::clone(BSTNode *t) const {
    if(!t) return nullptr;
    return new BSTNode(t->element, this->clone(t->left), this->clone(t->right));
  }

  template <class T>
  BST<T>::BST(void) : root(nullptr) { }

  template <class T>
  BST<T>::BST(const BST & rhs) : root(nullptr) {
    root = this->clone(rhs.root);
  }

  template <class T>
  BST<T>::~BST(void) {
    this->empty();
  }

  template <class T>
  typename BST<T>::BSTNode * BST<T>::get_root(void) const {
    return this->root;
  }

  template <class T>
  const T & BST<T>::find_min(void) const {
    if(this->root) return this->find_min(root)->element;
    else throw std::out_of_range("Tree has no elements");
  }

  template <class T>
  const T & BST<T>::find_max(void) const {
    if(this->root) return this->find_max(root)->element;
    else throw std::out_of_range("Tree has no elements");
  }

  template <class T>
  bool BST<T>::contains(const T & x) const {
    return this->contains(x, this->root);
  }

  template <class T>
  bool BST<T>::is_empty(void) const {
    return !this->root;
  }

  template <class T>
  void BST<T>::print(std::ostream & out) const {
    this->print(out, this->root);
  }

  template <class T>
  void BST<T>::empty(void) {
    this->empty(this->root);
  }

  template <class T>
  void BST<T>::insert(const T & x) {
    this->insert(x, this->root);
  }

  template <class T>
  void BST<T>::remove(const T & x) {
    this->remove(x, this->root);
  }
}

#endif
