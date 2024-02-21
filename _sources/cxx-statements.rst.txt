******************
Loops and If-Tests
******************

.. admonition:: reading

   Cyganek section 3.13

We've been using ``if`` tests and ``for`` loops already, but now it's
time to understand some of the nuances of these statements.


Statement Blocks
================

We use curly braces, ``{}`` to denote blocks of code.  These are used
in a number of contexts:

* to define the body of a function (so far we've only seen ``main()``,
  but this applies to any function).

* to define the members of a ``struct``, ``enum``, or as we'll soon
  see, a ``namespace`` or ``class``.

* to group statements that are part of another statement, as with an
  ``if`` or ``for`` loop.

One thing to keep in mind with these blocks is *scope*---this means
whether we have access to the value held by an object.

A general rule is that we can access objects that are defined outside
of our current scope.

Let's look at a Fibonacci example:

.. literalinclude:: ../../examples/statements/fibonacci.cpp
   :language: c++
   :caption: ``fibonacci.cpp``

Inside of the ``main()`` function, we create a ``vector`` called
``fib`` and an integer ``n``.  Both of these are in scope inside of
``main``---that means that we can use them and access them as needed.

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


Conditional Statements
======================

``if``-test
-----------

We've already been using if-tests quite a bit.  So let's look a little more at their syntax:

.. code:: c++

   if (condition1) {
      // do things if condition1 is true

   } else if (condition2) {
      // do things if condition1 is false but condition 2 is true

   } else {
      // do things only if both condition1 and condition2 are false

   }


.. tip::

   There is a form of an if-statement that does not use brackets if
   there is only a single statement to execute:

   .. code:: c++

      if (condition)
          statement;

   This is potentially dangerous---if someone later edits the code
   and decides that they want to add another statement to that
   condition, they might do:

   .. code:: c++

      if (condition)
          statement;
          another_statement;

   But since there are no braces, only ``statement`` is
   conditionally-executed.  ``another_statement`` is not part of the
   if-test and will always be executed.

   For this reason, it is always best to use brackets.

.. note::

   C++17 also allows for a form with an initializer before the
   conditional (e.g., to open a file).  We will not explore this here.


.. tip::

   There is also a simple `ternary operator
   <https://en.wikipedia.org/wiki/%3F:>`_ in C++ of the form:

       *condition* ``?`` *true-result* ``:`` *false result*

   Where *true-result* is the value used if *condition* is ``true``
   and *false-result* otherwise.

   For instance:

   .. code:: c++

      int i{10};

      double x = (i > 5) ? 1.0 : 0.0;


``switch`` statement
--------------------

A switch statement takes action on a single expression, and has many different
cases that can take different actions.  For example:

.. code:: c++

   int i{2};
   std::string text{};

   switch (i) {

      case 0:
          text = "zero";
          break;

      case 1:
          text = "one";
          break;

      case 2:
      case 3:
      case 4:
          text = "2 <= i <= 4";
          break;

      default:
          text = "i > 4";

   }

Notice that each ``case`` region ends with ``break``.  If you omit the
``break``, then the flow "falls through" to the next options.

``for`` loops
-------------

We've already seen the basic structure of a for loop:

.. code:: c++

   for (initializer ; condition ; iterator) {
        // do stuff
   }

We can do this for just a simple integer counter:

.. code:: c++

   for (int i = 0; i < 10; i += 2) {
        // we'll see i = 0, 2, 4, 6, 8
   }

or with an iterator, like:

.. code:: c++

   std::string my_string{"this is my string"};

   for (auto it = my_string.begin(); it < my_string.end(); ++it) {
        // work on the string character by character
   }

.. note::

   Just like with ``if``, there is a single-statement form of ``for``
   that doesn't use brackets for the loop body---this should be
   avoided.

We also saw the range-for loop that works with a variety of containers.  For example:

.. code:: c++

   std::vector<double> x{0.0, 1.0, 2.0, 3.0};

   for (auto e : x) {
       // work on the current element in x
   }



``while`` and ``do``-``while`` loops
------------------------------------

There are two types of ``while`` loops in C++.  The first takes the form:

.. code:: c++

   while (condition) {
       // do stuff
   }

where the body is executed so long as ``condition`` is true.  For example:

.. code:: c++

   int i{0};

   while (i < 10) {
      i = 2*i;
   }

The loop body is only ever executed if the condition is true.  The
other form puts the ``while`` at the end:

.. code:: c++

   do {
       // do stuff
   } while (condition);

In this case, all of the statements in the loop body are executed at least once.

``continue`` and ``break``
==========================

Sometimes we want to exit a loop early or skip the remainder of the
loop block if some conditions is met.  This is where ``continue`` and
``break`` come into play.

It is not uncommon to write an infinite loop, like:

.. code:: c++

   for (;;) {
       // do stuff
   }

or

.. code:: c++

   while (true) {
       // do stuff
   }

In this case, we will want a way to bail out.  Here's an (silly)
example of asking for a word from a user and telling them how many
letters it contains.  But if they enter "0", we exit:

.. literalinclude:: ../../examples/statements/infinite_loop.cpp
   :language: c++
   :caption: ``infinite_loop.cpp``

``continue`` is used to skip to the next iteration.  Here's an example
that loops over elements of a vector but only operates on them if they
are even numbers, in which case, it negates them.

.. literalinclude:: ../../examples/statements/continue_example.cpp
   :language: c++
   :caption: ``continue_example.cpp``
