******
Arrays
******

.. admonition:: reading

   * Cyganek section 3.10

   * `std::array at cppreference.com <https://en.cppreference.com/w/cpp/container/array>`_

Arrays have many similarities to vectors.  In particular, both arrays and vectors
store the data contiguously in memory.  This means you get good cache performance
when looping over elements.

But there are some key differences:

* Vectors can grow in size as needed to accommodate additional data.
  In contrast, arrays are fixed-size.

* Arrays also are allocated in a different part of memory by default
  (the stack rather than the heap---more on this later).

* Arrays do not initialize their elements by default when declared.


Here's a simple example:

.. literalinclude:: ../../examples/arrays/simple_array.cpp
   :language: c++
   :caption: ``simple_array.cpp``

Declaring the array takes 2 arguments in the ``<>``---the datatype and the number of elements.

Notice that when we look over the elements, they are uninitialized.

We can use an initializer list to give initial values, like:

.. code:: c++

   std::array<int, 10> int_arr{0};

If you don't give all the values, the remainder are initialized to 0:

.. admonition:: try it...

   What are the values from this:

   .. code:: c++

      std::array<int, 10> int_arr{1, 2};

We can use the same set of algorithms we saw with vectors on arrays, like ``sort``, ``find``, etc.


Multidimensional Arrays
=======================

.. _sec:multidimensionalarrays:

Just like with vectors, we can have an array of arrays.  This would
again be fixed-size, so we'll need to specify both the number of rows
and the number of columns at compile time.

Here's an example:

.. literalinclude:: ../../examples/arrays/multid_array.cpp
   :language: c++
   :caption: ``multid_array.cpp``

Notice that we need to explicitly set the size of both the
``row_arr_t`` and the ``fixed_mat_t``.  While this solves the issue we had
with our ``std::vector<std::vector<double>>`` where we could have rows
of varying length, it is less flexible in that we need to know the
size ahead of time.

There are a few features here that we have not yet seen.

* We use ``std::setw()`` to set the width (number of characters) to
  use when writing out our numbers.  This makes them line up nicely.

* We access the information in the arrays using a reference (with the
  ``&`` operator).  This gives us direct access to the memory without
  needing to make a copy.

We'll cover references next.

.. note::

   In C and older C++, you will see fixed-side arrays declared as:

   .. code:: c++

      double x[10];
      int p[10][20];

   The ``std::array`` is a more modern wrapper for these---it has the
   advantage that it knows the size of the array.


