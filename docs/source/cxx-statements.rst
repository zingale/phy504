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

Inside of the ``main()`` function, we create a ``vector`` called
``fib`` and an integer ``n``.  Both of these are in scope inside of
``main`` -- that means that we can use them and access them as needed.

One of the nice things about the standard types like ``vector`` is
that C++ automatically cleans up their memory when they go out of
scope.  This occurs at the last ``}`` of ``main()``.  At that point,
``fib`` is destroyed and its memory is freed.  The same happens with ``n``.
This behavior is called an `automatic variable <https://en.wikipedia.org/wiki/Automatic_variable>`_.

Automatic variables are allocated in a special part of memory called
the `*stack* <https://en.wikipedia.org/wiki/Stack-based_memory_allocation>`_.  When you enter a function, all of the automatic
variables are *pushed down* onto the stack and are available as long
as they stay in scope.  When you exit the function, the variables are
*popped* off the stack and the memory is automatically freed.

In our example above, there are a few stacks.  The outermost static is
defined by the ``{}`` for ``main()``.

.. note::

   Stack space is limited and you can run out, resulting in a *stack overflow*.

   Later we'll see that we can manually manage memory for variables
   that we place in the *heap* which is generally much larger.

   (But also note that a ``vector`` keeps the storage for its elements
   separately from the vector object itself, and those can be on the
   heap and automatically managed for us.)


The ``for`` loop defines a new scope, and when we enter the ``{}``
delineating the loop block, a new stack is created, where the
variables local to that block are managed.  When we exit the loop,
that stack is destroyed, freeing up all of the memory those local
variables needed.


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

