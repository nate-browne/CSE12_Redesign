# Linked Lists
### Chapter 3 of _Data Structures and Algorithm Analysis in C++_

![linkedlist](../images/linkedlist.gif)

## The Motivation

We discussed the List ADT and how that can be used similarly to an array when we talked about [vectors](./arraylists_vectors.md), but there is a major flaw with vectors that we would like to resolve.

Insertion into an arbitrary spot of a vector takes a _considerable_ amount of time. Why is this?
<!-- reason: have to shift each element down and potentially resize the entire backing array-->

This lecture, we'll take a look at another data structure used for implementing the List ADT and see how it differs from the vector implementation.

## Linked Lists

At its core, a linked list is a sequence of connected node objects, each containing some sort of data item (whatever that may be). Depending on the type of list, the nodes may look slightly differently.

The list may contain either (or both) a pointer to the front (head) and a pointer to the end (tail/back) of the list, though commonly lists contain both head and tail pointers for reasons of speed.

### Singly-Linked
In this list, each node contains a pointer only to the next node, with the last node pointing to NULL.

This is the simplest type of linked list, and it only provides one way traversal through the list.

### Doubly-Linked
In this list, each node contains a pointer to both the previous node as well as the next node. The head node's previous pointer points to NULL, as does the tail node's next pointer.

<br>
There are other kinds of specialty lists, too:
<br><br>

### Circular Linked Lists
These can be either singly- or doubly-linked, but the idea is that no pointers point to NULL.

Instead, we have a circle being formed where following going to the tail and following the next pointer takes you back to the head of the list.

### Skip Lists
Technically, these aren't linked lists; they're more like cousins of linked lists.

They rely on probability to provide better than linear time lookup and insertion to any spot in the list.

You can read more about them <a href="https://en.wikipedia.org/wiki/Skip_list" target="_blank">here</a>


## Implementation
Let's look at implementing a simple singly-linked list class in C++ that will only hold integers, starting with the `node` class.

```cpp
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class node {
 public:
  node *next;
  int data;
  node(const int data) : next(nullptr) {
    this->data = data;
  }
  ~node(void) { }
};

.
.
.

#endif
```
There's not much to note here; the class does very little.

However, notice that the fields are public. How else could we have done this to better have provided <a href="https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)" target="_blank">encapsulation?</a>

Next, the list itself:

```cpp
.
.
.

class list {
  node *_front;
  size_t num_elements;
 public:
  list(void) : _front(nullptr), num_elements(0) { }

  ~list(void) {
    // destructor implementation
  }
  .
  .
  .
  bool empty(void) const {
    return this->size() == 0;
  }

  size_t size(void) const {
    return this->num_elements;
  }

  int front(void) const {
    return this->_front->data;
  }

  void push_front(const int val) {
    node *tmp = new node(val);

    if(this->empty())
      this->_front = tmp;
    else {
      // integrate the new node into the list (how?)
    }
    ++num_elements;
  }

  void push_back(const int val) {
    node *tmp = new node(val);
    node *walker = this->_front;
    if(this->empty())
      this->_front = tmp;
    else {
      while(walker->next) walker = walker->next;
      walker->next = tmp;
    }
  }

  void pop_front(void) {
    node *tmp = this->_front;
    this->_front = this->_front->next;
    delete tmp;
    --num_elements;
    if(!this->empty()) this->_front->pre = nullptr;
    // why is the above line necessary?
  }
  .
  .
  .
};

#endif

```

This isn't the complete implementation, but it gives us enough to talk about.

First, why so many size checks?
<!-- answer: because null pointer problems are easy to make -->

Second, is it supposed to look that short?
<!-- answer: for singly-linked with only a head pointer, yes! for other types, no -->

Your PA will be the creation of a doubly-linked list with a front and back pointer.

Your PA's implementation will also feature templates again, so you can hold anything instead of just integers.

That's all folks! Next time, [Introduction to Hashing](./hashing.md)

[back](../lectures.md)
