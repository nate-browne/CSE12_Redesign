# PA4: Linked Lists (XXX points)
## Due: TBD

### Overview
In this PA, you'll be implementing a linked list data structure which implements the list ADT. Unlike vectors, the linked list implementation does not provide constant time access but does provide constant time insertion to the end and front of the list.

### *Note: If you use the `<list>` header file from the STL, you **will** get 0 points!*

Your implementation should go in `list.hpp` under the `cse12_ds` namespace (this has been set up for you).

#### Compilation and Testing
To compile, use the provided Makefile. If you just want to build the program, run `make build`. If you want to build and run, use `make prog`. For debugging, run `make debug`.

Like before, you are responsible for testing your program fully. We provide a driver for you to use, but you still have to verify correctness to ensure a good grade.

#### Turnin
*Instructions coming soon!*

### The Code
As before, our `list` will closely emulate the STL, just with a few simplifications. We provide a `node` class, a helper function (`start_from_back`), and the completed constructor.

#### The Functions, Described
*Do note that you do not have to implement them in this order.*
1. `~list(void)`
   * This is the destructor.
   * Delete all nodes in the list.
2. `bool empty(void) const`
   * This is an "is empty" check.
   * Should be one line of code.
3. `size_t size(void) const`
   * This should return the number of elements in the list.
   * Should be one line of code.
4. `const T & front(void) const`
   * Return the data held at the first node in the list.
   * Should be one line of code.
5. `const T & back(void) const`
   * Return the data held at the last node in the list.
   * Should be one line of code.
6. `void push_front(const T & val)`
   * Insert `val` into a new node at the front of the list.
     * Don't forget to increment `num_elements`!
   * (An) Edge case: empty list --> what changes?
7. `void push_back(const T & val)`
   * Insert `val` into a new node at the back of the list.
     * Don't forget to increment `num_elements`!
   * (An) Edge case: empty list --> what changes?
8. `void pop_front(void)`
   * Removes the first element from the list.
   * Running this function on an empty list causes **undefined behavior**.
   * (An) Edge case: list is empty after removal
9. `void pop_back(void)`
   * Removes the last element from the list.
   * Running this function on an empty list causes **undefined behavior**.
   * (An) Edge case: list is empty after removal
10. `void insert(const size_t pos, const T & val)`
    * Insert an item **_directly before_** the given `pos` in the list.
      * You should check if it is faster to reach `pos` by going backwards or by going forwards and use the faster option (use a helper function!)
    * If `pos` is not within `[0,size())`, the function has **undefined behavior**.
    * Edge case: inserting at front/back vs inserting everywhere else.
11. `T & erase(const size_t pos)`
    * Removes the element at `pos`.
      * You should check if it is faster to reach `pos` by going backwards or by going forwards and use the faster option (use a helper function!)
    * If `pos` is not within `[0,size())`, the function has **undefined behavior**.
    * If erasing from back, return directly preceeding element's data. Else, return the directly succeeding element's data.
12. `void clear(void) noexcept`
    * Erases all elements from the container. After this call, `size()` shall return 0.

#### Implementation Tips
1. There are a *LOT* of edge cases to consider regarding pointers, so be careful to avoid unexpected segmentation faults.
2. Think carefully about expected behavior of `_front` and `_back` when the list has one element vs multiple elements. How do they differ? How are they the same?
3. `gdb` (or `lldb`) will be your friend for debugging the inevitable segmentation faults you will run into. Use it often!
4. Remember the [style guide](https://nate-browne.github.io/CSE12_Redesign/styleguide.html)! These are easy points to make sure you earn.
5. This is the hardest PA you've had to date; be sure to start early!

# Good luck! Start Early, Test Often, and Finish Early!
