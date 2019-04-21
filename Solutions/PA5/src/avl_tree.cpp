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
#include <string>
#include <cstdlib>
#include "avl_tree.h"

template <class E>
bool Tree<E>::debug = false;

template <class E>
int Tree<E>::counter = 0;

// Function prototype for the << operator
template <class E>
std::ostream & operator << (std::ostream &, const TNode<E> &);

/*=============================================================================
/ class TNode
/
/ Description: Implements a node for the AVL Tree.
/
/ Data Fields:
/     int balance: left child height - right child height
/     E data: data object held by the node
/     int height: tallest child height + 1
/     TNode<E> *left: pointer to the node left of the current node
/     int & occupancy: reference to the Tree's occupancy
/     TNode<E> *right: pointer to the node right of the current node
/     unsigned int & tree_count: reference to the Tree's count (number of the
/                                tree)
/
/ Private Functions:
/     rotate_left(): rotates the current node left
/     rotate_right(): rotates the current node right
/     double_left(): perform a left right rotation
/     double_right(); perform a right left rotation
/
/ Public Functions:
/     TNode(): constructor for the root
/     TNode(): constructor for every other node
/    ~TNode(): destructor
/     Write_AllNodes: function that writes out the nodes via in order traversal
/     RARM(): function used to remove a node with two children
/     delete_AllNodes: deletes all nodes in via post order traversal
/     insert(): insert node into tree
/     lookup(): lookup node in the tree
/     remove(): remove node from the tree
/     SHAB(): sets the height and balance of the node
/============================================================================*/
template <class E>
class TNode {

  // private functions
  void rotate_left(TNode<E> *&);
  void rotate_right(TNode<E> *&);
  void double_left(TNode<E> *&);
  void double_right(TNode<E> *&);

public:

  // data fields
  int balance;
  E data;
  int height;
  TNode<E> *left, *right;
  unsigned int & occupancy;
  unsigned int & tree_count;

  // public functions
  TNode(const E &, Tree<E> &);
  TNode(const E &, TNode<E> &);
  ~TNode(void);
  std::ostream & Write_AllNodes(std::ostream &) const;
  void delete_AllNodes(void);
  void check_all(void);
  void RARM(TNode<E> &, TNode<E> *&);
  bool insert(const E &, TNode<E> *&);
  bool lookup(E &) const;
  bool remove(TNode<E> &, TNode<E> *&, bool fromSHB = false);
  void SHAB(TNode<E> *&);
  bool operator == (const TNode<E> &) const;
};

/*-----------------------------------------------------------------------------
% Routine Name: TNode(constructor)
% File: avl_tree.cpp
%
% Description:  Creates a TNode as called by Tree's insert method. All fields
% are initialized via guaranteed initialization so the only thing the body has
% to do is increment the occupancy
%
% Result:       A TNode is created
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% element           reference to the element to use as the data
% tree              reference to the tree used as the calling object
-----------------------------------------------------------------------------*/
template <class E>
TNode<E>::TNode(const E & element, Tree<E> & tree) :
  balance(0), data(element), height(0), left(nullptr), right(nullptr),
  occupancy(tree.occupancy), tree_count(tree.tree_count) {

  occupancy++;
}

/*-----------------------------------------------------------------------------
% Routine Name: TNode(constructor)
% File: avl_tree.cpp
%
% Description:  Creates a TNode as called by TNode's insert method. All fields
% are initialized via guaranteed initialization so the only thing the body has
% to do is increment the occupancy
%
% Result:       A TNode is created
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% element           reference to the element to use as the data
% tree              reference to the TNode used as the calling object
-----------------------------------------------------------------------------*/
template <class E>
TNode<E>::TNode(const E & element, TNode<E> & parent) :
  balance(0), data(element), height(0), left(nullptr), right(nullptr),
  occupancy(parent.occupancy), tree_count(parent.tree_count) {

  occupancy++;
}

/*-----------------------------------------------------------------------------
% Routine Name: ~TNode(destructor)
% File: avl_tree.cpp
%
% Description:  Destroys a TNode object. Since nothing was dynamically
% allocated, only the occupancy is decremented.
%
% Result:       TNode is destroyed
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% N/A
-----------------------------------------------------------------------------*/
template <class E>
TNode<E>::~TNode(void) {
  occupancy--;
}

