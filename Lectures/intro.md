# Introduction to C++, Java and Basic Runtime Analysis

### Who am I?

![Photo of Instructor](https://s3.amazonaws.com/images.seroundtable.com/t-google-404-1303660172.jpg){.align-center width=25%}
* Put information about yourself (the instructor) here
* Maybe info about where your degrees are from
* Or what you've taught before

#### My Research
* You can remove this section if you're a lecturer or another
non-research faculty.
* Otherwise, you should put what you research about.

#### The Crew
TAs (if applicable):
* Name
* Here
Tutors/IAs/Undergraduate TAs (if applicable):
* Name
* Here

#### What is CSE 12 about?
* The motivation and implementation behind many data structures.
* Building an intuition about what data structure to use for which problem.
* Gaining exposure to new styles of programming and building up your skills as
computer scientists and programmers.

Some advice:
* This class is a **lot** of work.
..* It is fast paced and will keep you quite busy. 
* We're all here to help though!

#### What is CSE 12 _not_ about?
* This class is not a "how to pass a technical interview" class.
..* The information will be helpful for those, but it is not strictly the purpose.
* This class isn't about the proofs of why these data structures work.
..* We will talk a little bit about the math, but not a ton.
..* The details will be CSE 21 and CSE 101 ;)

### Introduction to C++ (from a Java perspective)

* As you all know, this class is taught in C++. Many of you only have Java experience from CSE 8B/11.
* We will be covering many of the similarities and differences between the languages so that you are
able to hit the ground running with these assignments.

* C++ is a procedural, functional, object-oriented, statically typed programming language.
..* Developed by Bjarne Stroustrup in 1985 at Bell Labs
* It is used frequently in desktop application development, game development, animation
(Pixar's tools are built in C++), operating systems, compilers...
* It is a very powerful language, but also a bit less friendly.
..* It's not as friendly as Java, but it's not as raw as C is.

#### The Basics

Here's a hello world program in Java:
```java
public class Hello {
  public static void main(String[] args) {
    System.out.println("Hello world!");
  }
}
```

and here's the equivalent program in C++:
```cpp
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Hello world!" << std::endl;
  return 0;
}
```

What are some similarities?

###### Similarities
1. Both functions are named `main` (this one is trivial).
2. Syntax is relatively similar (semicolons, curly braces, etc).

Differences?

###### Differences
1. `main` returns an int now?
..* That's a bit odd...
2. What's up with that `<<` syntax? And the `std::`?
3. `main` takes another argument?
..* But sometimes it takes no arguments? What's going on?
4. No `class`?
..* C++ **does** have classes, but they're not required.

Just with this, it's possible to reason through some programs and to even write some
basic C++ code. That said, it's best to understand exactly *what* is happening.
Throughout the course, we'll begin to unravel some of the intricasies of C++

#### The Not-So-Basics

###### What's the deal with main?
1. Main now returns an int. Why?
The short reason:
* The return value has to do with UNIX exit codes (you'll learn these in CSE 15L)
* Java doesn't have them because of the JVM providing a layer between the kernel
and your program.
..* You don't need to know what this means yet, just wait till CSE 120.

2. What about the arguments?
* `main` can either take `void` as an argument, (so, nothing), or the arguments seen
* `argc` is the number of command line arguments
* `argv` is an array of `char *` (C style strings) containing the command line arguments.
* These directly correlate to `String[] args` (`argv`) and `args.length` (`argc`)

3. How about the `<<` and `std::`?
* The `<<` will make more sense when we talk about operator overloading soon, and the `std::` will
be explained during week 9.

###### Compilation
* Compiling Java was easy
..* `javac <file>.java`
* Compiling C++ is a bit more annoying
..* Base command is `g++`, but there are a *LOT* of flags.
..* We provide Makefiles with each assignment to make things a bit more easy.

### Basic Runtime Analysis