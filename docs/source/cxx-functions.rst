*********
Functions
*********

.. admonition:: reading

   Cyganek section 3.14

As we write increasingly complex code, it becomes helpful to split it apart into functions.  This has
several advantages:

* We can reuse the functionality provided by a function easily

* It becomes easier to test the code -- we can test each function
  separately (unit tests)

* We can use the functions in other codes

* The design process becomes easier if we think of our code in terms
  of what functions are needed.  Then once we layout the flow of the
  code in terms of the major functions, we can implement them
  one-by-one.

Quite often in C++ we will split our code into multiple files, but for
now we'll work all within a single file.

Basic Example
=============

Let's start with a simple example, and then we'll talk about the structure:

.. literalinclude:: ../../examples/functions/simple_function.cpp
   :language: c++


Some things to note here:

* We include a `forward declaration
  <https://en.wikipedia.org/wiki/Forward_declaration>`_ of the
  function.

  .. code:: c++

     double sum(double x, double y);

  This just tells the compiler the function name, its return type, and
  what arguments it takes (and their types).  There is no function
  body.

  With this declaration, the compiler will now know that anytime we
  use ``sum()`` we need to pass it two ``double`` 's and it returns a
  ``double``.

  Often, we would put the forward declaration in a header file and the
  ``#include`` it just like we do with the standard C++ headers.

  Note that this code will compile even without the forward
  declaration because we have the actual function definition before it
  is used.  But this is not always possible.

* The function definition provides the actual implementation of the function.
  For our ``add`` function, it is:

  .. code:: c++

     double sum(double x, double y) {
        return x + y;
     }

* The function has its own scope -- inside of the function, ``x`` and ``y`` are
  in scope and visible, but they are not available outside of the function.

* We use ``return`` to explicitly return a value to the caller of the function.

  Only one return will ever be executed in a function, but the
  function itself could have multiple returns that are executed
  depending on conditions inside the function itself.

.. admonition:: try it...

   #. Move the function definition to be after ``main`` and remove the
      forward declaration -- does the code still compile?

   #. Now instead leave in the forward declaration, but remove the
      function definition -- what happens when you compile now?


Void
====

It is possible to have a function that doesn't return anything -- in
that case we mark it as ``void``.

Also, we can have a function that doesn't take any arguments.  Here's
an example:

.. code:: c++

   void hello();

   void hello() {
        std::cout << "hello" << std::endl;
   }


Passing by Value vs. Reference
==============================

When we write a function like:

.. code:: c++

   void f(double x) {
       // do stuff -- the caller won't see any changes to x
   }

and then call it as:

.. code:: c++

   double z{0};
   f(z);

The value of ``z`` in our caller is copied into the value of ``x`` in
the function ``f()``.  This is a *pass-by-value* argument (sometimes
called *value semantics*).

Inside of ``f()`` any changes we do to ``x`` will not be reflected
back to the caller, so ``z`` will be unmodified by anything that
happens in the function.

Many times this is what we want.  But not always.  What if we want to
allow the function to modify its argument and for those modifications
to be reflected to the caller?  In this case, we use a reference
argument:

.. code:: c++

   void g(double &x) {
       // anything we do to x will be reflected back to the caller
   }


.. tip::

   Sometimes, if the object we are passing is big (like a
   ``std::vector``), then the copy incurred by passing by value is
   expensive.  If we use a reference, then there is no copy, and
   passing the object is faster.

   If we know that we only want the function we are calling to read
   from the object and not write to it, we can mark the reference as
   const, like:

   .. code:: c++

      void h(const double& x) {
          // x is passed as a reference, but we cannot modify it
      }

Here's an example of different ways to pass data into a function:

.. literalinclude:: ../../examples/functions/function_value_reference.cpp
   :language: c++



.. Default Values
.. ==============


STL Algorithms
==============

We looked at some of the `algorithms that work on standard C++
containers <https://en.cppreference.com/w/cpp/algorithm>`_ (like
vectors) previously.  Now we can look at some more.  

Consider ``std::sort()`` -- you can provide a function to ``sort``
that tells it how to do the comparison.

Here's an example that sorts some strings using the default comparison
(alphabetically) and then again with a custom comparison function that
sorts by string length:

.. literalinclude:: ../../examples/functions/algorithms_functions.cpp
   :language: c++

We'll revisit this yet again when we learn about *lambda functions*.

.. admonition:: more reading

   You text has a few additional sections of interest that we won't
   directly cover now:

   * Section 3.14.3 : the function call mechanism
   * Section 3.14.4 : recursive functions
   * Section 3.14.5 : function overloading and namespaces
