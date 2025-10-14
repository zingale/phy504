***********
Computation
***********

Computers essentially do 2 things:

* Store information

* Operate on this information

Computers are very good at repeating the same task over and over again.

Our goal is to learn how to write programs to automate operations on files (via the Unix shell)
and manage data / do numerical calculations (via C++).

Limitations
===========

Computers have a finite amount of memory and we want our answers in a
reasonable amount of time.  This means that we will need to make
approximations in a lot of our work---a great example is storing real
numbers.  You cannot store the infinite real numbers in [0, 1] with a
finite amount of memory.  So computers will approximate how real
numbers are stored---we will learn about this format shortly.

Languages
=========

In physics and astronomy, a wide range of programming languages are commonly used.
You can implement any algorithm in any of these languages, but some make it easier than others.

High-level languages have extensive libraries that implement
commonly-used features that you can rely on when writing your code,
saving you time.

There are many ways we can categorize languages (and there are
exceptions to most of what I write here):

* Compiled vs. interpreted

  * A compiled language is passed through a program called a
    *compiler* that translates the human-readable source code into
    instructions that are native to the CPU in your computer.

    Examples include: C, C++, and Fortran

  * An interpreted language is processed a runtime, by running the
    program through an `interpreter <https://en.wikipedia.org/wiki/Interpreter_(computing)#Compilers_versus_interpreters>`_.

    Examples include: python, ruby, mathlab

Generally speaking, compiled languages generate faster code, but
interpreted language can be easier to program in.

* Dynamic vs. static typing

  When we work with data, we are going to store it in variables with a
  descriptive name, and then refer to that name throughout the program
  to access the data.

  * Dynamically typed languages do not require us to specify up front
    what type of data we are going to store in a variable.  It is
    inferred at runtime.

    This can give a lot of flexibility to codes.

  * Statically typed languages require you to specify up front what
    type of data will be stored in a variable.

    This can allow the compiler to optimize the code.

Why C++?
========

This course aims to teach a compiled language, and traditionally,
Fortran and/or C++ are taught.

We will focus only on C++

C++ is:

* a modern compiled language

* updated with new features frequently (currently a 3-year cycle)

* used extensively in physics (in particular in high-energy physics
  and increasingly in high-performance computing)

* versatile

* widely used outside of academic research environments---this means
  that you can take your C++ skills to industry jobs if desired


