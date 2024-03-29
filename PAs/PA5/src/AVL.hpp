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
   public:
    AVL(void);
    AVL(const BST<T> & rhs);
  };

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
  AVL<T>::AVL(const BST<T> & rhs) {
  }

  template <class T>
  AVL<T>::AVL(void) {
  }
}

#endif

