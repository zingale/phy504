******************
Aside Unit Testing
******************

As we write increasingly complex codes, we want some way to automate
testing to ensure that our changes don't break the functionality.

There are a wide variety of tests for general codes (the Wikipedia
`software testing <https://en.wikipedia.org/wiki/Software_testing>`_
page gives a good overview:

* *unit testing* : for each of your functions, you provide one or more
  tests that exercise that function alone, ensuring that it gives the
  expected result.

* *integration testing* : you test the several pieces of the program
  or the entire program interacting.  Since unit tests are done in isolation,
  integration tests will catch issues in how the different functions work
  together.

* *regression testing* : you store a "correct answer" from your code and
  you run the code regularly to see if any changes have unexpectedly
  changed the answer.

For numerical algorithms, we also can discuss:

* *convergence testing* : some algorithms have a formal order of
  accuracy, For instance, our Euler method for integrating the orbits
  is first-order accurate in time, but the RK2 algorithm in your
  homework is second-order accurate in time.  In convergence testing
  you varying the space or time resolution and see if you get the
  expected convergence.

* *verification* and *validation* : verification asks the question "am
  I solving the equations correctly?", while validation asks "am I
  solving the right equations to begin with?"  For verification, one
  can compare to known analytic solutions of the set of equations you
  are solving.  For validation, you will typically want to compare to
  experiments to see if you are appropriately modeling all of the
  physics you need.


Unit tests for ``Vector2d``
===========================

We can use the basic ``assert`` statement together with a makefile target to automate testing.

We'll do this with our ``Vector2d`` class.

The basic structure we will use is:

.. code:: c++

   int main() {

       // create some vectors v1 and v2

       // do some operations on v1 and v2

       // assert the result

   }

Ideally, we'd like to be able to capture the success of our test in a
Bash script, so let's start by checking what the return value of a
program that failed an ``assert`` is


Consider the following:

.. code:: c++

   #include <cassert>

   int main() {

      assert(false);

   }


Let's build and run that, and then check the return code via:

.. prompt:: bash

   echo $?

On my machine, I get ``134``, but the actual code may vary depending
on the compiler and OS.  The key however is that it is non-zero.  This
means that we can test for a non-zero return in a script.

Comparing vectors
=================

To make life easier, we'd like to be able to check if two vectors are
equal, using ``==``, and not equal, using ``!=``.

So we want to overload those operators and add them to our class:

.. code:: c++

    bool operator== (const Vector2d& vec) const {
        return x == vec.x && y == vec.y;
    }

    bool operator!= (const Vector2d& vec) const {
        return x != vec.x || y != vec.y;
    }

The ``const`` after the argument list allows these to be used on a
``const Vector2d`` object.

Writing tests
=============

Let's write some basic tests:




Continuous integration and github
=================================
