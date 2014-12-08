TheoryCalc v2.0
===============

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

This calculator has two modes: Recursive and PDA. With the
recursive option selected, you will input two decimal numbers
when prompted after choosing your operation. In the PDA option,
type an input string in the format '1...101...10', where '1...1' can
be any number of '1s'. Note that a zero follows both series of 1s. The
number of 1s represent a decimal number that will be operated upon in
the function (i.e: if you selected addition, the string '1101110'
represents '2 + 3 ', and the function would return the answer '11111',
or '5'.

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


Version
-------

> v2.0
Working PDA logic. Can choose between PDA and Recursive methods to 
solve simple mathematical operations. The addition of two classes,
'state' and 'pushdown', enable this new feature. 

> v1.0
Working calculator that returns number of recursions as well as the
answer. The recursion counts will be used in future calculations and
proofs on Computational Theory concepts. 