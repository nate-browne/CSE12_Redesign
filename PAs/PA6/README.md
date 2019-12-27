# Priority Queues and Heaps (XXX points)
### Due: TBD

### Overview
For your penultimate PA, you'll be implementing a `heap` class for use in the given `priority_queue` class.
Your heap will be a binary heap, so _**do not**_ implement a Fibonacci heap or Binomial heap!

For this assignment, you have a "choose your own adventure" style approach. You can either implement your heap as a tree,
or you can do it with an array. The choice is completely yours to make!

If you choose the tree, you can re-use your `"BST.hpp"` class from the last PA if you'd like to do some more
practice with inheritance, or you can re-write a new tree. If you choose the array option, you're welcome to either
use your `"vector.hpp"` from PA2, or you can use the STL's `<vector>` header.

All of the code you write should go in `heap.hpp`. Do **not** modify `driver.cpp` or `priority_queue.hpp`; if you do, your code **_will not_** work!

#### Compilation and Testing
To compile, use the provided Makefile. If you just want to build the program, run `make build`. If you want to build and run, use `make prog`. For debugging, run `make debug`. For memory leaks, run `make memcheck`.

Like in previous PAs, you're responsible for testing your own code. We provide a driver, but you should also consider unit testing each of your functions to verify and ensure correctness.

#### Turnin
*Instructions coming soon!*

### The Code
Your heap class that you're writing is the implementing data structure for the (given) `priority_queue`. Crucially, your heap must support being used as either a min heap or a max heap. Which one is dependent on the parameter `max` which is passed in from the Priority Queue code.

If you choose to implement your heap using the tree, one option is to inherit from the `BST` class and override appropriate methods (such as the two-parameter `insert`). This will save you a little bit of writing.

Be warned, the tree approach is *notably* more complex than the array based implementation. However, one benefit is that when you print the tree, the logical representation in your head will match the literal representation in the code.
The vector approach, though simpler, does not have the above benefit (making debugging more difficult).

If you pick the vector approach, it would be wise to use *composition* instead of *inheritance*, to make your code easier to reason about.

**This code will work with _any_ datatype (both custom and primative) as long as
it can be compared with both `operator <` and `operator >`, and if it implements
`operator <<` for printing.**

#### The Functions, Described
You have 6 functions to fill out. Be sure to read the comments given in `heap.hpp`, though:
1. ```cpp
   heap(void)
   ```
   * This is your heap constructor. Initialize whatever structure you decide to implement.
2. ```cpp
   ~heap(void)
   ```
   * This is your heap destructor. Clean up whatever you initialize.
3. ```cpp
   void insert(const T & x, bool max = true);
   ```
   * This is your heap's insert method.
   * Remember that in a heap, you insert the new value at the spot where it maintains the *full heap property*, then you adjust the heap via upwards reheaps (a.k.a. bubble up).
4. ```cpp
   void remove(bool max = true);
   ```
   * Remove, but do not return, the element at the top of the heap.
   * Remember that in a heap, you always remove the root but you must replace the root with some other item. This may violate the *heap order property*, so you should adjust the heap via downwards reheaps (a.k.a. trickle down).
   * Keep the given line and put your code **below** it!
5. ```cpp
   const T & view(void) const;
   ```
   * View, but do not remove, the item at the top of the heap.
   * This function, regardless of implementation choice, should be short.
   * Keep the given line and put your code **below** it!
6. ```cpp
   size_t size(void) const;
   ```
   * Return the number of elements in the heap.
   * If you use the BST, you'll have to write a function to count the number of nodes (use a traversal!). If you use the vector (doesn't matter which one), this function will be trivial.

#### Implementation Tips
1. If you choose the tree and decide to inherit, look back
   at the inheritance lecture and your PA5 to see how to do it.
2. If you pick the vector, make sure you remember your formulas for finding children/parents!
3. Don't forget about the [style guide](../../styleguide.md)!

# Good luck! Start Early, Test Often, and Finish Early!
