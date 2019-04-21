# Introduction to C++, Java and Basic Runtime Analysis

Who am I?

![Photo of Instructor](https://s3.amazonaws.com/images.seroundtable.com/t-google-404-1303660172.jpg)
* Put information about yourself (the instructor) here
* Maybe info about where your degrees are from
* Or what you've taught before

My Research
* You can remove this section if you're a lecturer or another
non-research faculty.
* Otherwise, you should put what you research about.

The Crew
TAs (if applicable):
* Name
* Here
Tutors/IAs/Undergraduate TAs (if applicable):
* Name
* Here

What is CSE 12 about?
* The motivation and implementation behind many data structures.
* Building an intuition about what data structure to use for which problem.
* Gaining exposure to new styles of programming and building up your skills as
computer scientists and programmers.

Some advice:
* This class is a **lot** of work.
  - It is fast paced and will keep you quite busy. 
* We're all here to help though!

What is CSE 12 _not_ about?
* This class is not a "how to pass a technical interview" class.
  - The information will be helpful for those, but it is not strictly the purpose.
* This class isn't about the proofs of why these data structures work.
  - We will talk a little bit about the math, but not a ton.
  - The details will be CSE 21 and CSE 101 ;)

## Introduction to C++ (from a Java perspective)

* As you all know, this class is taught in C++. Many of you only have Java experience from CSE 8B/11.
* We will be covering many of the similarities and differences between the languages so that you are
able to hit the ground running with these assignments.

* C++ is a procedural, functional, object-oriented, statically typed programming language.
  - Developed by Bjarne Stroustrup in 1985 at Bell Labs
* It is used frequently in desktop application development, game development, animation
(Pixar's tools are built in C++), operating systems, compilers...
* It is a very powerful language, but also a bit less friendly.
  - It's not as friendly as Java, but it's not as raw as C is.

The Basics

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

Similarities:
1. Both functions are named `main` (this one is trivial).
2. Syntax is relatively similar (semicolons, curly braces, etc).

Differences?

Differences:
1. `main` returns an int now?
 - That's a bit odd...
2. What's up with that `<<` syntax? And the `std::`?
3. `main` takes another argument?
  - But sometimes it takes no arguments? What's going on?
4. No `class`?
  - C++ **does** have classes, but they're not required.

Just with this, it's possible to reason through some programs and to even write some
basic C++ code. That said, it's best to understand exactly *what* is happening.
Throughout the course, we'll begin to unravel some of the intricasies of C++

The Not-So-Basics

What's the deal with main?
1. Main now returns an int. Why?
The short reason:
* The return value has to do with UNIX exit codes (you'll learn these in CSE 15L)
* Java doesn't have them because of the JVM providing a layer between the kernel
and your program.
  - You don't need to know what this means yet, just wait till CSE 120.

2. What about the arguments?
* `main` can either take `void` as an argument, (so, nothing), or the arguments seen
* `argc` is the number of command line arguments
* `argv` is an array of `char *` (C style strings) containing the command line arguments.
* These directly correlate to `String[] args` (`argv`) and `args.length` (`argc`)

3. How about the `<<` and `std::`?
* The `<<` will make more sense when we talk about operator overloading soon, and the `std::` will
be explained during week 9.

Compilation:
* Compiling Java was easy
  - `javac <file>.java`
* Compiling C++ is a bit more annoying
  - Base command is `g++`, but there are a *LOT* of flags.
  - We provide Makefiles with each assignment to make things a bit more easy.

## Basic Runtime Analysis

How do we quantify how long our programs take to run and how much space they take up?

* We can never predict the **absolute** run time and space taken up due to differences in hardware,
programming language used to implement the algo, quality of the operating system, other CPU tasks, etc.

Solution: Quantify our algorithm speed and space in terms of *abstract operations*

*Note: We won't get into the details (I'll leave that for CSE 21 and 101) but this will be a quick and dirty intro.*
*In general, we will talk about the average case upper bound (aka big O), but other measures exist.*

Here's a table to build intuition about kinds of runtime:

Adjective | O-notation | Sample operation
:---: | :---: | :---:
constant | O(1) | adding two `int` values
logarithmic | O(log n) | binary search
linear | O(n) | iterating through an array
logarithmic linear | O(n log n) | merge sort
quadratic | O(n<sup>2</sup>) | bubble sort
cubic | O(n<sup>3</sup>) | naïve matrix multiplication
exponential | O(x<sup>n</sup>), for x > 1 | naïve Fibonacci is ~2<sup>n</sup>
just no | O(n<sup>n</sup>) | ??? I don't even have an example

Here's a table to build intuition in concrete units of time:

F(n) | n = 256 | n = 1024 | n = 1,048,576
:---: | :---: | :---: | :---:
1 | 1 µsec | 1 µsec | 1 µsec
log<sub>2</sub>n | 8 µsec | 10 µsec | 20 µsec
n | 256 µsec | 1.02 ms | 1.05 sec
n log<sub>2</sub>n | 2.05 ms | 10.2 ms | 21 sec
n<sup>2</sup> | 65.5 ms | 1.05 sec | 1.8 weeks
n<sup>3</sup> | 16.8 sec | 17.9 min | 36,559 years
2<sup>n</sup> | 3.7x10<sup>63</sup> years | 5.7x10<sup>294</sup> years | 2.1x10<sup>315639</sup> years

Calculating Runtime:
1. Sum up the operation in terms of how much time each step takes
  * This can be done by figuring out what happens to the output as the input increases
  * Better techniques for this will be taught in other courses (Master's Theorem, Recurrences, etc.)
2. Largest term dominates
3. Drop any constants

Example:
```cpp
int errogate(int n) {
  int sum = 0;
  for(int i = 0; i < n; ++i) {
    sum += i;
  }
  std::cout << "sum is " << sum << std::endl;
  return sum;
}
```
First line is initialization, which is constant time.
Second line starts a loop that will run for `n` number of times.
Third line does integer addition, which is constant time.
Fifth line prints to the screen, which we'll say is constant time.
Last line returns the value, another constant time operation.

Total runtime: O(1) + O(n) + O(1) + O(1) + O(1) = O(n) = linear time

What about this one?
```cpp
int errogate(int n) {
  int sum = 0;
  for(int i = 0; i < n; ++i) {
    sum += i;
  }
  for(int i = 1; i <= n; ++i) {
    sum *= i;
  }
  std::cout << "sum is " << sum << std::endl;
  return sum;
}
```
Total runtime: O(1) + O(n) + O(n) + O(1) + O(1) + O(1) = O(2n) = O(n) = linear time

So, do problems with the same big-O runtime take the same amount of time?

Try this one on your own:
```cpp
int mystery(int n) {
  int count;
  for(int i = 1; i <= n; i *= 2) {
    for(int j = 0; j < n; j++) {
      count++;
    }
  }
  std::cout << count << std::endl;
}
```
[back](../lectures.md)
<!--- note: answer should be O(n log n) --->