/*-----------------------------------------------------------------------------
% Routine Name: operator ==
% File: avl_tree.cpp
%
% Description:  Overload the == operator to compare TNodes by comparing their
% data fields. If two TNodes have the same data field, then they are equal
%
% Result:       TNodes are compared
% Return:       true if TNodes are equal, false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% other             const reference to a TNode for comparing
-----------------------------------------------------------------------------*/
template <class E>
bool TNode<E>::operator == (const TNode<E> & other) const {

  return this->data == other.data;
}

/*-----------------------------------------------------------------------------
% Routine Name: rotate_left()
% File: avl_tree.cpp
%
% Description:  Performs a left rotation for rebalancing. This situation arises
% if a tree (or subtree) is right-heavy, meaning that it has a balance less than
% -1. To perform this rotation, set PIP to the calling node's right child, set
% the right child to the PIP node's left child, then set the PIP node's left
% child to the calling node.
%
% Result:       The tree is rebalanced
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% PIP               Pointer in the parent node followed to reach current node
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::rotate_left(TNode<E> *& PIP) {

  PIP = this->right;
  this->right = PIP->left;
  PIP->left = this;

  // Update height and balance
  this->SHAB(PIP);
}

/*-----------------------------------------------------------------------------
% Routine Name: rotate_right()
% File: avl_tree.cpp
%
% Description:  Performs a right rotation for rebalancing. This situation arises
% if a tree (or subtree) is left-heavy, meaning that it has a balance greater
% than 1. To perform this rotation, set PIP to the calling node's left child,
% set the left child to the PIP node's right child, then set the PIP node's
% right child to the calling node.
%
% Result:       The tree is rebalanced
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% PIP               Pointer in the parent node followed to reach current node
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::rotate_right(TNode<E> *& PIP) {

  PIP = this->left;
  this->left = PIP->right;
  PIP->right = this;

  // Update height and balance
  this->SHAB(PIP);
}

/*-----------------------------------------------------------------------------
% Routine Name: double_left()
% File: avl_tree.cpp
%
% Description:  Performs a double left rotation (a.k.a. left-right). This
% situation arises when a tree is right-heavy, but the right subtree is
% left-heavy. To fix this, we first perform a rotate_right on the right subtree
% to correct the right-heaviness, then rotate_left on our current node.
%
% Result:       The tree is rebalanced
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% PIP               Pointer in the parent node followed to reach current node
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::double_left(TNode<E> *& PIP) {

  this->right->rotate_right(this->right);
  this->rotate_left(PIP);
}

/*-----------------------------------------------------------------------------
% Routine Name: double_right
% File: avl_tree.cpp
%
% Description:  Performs a double right rotation (a.k.a. right-left). This
% situation arises when a tree is left-heavy, but the left subtree is
% right-heavy. To fix this, we first perform a rotate_left on the left subtree
% to correct the left-heaviness, then rotate_right on our current node.
%
% Result:       The tree is rebalanced
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% PIP               Pointer in the parent node followed to reach current node
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::double_right(TNode<E> *& PIP) {

  this->left->rotate_left(this->left);
  this->rotate_right(PIP);
}

/*-----------------------------------------------------------------------------
% Routine Name: set_debug
% File: avl_tree.cpp
%
% Description: Helper method to enable debug mode.
%
% Result:       Debug mode is enabled or disabled
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% option            Value to set the debug static boolean to
-----------------------------------------------------------------------------*/
template <class E>
void Tree<E>::set_debug(bool option) {

  Tree<E>::debug = option;
}

/*-----------------------------------------------------------------------------
% Routine Name: operator <<
% File: avl_tree.cpp
%
% Description: Function used to write information about a TNode
%
% Result:       The node is written out
% Return:       an ostream reference, probably cout
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% stream            Reference to a global ostream object used to print
% node              Reference to a TNode to print
-----------------------------------------------------------------------------*/
template <class E>
std::ostream & operator << (std::ostream & stream, const TNode<E> & node) {

  stream << "at height: :" << node.height << " with balance: " << node.balance
    << " ";
  return stream << node.data << std::endl;
}

