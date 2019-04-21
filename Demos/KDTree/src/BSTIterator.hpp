#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP

#include <iterator>
#include <list>

#include "BSTNode.hpp"

using namespace std;

template <typename Data>
class BSTIterator : public iterator<input_iterator_tag, Data> {
  private:

    BSTNode<Data> *curr; // BSTNode pointer used to grab values

  public:

    /**
     * Constructor.  Use the argument to initialize the current BSTNode
     * in this BSTIterator.
     */
    BSTIterator(BSTNode<Data> *curr) {
      this->curr = curr;
    }

    /**
     * Overload the dereference operator to retrieve the data
     * @return the data at the current node
     */
    Data operator*() const {
      return curr->data;
    }

    /**
     * Overload the pre-increment operator
     * @return a reference to the current iterator after being moved.
     */
    BSTIterator<Data>& operator++() {
      curr = curr->successor();
      return *this;
    }

    /**
     * Overload the post-increment operator
     * @return the iterator before being incremented
     */
    BSTIterator<Data> operator++(int) {
      BSTIterator before = BSTIterator(curr);
      ++(*this);
      return before;
    }

    /**
     * Overload the equality test operator to do BSTNode comparison.
     * @param other reference to the other iterator to check against
     * @return true if nodes are the same, false otherwise
     */
    bool operator==(BSTIterator<Data> const & other) const {
      return curr == other.curr;
    }

    /**
     * Overload the inequality test operator to do BSTNode comparison.
     * @param other reference to the other iterator to check against
     * @return false if nodes are the same, true otherwise
     */
    bool operator!=(BSTIterator<Data> const & other) const {
      return curr != other.curr;
    }
};

#endif  // BSTITERATOR_HPP
