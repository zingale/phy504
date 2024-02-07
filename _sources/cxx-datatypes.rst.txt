*************
C++ Datatypes
*************

.. admonition:: reading

   * Cyganek section 3.1
   * `Fundamental types <https://en.cppreference.com/w/cpp/language/types>`_ from cppreference.com

Data is stored in computer memory.  We'll refer to the data in memory as an `object <https://en.wikipedia.org/wiki/Object_(computer_science)>`_.

We can access this data:

* directly: using a descriptive object name

* indirectly: using a pointer or a reference to the memory location

Data stored in the object can be:

* *mutable* : we can change it---these are `variables <https://en.wikipedia.org/wiki/Variable_(computer_science)>`_

* *immutable* : it cannot be changed---these are `constants <https://en.wikipedia.org/wiki/Constant_(computer_programming)>`_

There are several basic types of data:

* ``bool`` : a 1-bit true or false

* ``char`` : a 1 byte character (like ``'a'``)

* ``int`` : an integer

* ``float`` : a single precision floating point number

* ``double`` : a double precision floating point number

.. note::

   A `floating point number
   <https://en.wikipedia.org/wiki/Floating-point_arithmetic>`_ is any
   number with a decimal point, like ``2.0`` or ``1.e-20``.

   Generally, floating point numbers cannot be exactly represented on
   a computer, since there are infinite numbers on the number line
   between :math:`[0, 1]`, but the computer only has a finite amount
   of memory.

   *Single* and *double* precision refer to how much memory (and therefore
   how much precision) is used to store the numbers.  Usually single
   precision uses 32 bits and double precision uses 64 bits.
   More on this later...

There are also modifiers that can be used with many of these like: ``short``, ``unsigned``, ``long``.

A table of C++ datatypes is provided in the `CPlusPlus tutorial variables section <https://www.cplusplus.com/doc/tutorial/variables/>`_

Initialization
==============

We can initialize a define a variable as:

.. code:: c++

   int i;
   float x;
   double slope;

.. tip::

   C++ variable names are case-sensitive, so ``x`` and ``X`` are distinct.

.. warning::

   Variable names can include letters, numbers, and ``_``, but cannot
   begin with a number.  Additionally, there are some reserved
   keywords (like ``int``) that cannot be used as variable names.

.. danger::

   It is always a good idea to initialize a variable with a starting
   value.  Otherwise, most compilers will leave it undefined and you
   can run into problems if you try to use it without first
   remembering to initialize it.

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


Mixing types
============

You need to be careful when mixing different data types.  C++ will
implicitly *cast* objects to the more general type, sometimes with
unexpected consequences.  Later we'll see how to explicitly cast data
if needed.

Try the following (you'll need to put this in a ``main()`` function and compile it).

.. code:: c++

   // convert from Fahrenheit to Celsius

   double T_F {100.0};
   double T_C =  (T_F - 32) * (5 / 9);

   std::cout << "T_C = " << T_C << std::endl;


Why doesn't this work as expected?


Sizes
=====

The link above as well as your text tells you how the standard defines
the sizes of the different data types.

.. important:: 

   C++ guarantees a minimum size of the different types, but different
   compilers or processors may have different defaults.

But we can explicitly determine this with a C++ program using ``sizeof()``---that returns the number of *bytes*

.. code:: c++

   std::cout << sizeof(double) << std::endl;

The following is guaranteed:

.. code:: c++

   sizeof(char) == 1 <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)

We can find out a lot about the range and precision of numbers that can be stored with a given type by using
`std::numeric_limits <https://en.cppreference.com/w/cpp/types/numeric_limits>`_:

.. literalinclude:: ../../examples/limits/limits_test.cpp
   :language: c++
   :caption: ``limits_test.cpp``

Notice that there is a new pattern here, the use of ``<>``---this is
used in template functions, a topic we will talk a lot about later.

What happens if we exceed the limits of a data type?

.. figure:: https://imgs.xkcd.com/comics/cant_sleep.png
   :align: center

   (`xkcd <https://imgs.xkcd.com/comics/cant_sleep.png>`_)

.. admonition:: try it...

   Create a program that initializes a ``short`` integer and through
   addition triggers an overflow.

Precision is also important with floating point.  Consider the following: what do you expect?

.. code:: c++

   double a = 1.0;
   double b = -1.0;
   double c = 2.e-15;

   std::cout << (a + b) + c << std::endl;
   std::cout << a + (b + c) << std::endl;

With floating point, the associate property of addition does not hold.



