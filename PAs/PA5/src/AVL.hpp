#ifndef AVL_HPP
#define AVL_HPP

#include <algorithm>

#include "BST.hpp"

#define THRESHOLD 1

template <class T>
class AVL : public BST<T> {
  int height(typename BST<T>::BSTNode *t) const;
  void balance(typename BST<T>::BSTNode *& t);
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
int AVL<T>::height(typename BST<T>::BSTNode *t) const {
  return (t) ? t->height : -1;
}

template <class T>
void AVL<T>::balance(typename BST<T>::BSTNode *& t) {
}

template <class T>
void AVL<T>::rotate_left(typename BST<T>::BSTNode *& t) {
}

template <class T>
void AVL<T>::double_left(typename BST<T>::BSTNode *& t) {
}

template <class T>
void AVL<T>::rotate_right(typename BST<T>::BSTNode *& t) {
}

template <class T>
void AVL<T>::double_right(typename BST<T>::BSTNode *& t) {
}

template <class T>
void AVL<T>::insert(const T & x, typename BST<T>::BSTNode *& t) {
}

template <class T>
void AVL<T>::remove(const T & x, typename BST<T>::BSTNode *& t) {
}

template <class T>
AVL<T>::AVL(const BST<T> & rhs) {
}

template <class T>
AVL<T>::AVL(void) {
}

template <class T>
void AVL<T>::insert(const T & x) {
}

template <class T>
void AVL<T>::remove(const T & x) {
}

#endif
