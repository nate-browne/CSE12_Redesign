# Rebalancing BSTs
### Due: TBD

### Overview
**This _will be_ your longest and most difficult PA to date! You have two weeks; don't procrastinate!**

In this PA, you will use the object-oriented principles of encapsulation and inheritance to create a binary search tree as well as an AVL tree. The main bulk of your code will be in `BST.hpp`, with some methods overridden in `AVL.hpp`.

This code make heavy use of some C++ concepts you've probably never seen before, which are explained below:
1. `virtual`.
   * C++, by default, uses static binding. By contrast, Java uses dynamic binding <a href="https://en.wikipedia.org/wiki/Name_binding#Binding_time" target="_blank">(read about them here).</a>
   * Static binding means that the exact function to be run is known at *compile time*.
   * In dynamic binding, at compile time the compiler only knows the *type of the pointer (C++) or reference (Java)* while at runtime it knows the *declared type*. Using Java as a familiar example:
     * ```java
       Weather ref = new Snow();
       ```
       compile time: ref is a `Weather`
       
       run time: ref is a `Snow`
   * The `virtual` keyword changes the binding for the following function from static to dynamic in C++.
     * This is necessary for <a href="https://en.wikipedia.org/wiki/Virtual_function" target="_blank">virtual function run-time polymorphism.</a>
2. `override`
   * Similar to Java's `@Override` annotation, this allows the compiler to emit errors for incorrect function overriding.
3. `typename BST<T>::BSTNode`
   * This is necessary to be able to reference the `protected BSTNode` field from public deriving subclass.
4. Default arguments (see `BST.hpp:42`)
   * This, effectively, provides function overloading. Without the argument supplied, the default one provided is used.
5. `*&` parameters (see `BST.hpp:24`)
   * This allows for the pointer parameter passed in to be modified by reference. Similar to passing a double pointer in to a function, just with cleaner, single pointer syntax.


#### Compilation and Testing
To compile, use the provided Makefile. If you just want to build the program, run `make build`. If you want to build and run, use `make prog`. For debugging, run `make debug`.

Like before, you are responsible for testing your program fully. We provide a driver for you to use, but you still have to verify correctness to ensure a good grade. This time, the driver performs unit testing before getting to the interactive portion.
While these tests aren't totally comprehensive, passing them all will give a good indication of how much progress you've made.

#### Turnin
*Instructions coming soon!*

### The Code
This PA, we're not really emulating the STL very much, instead opting for an implementation more similar to the one in the textbook.

While there is a decent amount of implementation freedom, there are ways to limit the amount of code you'll write total. We'll give hints towards these implementations, so reading the write up in full will be useful.

The `BST` class implements a base BST with no rebalancing at all, used by the AVL tree to implement a lot of basic features.
The code showcases the idea of function overloading by providing public and private overloaded functions. **The public functions should simply delegate to the private ones**. This leads to cleaner, more easy to reason about APIs.

**Make sure you implement every function!** The driver expects them all to be implemented.

**This tree will work with _any_ datatype (both custom and primitive) as long as it can be printed with `operator <<` and implements `operator <` for comparison**. This means that you should only use `operator <` when doing checks, since `operator >` is not expected to be used.
Keep this in mind if you write custom objects to use for testing.

#### The Functions, Described
First, the BST:
1. `void BST<T>::insert(const T & x, BSTNode *& t);`
   * This function inserts value `x` into the tree starting from node `t`.
   * It can be written iteratively or recursively, with the recursive implementation being simpler.
   * Duplicate insertions should be ignored.
2. `void BST<T>::remove(const T & x, BSTNode *& t);`
   * This function removes value `x` from the tree starting from node `t`.
   * It can be written iteratively or recursively, with the recursive implementation being simpler.
   * You will have to handle the case of having two children. Use the predecessor node strategy for data replacement.
     * This can be implemented with two function calls.
3. `typename BST<T>::BSTNode * BST<T>::find_min(BSTNode *t) const;`
   * This function finds the smallest element for the given tree starting from node `t`.
   * It can be written iteratively or recursively. Both implementations are pretty simple and equally as fast when optimized by the compiler.
4. `typename BST<T>::BSTNode * BST<T>::find_max(BSTNode *t) const;`
   * This function finds the largest element for the given tree starting from node `t`.
   * It can be written iteratively or recursively. Both implementations are pretty simple and equally as fast when optimized by the compiler.
5. `bool BST<T>::contains(const T & x, BSTNode *t) const;`
   * This function checks if the tree starting from node `t` contains element `x`.
   * It can be written iteratively or recursively, with the recursive implementation being simpler.
   * _**DO NOT**_ use `operator ==`! (how can you check for equality?)
