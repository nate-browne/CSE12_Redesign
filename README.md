# Nate's CSE 12 Redesign
## A New Approach to a Basic Data Structures Course

### Introduction
I'm not a professor, but if I ever was teaching a Basic Data Structures course,
this would be it. It's designed as an alternative to [UCSD's current CSE
12](https://www.ucsd.edu/catalog/courses/CSE.html#cse12).

Since it is designed with UCSD in mind, it is written to work in a 10 week
quarter system. It could pretty easily be adapted to work in a semester based
system though; just space stuff out more.

This class will be *intense*. It moves quickly, and has lots of difficult PAs.
Hopefully, with a good tutor squad, this course would still be doable by
students but they'll have to put work in to excel.

Dicussion sections could be used to give extra aid on the PAs, since this class
does not have written assignments.

All are able to modify this and adapt it as you see fit (open source FTW), just
give me credit please and thanks.

### Required Materials
1. Either `clang++` or `g++`
2. `valgrind`/`leaks` (for macOS) and GDB/LLDB (for macOS)

There are Makefiles that are written to work natively with both macOS and with
Linux distributions, so either of those should be used. Windows is **_not
supported_** by this project.

To be explicit, `clang++` and `leaks` are part of macOS already (providing you
have Xcode tools, which if you've tried compiling anything you already have).
MacOS actually aliases `g++` to `clang++`, so you don't even have to type
anything different. On Linux, you'll have to install `g++`, `gdb`, and `valgrind`.

For the sake of clarity, I'll now put links to all of the tools (except `leaks`):
* [valgrind](http://valgrind.org/)
* [GNU compiler project (includes `g++`)](https://gcc.gnu.org/)
* [clang](https://clang.llvm.org/)
* [GDB](https://www.gnu.org/software/gdb/)
* [LLDB](https://lldb.llvm.org/index.html)

For those new to LLDB who have used GDB, this [mapping of commands](https://lldb.llvm.org/use/map.html)
will probably be of use to you.

To be able to use `leaks` properly for macOS, you'll need to run the following
commands:

```sh
cd /usr/local/lib
sudo ln -s /Applications/Xcode.app/Contents/Developer/usr/lib/libLeaksAtExit.dylib
```

Without running these first, you'll run into an error with linking.

The code does not assume IDE support, so something like
[CLion](https://www.jetbrains.com/clion) is *not* recommended. I personally
would stick to either:

* [Vim/gVim](https://www.vim.org/)
* [Visual Studio Code](https://code.visualstudio.com/) (my personal recommendation)
* [Atom](https://atom.io/)

The best two options, in my opinion, are vscode and Atom due to their plugin
support. All you'll need is an appropriate C/C++ plugin (like [this one](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for
vscode or [this one](http://atom-packages.directory/package/atom-clang/) for Atom) and you're set.


### Contact
Send me an email at nbrowne [at] ucsd [dot] edu or at npcompletenate [at] protonmail
[dot] com if you have any suggestions/fixes/other stuff like that.
