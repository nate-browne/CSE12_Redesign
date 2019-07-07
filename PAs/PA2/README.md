# HW2: Vector
## Due: TBD

### Overview
In this PA, you'll be creating your own version of the [vector](http://www.cplusplus.com/reference/vector/vector/?kw=vector) class found in the C++ `stl`. You'll be implementing many of the functions found (see specifics below), and optimally, your vector class should be (mostly) indistinguishable from the C++ built-in one.

#### *Note: If you use the `<vector>` header, you **will** get 0 points!*

Your implementation should go in `vector.hpp`, under the `cse12_ds` namespace. **_From now on, all data structures/ADTs you implement will live in that namespace_**.
This is to prevent conflicts between the `std` namespace data structures/ADTs and ours, since they will have the exact same names as their `std` library equivalents.

#### Compilation and Testing
To compile, use the provided Makefile. If you just want to build the program, run `make build`. If you want to build and run, use `make prog`.

*You are responsible for testing your own program.* We have the driver program available for you to use to assist, but do note that it will be on **you** to make sure that everything works as expected.

It is not mandatory, but you should consider [unit testing](https://en.wikipedia.org/wiki/Unit_testing) to help you verify correctness.

#### Turnin

*Instructions coming soon!*

### The Code
As noted above, you'll be re-implementing the C++ `vector` class. Do note that this means that you **do not** have to do things that the original `vector` class does not do! This will be explained below, but knowing this should simplify your design a bit.

You will have to deal with [exception handling in C++](http://www.cplusplus.com/reference/exception/exception/?kw=exception). It works a lot like how it does in Java or Python, so this shouldn't be too hard to figure out.

We are using [templates](http://www.cplusplus.com/doc/oldtutorial/templates/) here to assist with polymorphic behavior. The link above will help to understand them, but if confused, feel free to refer back to lecture notes, DuckDuckGo for some more explanations, ask the staff, etc.

#### The Functions, Described
*Do note that you don't have to implement them in this order*
1. `vector(void)`
   * This is the constructor.
   * Initialize the three `private` fields of the object
      * set `_size` to `DEFAULT_SIZE`, make an array of size `_size`, and set the number of elements inserted to 0.
2. `~vector(void)`
   * This is the destructor.
   * Delete *all* elements of the vector, then delete the array you created in the constructor (look up how to call the destructor on template parameter objects)
3. `size_t size(void)`
   * This simply returns the number of elements inserted
4. `size_t capacity(void)`
   * Confusingly, this returns the maximum size of the vector's underlying container (i.e. the size of the array)
5. `bool empty(void)`
   * Return `true` if the vector is empty, `false` otherwise
6. `T & operator[](int pos)`
   * Return the element in the vector at position `pos`
   * A value of `pos` that is out of bounds should result in **undefined behavior**
7. `T & at(unsigned int pos)`
   * Does the same thing as above, but if the value of `pos` is invalid, it will throw an `std::out_of_range` exception.
   * Use the error string "Accessing element out of range of vector" in your exception
8. `T & front(void)`
   * Return the element at the front of the vector (i.e. the first one)
   * Using this function on an empty vector should result in **undefined behavior**
9. `T & back(void)`
    * Return the element at the back of the vector (i.e. the last one)
    * Using this function on an empty vector should result in **undefined behavior**
10. `void push_back(const T & elem)`
    * This function adds a new element to the end of the vector.
    * Remember that if the size equals the capacity, you need to regrow your array. Think about what steps this entails.
11. `void pop_back(void)`
    * Remove the last element and **_do not_** return it.
12. `void insert(int position, const T & item)`
    * Insert an element at position `position` in the vector.
    * This will (potentially) involve shifting elements over as well as regrowing the array.
    * Using this function with an invalid `position` should result in **undefined behavior**.
13. `void erase(int position)` and `void erase(int start, int end)`
    * This overloaded function will remove an element from a given position.
    * Note that removing elements other than the back will cause the entire vector to shift things down.
    * The first function removes from one spot, the second removes a range of elements from [start, end).
14. `void clear(void) noexcept`
    * This function clears the entire vector
#### Implementation Tips
1. It may be useful to define your own private helper functions.
2. Most of these functions should be implemented in a single line of code, due to not making guarantees about the parameters.
3. Don't forget to test for memory leaks using `valgrind` or any other memory tool of your choosing.
4. Remember the [style guide](https://nate-browne.github.io/CSE12_Redesign/styleguide.html)! These are easy points to make sure you earn.

# Good luck! Start Early, Test Often, and Finish Early!
