/*-----------------------------------------------------------------------------

                                                        Author: Nate Browne
                                                        Date: 20 Aug 2018
                        AVL Tree Implementation

File Name:       avl_tree.h
Description:     This file sets up the initial class for the AVL tree. An AVL
                 tree is a binary search tree that stays balanced through a
                 series of rotations instead of by using removals and
                 reinsertions. For a tree to count as an AVL tree, the left and
                 right subtrees of any node must not have a height difference
                 greater than 1 and every subtree must also be an AVL tree.
-----------------------------------------------------------------------------*/
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

// Rebalancing threshold
#define THRESHOLD 1

// debug messages
const std::string AND = " and ";
const std::string CHECK = " - Checking ";
const std::string COMPARE = " - Comparing ";
const std::string DEALLOCATE = " - Deallocating]";
const std::string INSERT = " - Inserting ";
const std::string UPDATE = " - Updating ";
const std::string REPLACE = " - Replacing ";
const std::string TREE = "[Tree ";
const std::string ALLOCATE = " - Allocating]";

// Defined in avl_tree.cpp
template <class E>
class TNode;

/*=============================================================================
/ class AVLTree
/
/ Description: Implements an AVL Tree data structure, as defined above.
/
/ Data Fields:
/     friend class TNode: Gives the TNode access to Tree members
/     unsigned int occupancy
/     TNode<E> *root: Pointer to the root node of our Tree
/     unsigned int tree_count: Number of trees allocated
/     static bool debug: used to doggle debug mode on or off.
/     static int counter: used to keep count of number of trees instantiated
/     bool is_primitive: used to determine which debug message to print
/
/ Public Functions:
/     Tree(): Tree Constructor
/     ~Tree(): Tree Destructor
/     static void set_debug(bool): sets the debug boolean on or off
/     bool is_empty(): Checks if the Tree is empty
/     bool insert(const ? &): insert an element
/     bool lookup(? &): search for an item
/     bool remove(? &): removes an element and returns it
/     ostream & Write(ostream &): write out the tree
/============================================================================*/
template <class E>
class Tree {

  // private section
  friend class TNode<E>;
  unsigned int occupancy;
  TNode<E> *root;
  unsigned int tree_count;
  static bool debug;
  static int counter;

public:

  Tree(void);
  ~Tree(void);

  static void set_debug(bool);
  bool is_empty(void) const;
  bool insert(const E &);
  bool lookup(E &) const;
  bool remove(E &);
  void check(void);
  std::ostream & Write(std::ostream &) const;
};

#include "avl_tree.cpp"

#endif