/*-----------------------------------------------------------------------------
% Routine Name: Write_AllNodes
% File: avl_tree.cpp
%
% Description: Function used to perform an in-order traversal for writing out
% each node in the tree.
%
% Result:       The Tree is written out
% Return:       an ostream reference, probably cout
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% stream            Reference to a global ostream object used to print
-----------------------------------------------------------------------------*/
template <class E>
std::ostream & TNode<E>::Write_AllNodes(std::ostream & stream) const {

  // Go left
  if(this->left) {
    left->Write_AllNodes(stream);
  }

  // Visit
  stream << *this;

  // Go right
  if(this->right) {
    right->Write_AllNodes(stream);
  }

  return stream;
}

/*-----------------------------------------------------------------------------
% Routine Name: delete_AllNodes
% File: avl_tree.cpp
%
% Description: Function used to perform an post-order traversal for deleting
% the nodes of the tree.
%
% Result:       The Tree is deleted.
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% N/A
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::delete_AllNodes(void) {

  if(this->left) {
    left->delete_AllNodes();
  }

  if(this->right) {
    right->delete_AllNodes();
  }

  delete this;
}

/*-----------------------------------------------------------------------------
% Routine Name: insert
% File: avl_tree.cpp
%
% Description: Recursively searches the tree for the correct spot to insert a
% new TNode
%
% Result:       A new TNode is inserted.
% Return:       true upon successful insertion
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% element           reference to the element to use as the data for the TNode
% PIP               Pointer followed in the parent node to reach the current
-----------------------------------------------------------------------------*/
template <class E>
bool TNode<E>::insert(const E & element, TNode<E> *& PIP) {

  if(Tree<E>::debug) {
    std::cerr << TREE << tree_count << COMPARE << element << AND << data << "]"
      << std::endl;
  }

  // duplicate insertion
  if(element == data) {

    if(Tree<E>::debug) {
      std::cerr << TREE << tree_count << INSERT << element << "]" << std::endl;
    }

    // reassign data field
    data = element;
  } else if(element > data) {

    if(!right) {

      if(Tree<E>::debug) {
        std::cerr << TREE << tree_count << INSERT << element << "]" << std::endl;
      }

      right = new TNode<E>(element, *this);
    } else {

      right->insert(element, right);
    }

  } else {

    if(!left) {

      if(Tree<E>::debug) {
        std::cerr << TREE << tree_count << INSERT << element << "]" << std::endl;
      }

      left = new TNode<E>(element, *this);
    } else {

      left->insert(element, left);
    }
  }

  // Update heights and balances
  SHAB(PIP);
  return true;
}

/*-----------------------------------------------------------------------------
% Routine Name: RARM
% File: avl_tree.cpp
%
% Description: Recursively searches the tree for the predecessor node. Used
% when deleting a TNode with two children
%
% Result:       The calling node is updated with the predecessor node's data
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% target            reference to the TNode to replace the data for
% PIP               Pointer followed in the parent node to reach the current
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::RARM(TNode<E> & target, TNode<E> *& PIP) {

  // Print debug message
  if(Tree<E>::debug) {
    std::cerr << TREE << tree_count << CHECK << data << "]" << std::endl;
  }

  // go right to find pred node
  if(right) {
    right->RARM(target, right);
    PIP = this;
    SHAB(PIP);
  } else {

    // print debug message
    if(Tree<E>::debug) {
      std::cerr << TREE << tree_count << REPLACE << data << "]" << std::endl;
    }

    /*
     * Overwrite output param and reassign pointer
     */
    target.data = data;
    PIP = left;
    delete this;
  }
}

