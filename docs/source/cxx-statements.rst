**********
Statements
**********

.. admonition:: reading

   Cyganek section 3.13

We've been using ``if`` tests and ``for`` loops already, but now it's
time to understand some of the nuances of these statements.


Statement Blocks
================

We use curly braces, ``{}`` to denote blocks of code.  These are used in a number of contexts:

* to define the body of a function (so far we've only seen ``main()``, but this applies to any function).

* to define the members of a ``struct``, ``enum``, or as we'll soon see, a ``namespace`` or ``class``.

* to group statements that are part of another statement, as with an ``if`` or ``for`` loop.

One thing to keep in mind with these blocks is *scope* -- this means whether we have access to the value held by an object.

A general rule is that we can access objects that are defined outside of our current scope.

Let's look at the solution from our homework 3:

.. literalinclude:: ../../examples/statements/fibonacci.cpp
   :language: c++




Shadowing
=========

Consider the following:

.. code:: c++

   bool test{true};
   double x{0.0};

   x = 3.14;

   if (test) {
       double x = 1.0;
   }

Here we've defined a new variable ``x`` inside the ``if`` block.
Since it has the same name as the object ``x`` in the main code, we
say that we are *shadowing* the value from outside our block.  In
general, this should be avoided.  These two ``x`` objects are
completely separate in memory and once we left the ``if`` block, the
inner ``x`` is destroyed and its contents are not available to us.
However, someone reading the code might not realize this.

.. tip::

   g++ can warn you about shadowing if you include the ``-Wshadow``
   option to the compiler.

