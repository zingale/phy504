Introduction to Classes
=======================

.. admonition:: reading

   Cyganek section 3.15



Classes are objects that hold both data and functions that know how to operate on the data.

.. note::

   In C++, both ``struct`` and ``class`` create a class, with the difference being
   whether the data is publicly accessible by default.

We'll start by doing a ``struct`` with a *constructor* -- this will
behave like a class, except by default all of the data will be
publicly available.

Here's the basic format of a struct / class:

.. code:: c++

   struct ClassName {

       // data members are declared here

       ClassName(int param1, int param2) {
           // do any initialization for when we create a ClassName object
       }

       // other member functions here

   };

The most important function is the *constructor*.  When we create an
instance of our class, the constructor function is called and does any
initialization / setup that the class requires.

Here's a concrete example -- we'll build on our vector of planets, but making a class/struct
that holds the data and member functions that know how to operate on that data.


The main advantage to using a class here is that we don't need to know
how the planet data is actually stored (in this case in a ``std::vector<Planet>``.
But creating member functions that are part of the class, we hide the implementation
details from the user.  Instead they are given a simple set of functions
to interact with the data.



.. note::

   A class can have multiple constructors.  A constructor that takes no arguments
   is called the *default constructor*.



In this simple example, we really did not need to use an initialization list, but there
are situations when it is desired or even required:

* if any of our member data is ``const`` or a reference.

* if we have other classes as our member data (including things like ``std::vector``)
  and initializing them involves some overhead.  It can be faster to do the initialization
  via the initialization list.

See the stack overflow `Why should I prefer to use member
initialization lists?
<https://stackoverflow.com/questions/926752/why-should-i-prefer-to-use-member-initialization-lists>`_
discussion.
