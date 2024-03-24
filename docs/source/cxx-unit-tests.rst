************
Unit Testing
************

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

.. note::

   There is a `GNU make shell function <https://www.gnu.org/software/make/manual/html_node/Shell-Function.html?>`_
   that looks like it might work, but that actually expands the command
   and then tries to execute the output.

Here's what the rule would look like:

.. code:: make

   testing: unit_test_vector2d
   	./unit_test_vector2d > /dev/null
   	@if [ $$? == 0 ]; then echo "tests passed"; fi

After we run our command (we redirect ``stdout`` to ``/dev/null`` to
make it quiet) we use an ``if-then`` statement to check the output.
Note the ``@`` at the start of the line makes it so ``make`` doesn't
print the command itself to the screen, just the output.

Here's the full version:

.. literalinclude:: ../../examples/unit_tests/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

.. admonition:: try it...

   Let's make a test fail in our ``unit_test_vector2d.cpp`` and make sure that this still works.

