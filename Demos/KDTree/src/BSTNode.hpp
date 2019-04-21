#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iomanip>
#include <iostream>

using namespace std;

#define THRESHOLD 1

template <typename Data>
class BSTNode {
  public:

    int height, balance; // height and balance of the node
    BSTNode(const Data &, BSTNode<Data> &); // constructor called from tree code
    BSTNode(const Data &, unsigned int &); // constructor called from BSTNode code
    unsigned int & occupancy; // reference to the BST occupancy
    BSTNode<Data> *left, *right, *parent; // pointers to the relative nodes
    const Data data;  // the Data in this node.

    /**
     * Destructor that simply decrements occupancy (no dynamic memory allocated)
     */
    ~BSTNode(void) {
      --occupancy;
    }

    /**
     * Iteratively insert a new element into the Tree
     * @param d data to be inserted
     * @param parent pointer in parent node used to reach current node
     * @return true on successful insertion, false otherwise (duplicate)
     */
    bool insert(const Data & d) {

      // Create a temp node pointer for traversal
      BSTNode *curr = this;

      bool result;

      while(true) {

        // Duplicate insertion
        if(!(d < curr->data) && !(curr->data < d)) {
          return false;
        }

        // New item is smaller than current
        if(d < curr->data) {
          if(curr->left) {
            curr = curr->left;

          // insert new item since left is null
          } else {
            curr->left = new BSTNode<Data>(d, *curr);
            curr->left->parent = curr;
            curr = curr->left;
            result = true;
            break;
          }

        // new item is larger than current
        } else {
          if(curr->right) {
            curr = curr->right;

          // insert new item since right is null
          } else {
            curr->right = new BSTNode<Data>(d, *curr);
            curr->right->parent = curr;
            curr = curr->right;
            result = true;
            break;
          }
        }
      }

    // update heights and balances
    while(curr->parent != nullptr) {
      BSTNode *tmp = curr->parent;
      tmp->update_height();
      curr = tmp;
    }

    return result;
  }

    /**
     * Set heights and balances of the current node
     */
    void update_height(void) {

      // Grab heights
      int l_height = (left) ? left->height : 0;
      int r_height = (right) ? right->height : 0;

      // Set current node's height
      height = ((l_height > r_height) ? l_height : r_height) + 1;

      // Set balance
      balance = r_height - l_height;
    }

    /**
     * Find the successor node to the given node
     * @return pointer to the successor node of our current node, or null
     */
    BSTNode<Data>* successor(void) {

      // temp node pointer for iteration

      BSTNode *temp = this;

      // If we have a right child, go right once then all the way left to get
      // to the successor
      if(temp->right) {
        temp = temp->right;

        while(temp->left) {
          temp = temp->left;
        }
        return temp;

      // If our parent has a left child, go up the tree until the parent's
      // left equals the temp node and return the parent
      } else if(temp->parent->left) {

        while(temp->parent->left != temp) {
          if(!temp->parent) {

            return nullptr;
          }
          temp = temp->parent;
        }
        return temp->parent;

      // No successor node available
      } else {
        return nullptr;
      }
    }

    /**
     * Recursive post-order traversal to delete all nodes
     */
    void delete_all(void) {
      if(left) {
          left->delete_all();
      }

      if(right) {
          right->delete_all();
      }

      delete this;
    }
};

/**
 * Constructor called by the BSTNode insert
 * @param d data to be inserted
 * @param par reference to the calling BSTNode
 */
template <typename Data>
BSTNode<Data>::BSTNode(const Data & d, BSTNode<Data> & par) : occupancy(par.occupancy), data(d) {
  left = right = parent = nullptr;
  balance = 0;
  height = 1;
  ++occupancy;
}

/**
 * Constructor with the non recursive insert called from the tree
 * @param d data to be inserted
 * @param tree_occupancy reference to the tree occupancy for incrementing
 */
template <typename Data>
BSTNode<Data>::BSTNode(const Data & d, unsigned int & tree_occupancy) : occupancy(tree_occupancy), data(d) {
  left = right = parent = nullptr;
  balance = 0;
  height = 1;
  ++occupancy;
}

/**
 * Overload operator << to print the node's information out to an ostream
 * @param stm reference to the stream to print to
 * @param n reference to the node to print
 * @return a reference to an ostream operator
 */
template <typename Data>
ostream &operator<<(ostream &stm, const BSTNode<Data> &n) {
  stm << '[';
  stm << setw(10) << &n;                  // address of the BSTNode
  stm << "; p:" << setw(10) << n.parent;  // address of its parent
  stm << "; l:" << setw(10) << n.left;    // address of its left child
  stm << "; r:" << setw(10) << n.right;   // address of its right child
  stm << "; d:" << n.data;                // its data field
  stm << ']';
  return stm;
}

#endif  // BSTNODE_HPP
