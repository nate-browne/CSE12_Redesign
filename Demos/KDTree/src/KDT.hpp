#ifndef KDT_HPP
#define KDT_HPP

#include <math.h>     // pow, abs
#include <algorithm>  // sort, max, min
#include <iostream>   // cout, cin, and cerr
#include <limits>     // numeric_limits<type>::max()
#include <vector>     // vector<typename>
#include "BST.hpp"

using namespace std;

class Point {
  private:
    double delta = 0.00005;

  public:

    // x and y point coordinates
    double x, y;

    /**
     * Default constructor: point at (0, 0)
     */
    Point(void) : x(0.0), y(0.0) {}

    /**
     * Constructor that defines point location
     */
    Point(double x, double y) : x(x), y(y) {}

    /**
     * Equals operator
     */
    bool operator==(const Point &other) const {
      return abs(x - other.x) < delta && abs(y - other.y) < delta;
    }

    /**
     * Not-equals operator
     */
    bool operator!=(const Point &other) const {
      return abs(x - other.x) > delta || abs(y - other.y) > delta;
    }

    /**
     * Less than operator
     */
    bool operator<(const Point &other) const {
      cerr << "This operator should not be called, you will need "
        << "check the x and y components each time" << endl;
      return false;
    }

    /**
     * Return the square of the Euclidean distance between two points p1 and p2
     */
    static double squareDistance(const Point &p1, const Point &p2) {
      return pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2);
    }
};

/**
 * Overload the << operator to print out the point information
 */
std::ostream &operator<<(std::ostream &out, const Point &data) {
  out << "(" << data.x << ", " << data.y << ")";
  return out;
}

/**
 * Comparison operator for the x points
 */
bool xLessThan(const Point &p1, const Point &p2) { return p1.x < p2.x; }

/**
 * Comparison operator for the y points
 */
bool yLessThan(const Point &p1, const Point &p2) { return p1.y < p2.y; }

class KDT : public BST<Point> {
  public:

    /**
     * Build up a K-D tree given a vector of points to insert by calling
     * the helper buildSubset method
     */
    virtual unsigned int build(vector<Point> &items) {

      // Get size of vector for function call
      if(items.size()) {
        int num_items = items.size();

        // Recursively build the tree and return the root
        this->root = buildSubset(items, 0, num_items, false);

        // Set the tree height variable
        this->iheight = root->height;
        return this->size();
      }
      return 0;
    }

    /**
     * Find the nearest neighbor to a given point
     */
    virtual iterator findNearestNeighbor(const Point &item) const {

      if(!this->empty()) {
        // Create params to use in the helper function
        BSTNode<Point> *closest;
        double smallest = numeric_limits<double>::max();
        findNNHelper(root, item, &smallest, &closest, false);
        return iterator(closest);
      }
      return this->end();
    }

    /**
     * For the kd-tree, the find method should not be used.  Use the function
     * findNearestNeighbor instead.
     */
    virtual iterator find(const Point &item) const override {
      cerr << "The KD Tree find method should not be called" << endl;
      cerr << "Use findNearestNeighbor instead" << endl;
      return 0;
    }

    /**
     * For the kd-tree, the insert method should not be used.  The tree is
     * built all at once.  There should be no scenario where you add individual
     * points.
     */
    virtual bool insert(const Point &item) override {
      cerr << "The KD Tree insert method should not be called" << endl;
      return false;
    }

  private:

    /**
     * Recursively build up a k-d tree and assign the corresponding fields
     * @param items vector of points to be inserted
     * @param start starting index in the vector to use
     * @param end ending index in the vector to use
     * @param dimension true for y, false for x
     * @return a pointer to a BSTNode
     */
    BSTNode<Point> *buildSubset(vector<Point> items, unsigned int start,
      unsigned int end, bool dimension) {

      // End recursive case check
      if(items.size()) {

        // Step 1: sort on dimension
        if(dimension) {
          stable_sort(items.begin(), items.end(), yLessThan);
        } else {
          stable_sort(items.begin(), items.end(), xLessThan);
        }

        int size = items.size();
        unsigned int median = (size % 2 == 0) ? size / 2 - 1 : size / 2;

        if(!dimension) {
          while(median > start && items[median].x == items[median - 1].x) {
            --median;
          }
        } else {
          while(median > start && items[median].y == items[median - 1].y) {
            --median;
          }
        }

        BSTNode<Point> *ret = new BSTNode<Point>(items[median], isize);

        vector<Point> left(items.begin(), items.begin() + median);
        vector<Point> right(items.begin() + median + 1, items.end());

        ret->left = buildSubset(left, 0, left.size(), !dimension);
        ret->right = buildSubset(right, 0, right.size(), !dimension);

        ret->update_height();

        return ret;
      }
      return nullptr;
    }

    /**
     * Helper method to find the nearest neighbor node and return it as an
     * output parameter
     * @param node pointer to a BSTNode to use as the current
     * @param queryPoint reference to a point object that we're looking for
     * @param smallestSquareDistance pointer to a double for the smallest current distance
     * @param closestPoint pointer to a BSTNode pointer for the closest node so far
     * @param dimension true for y, false for x
     */
    void findNNHelper(BSTNode<Point> *node, const Point & queryPoint,
      double *smallestSquareDistance,
      BSTNode<Point> **closestPoint,
      bool dimension) const {

      // Recursive base case
      if(!node) {
        return;
      }

      // Create local variables for readability
      bool went_left;
      BSTNode<Point> *recurse;

      // Step 1: Recursive calls
      if(!dimension) {
        recurse = (xLessThan(queryPoint, node->data)) ? node->left : node->right;
      } else {
        recurse = (yLessThan(queryPoint, node->data)) ? node->left : node->right;
      }

      went_left = (recurse == node->left) ? true : false;

      // Make our recursive call for both cases
      findNNHelper(recurse, queryPoint, smallestSquareDistance, closestPoint, !dimension);

      // Step 2: distance squared calculation and reassignment
      double curr_dist = Point::squareDistance(node->data, queryPoint);

      if(curr_dist < *smallestSquareDistance) {
        *smallestSquareDistance = curr_dist;
        *closestPoint = node;
      }

      // Step 3: re-evaluate and recurse if needed
      double next_closest = (dimension) ? pow((queryPoint.y - node->data.y), 2) :
        pow((queryPoint.x - node->data.x), 2);

      if(next_closest <= *smallestSquareDistance) {
        BSTNode<Point> *temp = (went_left) ? node->right : node->left;
        findNNHelper(temp, queryPoint, smallestSquareDistance, closestPoint, !dimension);
      }
    }
};

#endif  // KDT_HPP
