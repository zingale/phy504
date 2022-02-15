*************
C++ Datatypes
*************

.. admonition:: reading

   Cyganek section 3.1 

Data is stored in computer memory.  We'll refer to the data in memory as an *object*.

We can access this data:

* directly: using a descriptive object name

* indirectly: using a pointer or a reference to the memory location

Data stored in the object can be:

* *mutable* : we can change it -- these are variables

* *immutable* : it cannot be changed -- these are constants

There are several basic types of data:

* ``char`` : a 1 byte character (like ``'a'``)

* ``int`` : an integer

* ``float`` : a single precision floating point number

* ``double`` : a double precision floating point number

There are also modifiers that can be used with many of these like: ``short``, ``unsigned``, ``long``.

A table of C++ datatypes is provided in the `CPlusPlus tutorial variables section <https://www.cplusplus.com/doc/tutorial/variables/>`_

Initialization
==============

We can initialize a define a variable as:

.. code:: c++

   int i;
   float x;
   double slope;

.. note::

   C++ variable names are case-sensitive, so ``x`` and ``X`` are distinct.

   Variable names can include letters, numbers, and ``_``, but cannot
   begin with a number.

   There are some reserved keywords (like ``int``) that cannot be used
   as variable names.

It is always a good idea to initialize a variable with a starting
value.  Otherwise, most compilers will leave it undefined and you can
run into problems if you try to use it without first remembering to
initialize it.

There are a few ways to initialize.  Here are the two we'll see the most:

.. code:: c++

   int i = 0;
   double x{};

Both of these will initialize the variable to ``0``.  The ``{}``
notation is more flexible, since it will work with more complicated
objects that we will encounter later.

We'll see a third way to initialize objects when we look at classes (and constructors).

Objects defined with ``const`` cannot be changed, so you are required to initialize the immediately:

.. code:: c++

   const double G = 6.67e-8;


Sizes
=====

.. note:: 

   C++ guarantees a minimum size of the different types, but different
   compilers or processors may have different defaults.

