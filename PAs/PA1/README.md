# HW1: Introduction to C++ (XXX points)
## Due: TBD

### Overview

This PA is meant to introduce the basic concepts of C++ via some easy exercises. None of these are particularly
difficult; the goal is to merely introduce the language in a really simple form for us to build on.

#### Compilation and Testing

We provide a `Makefile` for you to use. To make the base program, type `make test`. You can also type `make run` to both compile
and run the program. The tester is **not** complete; you'll have to add your own test cases in to make sure that your program works.

There are test cases that we do not provide in the tester that we will be running, so be sure to be thorough!

#### Turnin

*Instructions coming soon!*

### The Code

#### Problem 1: GradeAssignment

`std::string GradeAssignment(int score);`

For this problem, your goal is to write a function that, given a score, returns a corresponding string.
The strings are provided in `pa1.hpp`; **any non-exact matches will result in 0 points on that test case.**

Sample Input | Sample Output
:---: | :---:
100 | "Perfect score!"

#### Problem 2: ReplaceLetter

`std::string ReplaceLetter(const std::string & to_replace, const char replacee, const char replacer);`

For this problem, your goal is to write a function that takes a string and returns a different string where
each occurence of the `replacee` char in the original string is replaced by the `replacer`.

Sample Input | Sample Output
:---: | :---:
"Hello there", 'e', 'x' | "Hxllo thxrx"
"Sup", 'e', 'q' | "Sup"

#### Problem 3: AverageScore

`double AverageScore(const double scores[], int num_elements);`

For this problem, you are to compute the average of the scores array and return it.
*Note: C-style arrays (so not `std::array`) do not track their own length, which is what `num_elements` is for*.

Sample Input | Sample Output
:---: | :---:
[10, 3, 8, 4, 9], 5 | 6.8