/*-----------------------------------------------------------------------------
% Routine Name: remove
% File: avl_tree.cpp
%
% Description: Recursively searches the tree for the node to delete from the
% tree.
%
% Result:       A TNode is deleted from the Tree
% Return:       true upon successful deletion, false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% elementTNode      reference to the TNode to replace the data for output
%                   parameter updated to send the data back.
% PIP               Pointer followed in the parent node to reach the current
% fromSHB           optional parameter used to determine if we need to call
%                   SHAB.
-----------------------------------------------------------------------------*/
template <class E>
bool TNode<E>::remove(TNode<E> & elementTNode, TNode<E> *& PIP, bool fromSHB) {

  if(Tree<E>::debug) {
    std::cerr << TREE << tree_count << COMPARE << elementTNode.data << AND <<
      data << "]" << std::endl;
  }

  // Found the element
  if(elementTNode.data == data) {

    // Reassign the data
    elementTNode.data = data;

    // Reassign PIP
    if(left && right) {

      // Call RARM
      left->RARM(*this, left);

      if(!fromSHB) {
        SHAB(PIP);
      }
    } else {

      PIP = (left) ? left : right;

      delete this;
    }

    // Successful deletion
    return true;

  } else if(elementTNode.data > data) {
    if(right) {
      bool removed = right->remove(elementTNode, right, fromSHB);

      if(!fromSHB) {
        SHAB(PIP);
      }

      return removed;
    }
  } else {
    if(left) {
      bool removed = left->remove(elementTNode, left, fromSHB);

      if(!fromSHB) {
        SHAB(PIP);
      }

      return removed;
    }
  }

  // Element wasn't found
  return false;
}

/*-----------------------------------------------------------------------------
% Routine Name: lookup
% File: avl_tree.cpp
%
% Description: Looks up an element in the tree and updates the output param.
%
% Result:       An item is looked up and sent back as an output param
% Return:       true for successful lookup, false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% element           reference to the element to find. Output parameter.
-----------------------------------------------------------------------------*/
template <class E>
bool TNode<E>::lookup(E & element) const {

  // Print debug message
  if(Tree<E>::debug) {
    std::cerr << TREE << tree_count << COMPARE << element << AND << data << "]"
      << std::endl;
  }

  // Stop searching
  if(element == data) {

    element = data;
    return true;
  } else if(element > data) {

    // Go right
    if(right) {

      return right->lookup(element);
    }
  } else {

    // Go left
    if(left) {

      return left->lookup(element);
    }
  }

  // Item not found
  return false;
}

/*-----------------------------------------------------------------------------
% Routine Name: SHAB
% File: avl_tree.cpp
%
% Description: Sets the height and balance of the calling node.
%
% Result:       The height and balance is called, and tree is rebalanced
% as needed
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% PIP               Pointer followed in the parent node to reach the current
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::SHAB(TNode<E> *& PIP) {

  // left and right child heights
  int l_height = (left) ? left->height : -1;
  int r_height = (right) ? right->height : -1;

  // Print debug message
  if(Tree<E>::debug) {
    std::cerr << TREE << tree_count << UPDATE << data << "]" << std::endl;
  }

  // Set height
  height = ((l_height > r_height) ? l_height : r_height) + 1;

  // Set balance
  balance = l_height - r_height;

  // Determine which rotations are needed
  if(abs(balance) > THRESHOLD) {

    // Tree is right heavy
    if(balance < 0) {

      // right subtree is left heavy
      if(right->balance > 0) {
        this->double_left(PIP);
      } else {
        this->rotate_left(PIP);
      }
    // Tree is left heavy
    } else if(balance > 0) {

      // left subtree is right heavy
      if(left->balance < 0) {
        this->double_right(PIP);
      } else {
        this->rotate_right(PIP);
      }
    }
  }
}

/*-----------------------------------------------------------------------------
% Routine Name: insert
% File: avl_tree.cpp
%
% Description: Performs first item insertion, or delegates to TNode's insert
% otherwise. Will also check balance to verify that the tree is valid.
%
% Result:       An item is inserted into the tree
% Return:       true for successful insertion.
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% element           reference to the element to find. Output parameter.
-----------------------------------------------------------------------------*/
template <class E>
bool Tree<E>::insert(const E & element) {

  // Check first item insertion
  if(!root) {

    // Print debug message
    if(debug) {
     std::cerr << TREE << tree_count << INSERT << element << "]" << std::endl;
    }

    // Insert root
    root = new TNode<E>(element, *this);
  } else {

    // Have root handle insertions
    root->insert(element, root);
  }

  // Make sure we update all of the heights and balances
  // again
  this->check();
  return true;
}

