#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTIterator.hpp"
#include "BSTNode.hpp"

using namespace std;

template <typename Data>
class BST {
  protected:

    BSTNode<Data> *root; // Pointer to the root node
    friend class BSTNode<Data>; // Give BSTNode access to private fields

    unsigned int isize; // Number of elements

    unsigned int iheight; // Height of the BST (equal to height of the root)

  public:

    // define iterator as an aliased typename for BSTIterator<Data>.
    typedef BSTIterator<Data> iterator;

    /**
     * Default constructor. Initialize an empty BST.
     */
    BST(void) : root(nullptr), isize(0), iheight(0) {}

    /**
     * Default destructor. Delete every node in this BST recursively.
     */
    virtual ~BST(void) {

      // Delete all of the nodes recursively
      if(root) {
        root->delete_all();
      }
    }

    /**
     * Insert element into the BST
     * @param item reference to the element to be inserted
     * @return true if inserted, false if item is a duplicate
     */
    virtual bool insert(const Data & item) {

      bool result;

      // First element insertion
      if(!root) {

        root = new BSTNode<Data>(item, isize);
        result = true;
      } else {

        // For all other elements, let the root node handle insertion
        result = root->insert(item);
      }

      // Reassign the height of the tree
      iheight = root ? root->height : -1;
      return result;
    }

    /**
     * Find a Data item in the BST.
     * @param item reference to the data item to find in the BST
     * @return an iterator to the node containing the data
     */
    virtual iterator find(const Data & item) const {

      if(root) {

        // Temp node pointer for traversal
        BSTNode<Data> *temp = root;

        while(true) {

          // Element was found
          if(!(temp->data < item) && !(item < temp->data)) {
            return iterator(temp);
          }

          // The item to find is smaller than the current
          if(item < temp->data) {

            if(temp->left)
              temp = temp->left;
            else
              break;

          // The item to find is larger than the current
          } else if(temp->data < item) {

            if(temp->right)
              temp = temp->right;
            else
              break;
          }
        }
      }

      // Item wasn't found
      return this->end();
    }

    /**
     * Return the number of items currently in the BST.
     * @return the number of items
     */
    unsigned int size(void) const {
      return isize;
    }

    /**
     * Returns the height of the BST
     * @returns the height variable set earlier.
     */
    unsigned int height(void) const {
      return iheight;
    }

    /**
     * Check if the tree is empty
     * @return true if empty, false otherwise
     */
    bool empty(void) const {
      return root == nullptr;
    }

    /**
     * Return an iterator pointing to the first item in the BST (not the root).
     * @return an iterator to the first element in the BST
     */
    iterator begin(void) const {
      BSTNode<Data> *temp = root;
      return iterator(first(temp));
    }

    /**
     * Return an iterator pointing past the last item in the BST.
     */
    iterator end(void) const {
      return typename BST<Data>::iterator(nullptr);
    }

    /**
     * Perform an inorder traversal of this BST.
     */
    void inorder(void) const {
      inorder(root);
    }

  private:

    /**
     * Helper method for a recursive in-order traversal
     * @param node pointer to a BSTNode to print
     */
    static void inorder(BSTNode<Data> *node) {
      if(!node) {
        return;
      }

      inorder(node->left);

      cout << node->data << endl;

      inorder(node->right);
    }

    /**
     * Find the first element of the BST
     */
    static BSTNode<Data> *first(BSTNode<Data> *curr) {
      if(!curr) {
        return nullptr;
      }

      while(curr->left) {
        curr = curr->left;
      }
      return curr;
    }
};

#endif  // BST_HPP
