# How to use Other People's Code
### An Introduction to Libraries

All quarter, we've implemented our own takes on a lot of data structures.

Most times, it is advisable **not** to create your own, instead opting for a library implementation.

Today, we'll cover how to use different libraries in C++, as well as talk a bit about other languages'
libraries.

## Libraries
Nearly every language has some sort of standard library. Here are a few examples:

* C
  * [libc](https://www.gnu.org/software/libc/)
* C++
  * [C++ standard template library (STL)](https://en.cppreference.com/w/cpp)
* Java
  * [Java Standard Library](https://docs.oracle.com/javase/8/docs/api/)
* Python
  * [Python Standard Library](https://docs.python.org/3/)
* Rust
  * [Rust Standard Library](https://doc.rust-lang.org/std/)
* Haskell
  * [Hoogle](https://hoogle.haskell.org/)
* OCaml
  * [OCaml Standard Library](https://caml.inria.fr/pub/docs/manual-ocaml/libref/)

Most languages also include specialty libraries for things like GUI development, databases,
web development, and more.

Here is a step-by-step guide to using libraries:

1. **Formalize the problem that you want to solve**
   * Are you trying to build a web app? Do you need to do something involving multithreading?
   * By asking yourself what your objective is, you can better search for the library you need.
2. **Search for a library that matches what you want**
   * Github, Stack Overflow, forum posts, and more can help you track down the right library for your project.
3. **Figure out how to install**
   * Does your library come preinstalled? Do you need to use a package manager (e.g. `pip`, `cargo`, `homebrew`, etc)?
   * You cannot use a library unless you know how to get it on your machine!
4. **Figure out how to import it into your code**
   * Is it a C/C++ header file that you include with a `#include` directive?
     * Note for these: you usually have to compile with the `-I` flag in your compiler to use a separate include path
   * Is it a Java package you need to add to your `-classpath`?
   * Does your language have special `import` syntax?
5. **Read the documentation to see how best to use the code**
   * Often, the documentation comes with examples on how to use the library best!
6. **Use the library**
   * Use this library to solve your problem!
7. **Figure out how to compile/run your code**
   * You may need new compiler options or may need to tweak your runtime configuration to allow for new libraries.
8. **Figure out how to package up your code** *optional: needed if creating an app*
   * If you want other people to use your code, you'll need them to be able to run it the same as you.
   * Maybe your language of choice has a packaging system (like Java's `JAR` format), or maybe you can create install scripts!

## Example: C++ `boost`

The [`boost C++ library`](https://www.boost.org/) is a large, open-source project providing TONS of things to C++ that aren't already there.

Some features from `boost` have become popular enough to be adapted into the main C++ STL!

We will now show an example of how to use `boost` for a non-trivial project (that you will implement from scratch in CSE 100): [Six Degrees of Kevin Bacon](https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon)

1. Formalize the problem
   * At its core, the problem boils down to a graph search. If each actor is a node, we want to find the "Bacon number" (i.e. number of hops to Kevin Bacon) for each one.
2. Search for a library
   * Conviently, `boost` has a section titled the `Boost Graph Library` which can help us with this task.
3. Figure out how to install
   * On macOS, we can use Homebrew by typing `brew install boost`
4. Figure out how to import
   * Since `boost` is a C++ header only library, we don't have to do any custom builds. All we need to do is add an `include` statement, and add it to our buildpath when compiling.
5. Read the documentation
   * [Here it is!](https://www.boost.org/doc/libs/1_72_0/libs/graph/doc/table_of_contents.html)
6. Use the library
   * Instead of subjecting you to watching me type, I've instead linked to a completed project for this. You can find it [here](./lecturematerials/kevinbacon)
7. Figure out how to compile
   * This is given in the Makefile for this project!

That's all folks! Next time, we begin our [review](./review.md).

[back](../lectures.md)
