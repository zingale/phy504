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

.. note::

   There are a lot of unit testing frameworks for C++ programs (for
   example, `Catch2 <https://github.com/catchorg/Catch2>`_).  We are just going to
   something simple here.

We can use the basic ``assert`` statement together with a makefile target to automate testing.

.. tip::

   ``assert`` will end the execution at the first failure.  We could
   instead keep track of the number of failures and explicitly return
   that as the return value of ``main``, with ``0`` signifying all tests
   passing.

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

These should be added directly to the class in ``vector2d.H``.


Writing tests
=============

Let's write some basic tests:

.. literalinclude:: ../../examples/unit_tests/unit_test_vector2d.cpp
   :language: c++
   :caption: ``unit_test_vector2d.cpp``

These tests cover most of the functionality we explicitly implemented
in ``vector2d.H``.  As written, they should all pass.


Automating with make
====================

We'd like to provide a way to automate these tests.  Our first method
will be via ``make`` that we can run on our own computer.

Let's start with the general ``GNUmakefile`` we developed in our
:ref:`sec:makefiles` section.

We can use the `GNU make shell function
<https://www.gnu.org/software/make/manual/html_node/Shell-Function.html?>`_
to run our test and capture the return code.

Here's what the rule would look like:

.. code:: make

   testing: unit_test_vector2d
   	$(shell ./unit_test_vector2d)
   	@if [ ${.SHELLSTATUS} == 0 ]; then echo "all tests pass"; fi

We use ``$(shell )`` to run our executable.  Then we use a Bash
``if-then`` statement to check the output.  Note the ``@`` at the
start of the line makes it so ``make`` doesn't print the command
itself to the screen, just the output.


.. admonition:: try it...

   Let's make a test fail in our ``unit_test_vector2d.cpp`` and make sure that this still works.


Continuous integration and github
=================================

For a large project, with multiple developers, we often want to ensure
that any changes that they make to the code still pass all of the
tests before we merge it into the ``main`` git branch.  This is called
*continuous integration*.  Github has a feature called `Github actions
<https://docs.github.com/en/actions>`_ that allow us to set up simple
scripts that run on all pull requests.

We'll look at how this can work -- this is a high level overview of
the process that we will experiment with.  Usually one of the main
developers of a large project will have already implemented the
testing.

We'll use this repository: https://github.com/phy504-sbu/unit_tests

