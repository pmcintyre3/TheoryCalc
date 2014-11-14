TheoryCalc
==========

Author: Phillip A McIntyre Jr.


Description
-----------

TheoryCalc is a recursive, integer calculator. It is also 
a tool designed to show how integer operations can be proven 
to be context-free, Turing-decidable, Turing-Recognizable, 
and Co-Turing-Recognizable, among other things.

We will apply theorems and lemmas in accordance to Michael 
Sipser's Theory of Computation, 2nd edition textbook used in
the University of Georgia's CSCI 2670 - Theory of Computation
class to prove these properties.


Compile
-------

The makefile provided will compile the program. To compile, type
the following into the commandline:

    $ make calc

This will compile 'calculator.cpp' and 'main.cpp' into object files,
and then link them into an excecutable.

* Typing 'make' will also do the same thing.


Run
---

To run the program, you must compile first. After compiling, type the
following into the commandline:
 
    $ ./calc