/*-----------------------------------------------------------------------------
% Routine Name: check
% File: avl_tree.cpp
%
% Description: Calls the TNode check_all function to verify that the tree is
% still balanced
%
% Result:       Tree is rebalanced, if needed
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% N/A
-----------------------------------------------------------------------------*/
template <class E>
void Tree<E>::check(void) {
  if(root) {
    root->check_all();
  }
}

/*-----------------------------------------------------------------------------
% Routine Name: check_all
% File: avl_tree.cpp
%
% Description: Performs a post order traveral to verify that the tree is still
% in balance.
%
% Result:       Tree is rebalanced, if needed
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% N/A
-----------------------------------------------------------------------------*/
template <class E>
void TNode<E>::check_all(void) {

  // post order traversal; go left first
  if(left) {
    left->check_all();
  }

  // Go right next
  if(right) {
    right->check_all();
  }

  // Call SHAB
  TNode<E> *temp = this;
  this->SHAB(temp);
}

/*-----------------------------------------------------------------------------
% Routine Name: lookup
% File: avl_tree.cpp
%
% Description: Calls TNode's lookup to find an element in the Tree
%
% Result:       An item is looked up and sent back as an output param
% Return:       true for successful lookup, false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% element           reference to the element to find. Output parameter.
-----------------------------------------------------------------------------*/
template <class E>
bool Tree<E>::lookup(E & element) const {

  return (root) ? root->lookup(element) : false;
}

/*-----------------------------------------------------------------------------
% Routine Name: is_empty
% File: avl_tree.cpp
%
% Description: Checks if the tree is empty
%
% Result:       The tree is queried to verify if empty
% Return:       true if tree is empty, false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% N/A
-----------------------------------------------------------------------------*/
template <class E>
bool Tree<E>::is_empty(void) const {

  return (occupancy == 0) ? true : false;
}

/*-----------------------------------------------------------------------------
% Routine Name: remove
% File: avl_tree.cpp
%
% Description: Recursively searches the tree for the node to delete from the
% tree.
%
% Result:       A TNode is deleted from the Tree
% Return:       true upon successful deletion, false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% element           element to find in the tree to remove
-----------------------------------------------------------------------------*/
template <class E>
bool Tree<E>::remove(E & element) {

  // Make temp node for traversing the tree
  TNode<E> temp = TNode<E>(element, *this);

  if(root) {

    bool removed = root->remove(temp, root);

    element = temp.data;
    return removed;
  }

  return false;
}

/*-----------------------------------------------------------------------------
% Routine Name: Write
% File: avl_tree.cpp
%
% Description: Writes the information about the tree out for use
%
% Result:       Tree is written out
% Return:       an ostream reference, probably cout
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% stream            Reference to a global ostream object used to print
-----------------------------------------------------------------------------*/
template <class E>
std::ostream & Tree<E>::Write(std::ostream & stream) const {

  stream << "Tree " << tree_count << ":" << std::endl << "occupancy is " <<
    occupancy << " elements." << std::endl;

  return (root) ? root->Write_AllNodes(stream) : stream;
}

/*-----------------------------------------------------------------------------
% Routine Name: Tree(constructor)
% File: avl_tree.cpp
%
% Description: Constructs a tree object and initializes the corresponding
% fields
%
% Result:       A Tree is created
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% is_primitive      checks if the type is a primitive for use with debug
%                   messages
-----------------------------------------------------------------------------*/
template <class E>
Tree<E>::Tree(void) : occupancy(0), root (nullptr) {

  // initialize tree count
  tree_count = ++counter;

  // print debug message
  if(debug) {
    std::cerr << TREE << tree_count << ALLOCATE << std::endl;
  }
}

/*-----------------------------------------------------------------------------
% Routine Name: ~Tree(destructor)
% File: avl_tree.cpp
%
% Description: Destroys a tree object.
%
% Result:       A Tree is deleted
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% N/A
-----------------------------------------------------------------------------*/
template <class E>
Tree<E>::~Tree(void) {

  // print debug message
  if(debug) {
    std::cerr << TREE << tree_count-- << DEALLOCATE << std::endl;
  }

  // Delete all nodes
  if(root) {
    root->delete_AllNodes();
  }
}
