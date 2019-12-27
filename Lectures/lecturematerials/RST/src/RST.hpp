#ifndef RST_HPP
#define RST_HPP

#include <algorithm>
#include <exception>
#include <functional>
#include <random>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>

template <class T>
class RST {
  struct RSTNode {
    T element;
    RSTNode *left, *right;
    int priority, height;
    RSTNode(void) : left(nullptr), right(nullptr), priority(INT_MAX) { }
    RSTNode(const T & x, RSTNode *lt, RSTNode *rt, int pr) :
      element(x), left(lt), right(rt), priority(pr) {
      this->height = 0;
    }
  };

  RSTNode *root;
  RSTNode *nullNode;

  std::default_random_engine g;
  std::uniform_int_distribution<int> dist;

  void rotate_left(RSTNode *& t) {
    RSTNode *l = t->left;
    t->left = l->right;
    l->right = t;
    t = l;
  }

  void rotate_right(RSTNode *& t) {
    RSTNode *r = t->right;
    t->right = r->left;
    r->left = t;
    t = r;
  }

  int height(RSTNode *t) {
    return (t != nullNode) ? t->height : -1;
  }

  void balance(RSTNode *& t) {
    if(t == nullNode) return;
    t->height = std::max(this->height(t->left), this->height(t->right)) + 1;
  }


  void insert(const T & x, RSTNode *& t) {
    if(t == nullNode) t = new RSTNode(x, nullNode, nullNode, dist(g));
    else if(x < t->element) {
      this->insert(x, t->left);
      if(t->left->priority < t->priority) this->rotate_left(t);
    } else if(t->element < x) {
      this->insert(x, t->right);
      if(t->right->priority < t->priority) this->rotate_right(t);
    }

    this->balance(t);
  }

  void remove(const T & x, RSTNode *& t) {
    if(t != nullNode) {
      if(x < t->element) this->remove(x, t->left);
      else if(t->element < x) this->remove(x, t->right);
      else {
        if(t->left->priority < t->right->priority)
          this->rotate_left(t);
        else
          this->rotate_right(t);

        if(t != nullNode)
          this->remove(x, t);
        else {
          delete t->left;
          t->left = nullNode;
        }
      }
    }
    this->balance(t);
  }

  RSTNode * find_min(RSTNode * t) const {
    if(t->left == nullNode) return t;
    return this->find_min(t->left);
  }

  RSTNode *find_max(RSTNode *t) const {
    if(t->right == nullNode) return t;
    return this->find_max(t->right);
  }

  bool contains(const T & x, RSTNode *t) const {
    if(t == nullNode) return false;
    if(x < t->element) return this->contains(x, t->left);
    if(t->element < x) return this->contains(x, t->right);
    return true;
  }

  void print(std::ostream & out, RSTNode *t) const {
    if(t == nullNode) return;
    this->print(out, t->left);
    out << "height: " << t->height << " priority: " << t->priority
      << " element: " << t->element << std::endl;
    this->print(out, t->right);
  }

  void empty(RSTNode *& t) {
    if(t != nullNode) {
      this->empty(t->left);
      this->empty(t->right);
      delete t;
    }
  }

 public:

  RST(void) {
    nullNode = new RSTNode();
    nullNode->left = nullNode->right = nullNode;
    root = nullNode;
  }

  ~RST(void) {
    if(root != nullNode) {
      this->empty();
    }
    delete nullNode;
  }

  const T & find_min(void) const {
    if(root != nullNode) return this->find_min(this->root)->element;
    else throw std::out_of_range("Tree has no elements.");
  }

  const T & find_max(void) const {
    if(root != nullNode) return this->find_max(this->root)->element;
    else throw std::out_of_range("Tree has no elements.");
  }

  bool contains(const T & x) const {
    return this->contains(x, this->root);
  }

  bool is_empty(void) const {
    return this->root == nullNode;
  }

  void print(std::ostream & out = std::cout) const {
    this->print(out, this->root);
  }

  void empty(void) {
    this->empty(this->root);
  }

  void insert(const T & x) {
    this->insert(x, this->root);
  }

  void remove(const T & x) {
    this->remove(x, this->root);
  }

};

#endif

