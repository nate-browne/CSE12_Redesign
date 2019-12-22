# PA3: Stacks and Queues (XXX points)
## Due: TBD

### Overview
In this PA, you'll be implementing a stack and a queue ADT as discussed in class.
This PA will use the object-oriented principle of [*composition*](https://en.wikipedia.org/wiki/Object_composition) to create these two classes.

You will need to copy over your `vector.hpp` from PA2 for use in both `queue.hpp` and `stack.hpp`, but once you've done that, this PA should be pretty close to done.

### *Note: If you use the `<queue>`, `<vector>`, or `<stack>` header files from the STL, you **will** get 0 points!*

Your implementations should go in `queue.hpp` and `stack.hpp`, under the `cse12_ds` namespace (this has been set up for you).

#### Compilation and Testing
To compile, use the provided Makefile. If you just want to build the program, run `make build`. If you want to build and run, use `make prog`. For debugging, run `make debug`.

Like before, you are responsible for testing your program fully. We provide a driver for you to use, but you still have to verify correctness to ensure a good grade.

#### Turnin
*Instructions coming soon*

### The Code
You will be re-implementing the [queue](https://en.cppreference.com/w/cpp/container/queue) and [stack](https://en.cppreference.com/w/cpp/container/stack) classes from the STL, with nearly the same functionality. You do not have to support all of the constructors or the `swap` functions, though.

#### The Functions, Described
*Do note that you don't have to implement them in this order*

* Stack
  1. `stack(void)`
     * This is a constructor for the stack.
  2. `~stack(void)`
     * This is a destructor for the stack.
  3. `bool empty(void)`
     * Returns `true` if the stack is empty, `false` otherwise.
  4. `size_t size(void)`
     * Returns the number of elements in the stack.
  5. `T & top(void)`
     * Returns the element at the top of the stack.
  6. `void push(const T & item)`
     * Adds a new element to the top of the stack.
  7. `void pop(void)`
     * Removes (but does not return) the element at the top of the stack.
* Queue
  1. `queue(void)`
     * This is a constructor for the queue.
  2. `~queue(void)`
     * This is a destructor for the queue.
  3. `bool empty(void)`
     * Returns `true` if the queue is empty, `false` otherwise.
  4. `size_t size(void)`
     * Returns the number of elements in the queue.
  5. `T & front(void)`
     * Returns the element at the front of the queue.
  6. `T & back(void)`
     * Returns the element at the back of the queue.
  7. `void push(const T & item)`
     * Adds a new element to the end of the queue.
  8. `void pop(void)`
     * Removes (but does not return) the element at the front of the queue.
#### Implementation Tips
1. If your vector class is correct, you should hardly have any code to write here.
2. Remember the differences between LIFO and FIFO, and how those acronyms relate to stacks and queues.
3. It is possible to implement the queue and stack such that their constructor and destructor classes don't do anything. How does this relate to memory management, and how might you achieve this?
  
# Good luck! Start Early, Test Often, and Finish Early!