6. `void BST<T>::print(std::ostream & out, BSTNode *t) const;`
   * This function performs an in-order traversal printing contents of each node.
   * Given to you.
7. `void BST<T::empty(BSTNode *& t);`
   * This function empties the tree starting from node `t`.
   * Use a traversal! (which one?)
   * **Be sure to set `t = nullptr;` at the end!**
8. `typename BST<T>::BSTNode * BST<T>::clone(BSTNode *t) const;`
   * This function makes and returns a clone of the tree node by node starting from node `t`.
   * This function **must be recursive**.
   * Look at the `BSTNode` constructor for hints on what to pass as the 2nd and 3rd actual argument.
9. `BST<T>::BST(void)`
    * Default constructor. Given.
10. `BST<T>::BST(const BST & rhs);`
    * Copy constructor.
    * Should just set `root` to the result of a protected helper function call (which one?)
11. `BST<T>::~BST(void);`
    * Destructor.
    * Should just call a protected helper function (which one?)
12. `typename BST<T>::BSTNode * BST<T>::get_root(void) const;`
    * One line function to return the root
13. `const T & BST<T>::find_min(void) const;`
    * Calls the protected `find_min` and returns the value, or throws an exception if the tree is empty.
    * Given.
14. `const T & BST<T>::find_max(void) const;`
    * Calls the protected `find_max` and returns the value, or throws an exception if the tree is empty.
    * Given.
15. `bool BST<T>::contains(const T & x) const;`
    * Public interface method for `contains`.
    * Should call protected `contains` function starting from `root`.
16. `bool BST<T>::is_empty(void) const`
    * Checks if tree is empty.
    * Easy one-line function.
17. `void BST<T>::print(void) const`
    * Calls the protected `print` function starting from `root`.
18. `void BST<T>::empty(void)`
    * Calls the protected `empty` function starting from `root`.
19. `void BST<T>::insert(const T & x)`
    * Calls the protected `insert` function starting from `root`.
20. `void BST<T>::remove(const T & x)`
    * Calls the protected `remove` function starting from `root`.

Second, the AVL:
1. `int AVL<T>::height(typename BST<T>::BSTNode *t) const;`
   * Calculates the height of the given node `t`.
   * Given.
2. `void AVL<T>::balance(typename BST<T>::BSTNode *& t);`
   * Function that checks the heights and determines if the node `t` needs to be rotated.
   * You should use <a href="https://en.cppreference.com/w/cpp/algorithm/max" target="_blank">`std::max` from the algorithm header</a> to set the height of `t` before returning.
3. `void AVL<T>::rotate_left(typename BST<T>::BSTNode *& t);`
   * Performs a left rotation starting from `t`.
4. `void AVL<T>::double_left(typename BST<T>::BSTNode *& t);`
   * Performs a double left rotation starting from `t`.
   * Should be implemented with two function calls.
5. `void AVL<T>::rotate_right(typename BST<T>::BSTNode *& t);`
   * Performs a right rotation starting from `t`.
6. `void AVL<T>::double_right(typename BST<T>::BSTNode *& t);`
   * Performs a double right rotation starting from `t`.
   * Should be implemented with two function calls.
7. `void AVL<T>::insert(const T & x, typename BST<T>::BSTNode *& t) override;`
   * Override the protected `BST` insert method.
   * Should be identical, just with one extra function call right before the function ends.
8. `void AVL<T>::remove(const T & x, typename BST<T>::BSTNode *& t) override;`
   * Override the protected `BST` remove method.
   * Should be identical, just with one extra function call right before the function ends.
9. `AVL<T>::AVL(void);`
    * Default AVL constructor.
    * Should be identical to the equivalent `BST` constructor, just without the initialization list syntax.
10. `AVL<T>::AVL(const BST<T> & rhs);`
    * Copy AVL constructor.
    * Should be identical to the equivalent `BST` constructor, just without the initialization list syntax.
11. `void AVL<T>::insert(const T & x) override;`
    * Override the public `BST` insert method.
    * Should be identical to the equivalent `BST` method.
12. `void AVL<T>::remove(const T & x) override;`
    * Override the public `BST` remove method.
    * Should be identical to the equivalent `BST` method.
#### Implementation Tips
1. Use the book! The BST chapter has a lot of useful information for both the BST and AVL implementations.
2. For each function, consider edge cases and what should be returned. For example, if the `node` parameter to `contains` is `nullptr`, what do we return?
3. Though iteration or recursion can be used for most of the functions, some functions are more easily implemented via one method or the other. Draw it out by hand to see which you want to do which way.
4. The weird constructor syntax for the `BSTNode` makes writing `clone` a bit easier. Why would that be, and how does that relate to making `clone` recursive?
5. Remember that the predecessor is the largest node in any given node's left subtree.

# Good luck! Start Early, Test Often, and Finish Early!
