*************************
Example: Contiguous Array
*************************

.. admonition:: reading

   Your text does an example of a multi-dimensional array that is a
   ``vector`` of ``vector`` s.

   We are doing something different here -- we want the memory space
   to be fully contiguous, so we will create a 1-d memory space and create
   operators to index into it.

``vector``-of-``vector``'s
==========================

If we consider:

.. code:: c++

   std::vector<std::vector<double>> array_2d;

Then this is creating a 1-d array that corresponds to the rows of our
array, where each element of this is a separate vector to store the
columns that make up that row.  But each of those row vectors are independent,
and can be in very disparate positions in memory.

This can be visualized as:

.. figure:: vector_of_vectors.png
   :align: center
   :width: 80%

   Illustration of a ``vector``-of-``vector``'s for a :math:`4\times
   3` array.

Our goal is to create a contiguous memory space that stores all the
elements of the 2-d array.

Contiguous multi-dimensional array
==================================

To make a contiguous vector, we will use a single ``vector``
dimensioned with a size of ``nrows * ncols`` (note: C++ will likely
have more elements than this, to allow for the potential expansion of
the vector, but we won't use that).

We will then overload the ``()`` operator to allow for us to index
into this one-dimensional buffer as ``a(nrow, ncol)``.

This can be visualized as:

.. figure:: struct_array.png
   :align: center
   :width: 90%

   Illustration of a one-dimensional ``vector`` wrapped in a ``struct`` that can be
   indexed as a two-dimensional array.

Implementation
==============

We will implement the main ``struct`` in a header so we can reuse this

.. literalinclude:: ../../examples/contiguous_array/array.H
   :language: c++
   :caption: ``array.H``

Some comments on this implementation:

* We do not include the ``_data`` vector in the initialization-list,
  but instead explicitly resize it in the constructor.  This allows us
  to do an ``assert`` on the number of rows and columns before we try
  to resize it.

  The downside of this approach is that it might be a little slower,
  since we create the empty vector and then resize it in two steps
  instead of handling it all at initialization.

* We have two methods for the ``()`` operator.  The first is for the
  case of a non-``const`` declared ``Array`` and the second is for a
  ``const`` declared ``Array``.

The body of the ``Array`` methods is provided in a separate ``.cpp`` file:

.. literalinclude:: ../../examples/contiguous_array/array.cpp
   :language: c++
   :caption: ``array.cpp``

Here's a test program for the ``Array`` object:

.. literalinclude:: ../../examples/contiguous_array/test_array.cpp
   :language: c++
   :caption: ``test_array.cpp``

Notice a few things:

* When we loop over the elements of the ``Array`` we get the number of
  rows via ``.nrows()`` and the number of columns via ``.ncols()``.

* For ``Array y``, we use a range-for loop over the elements of
  ``_data`` directly -- this is the one-dimensional representation of
  our array.  We can do this because the data is stored contiguously.

* When we try to index out of bounds, the ``assert`` statements catch
  this.

And finally, to build this, here's a ``GNUmakefile``:

.. literalinclude:: ../../examples/contiguous_array/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

.. note::

   If we want to disable the asserts, then we need to define the
   ``-DNDEBUG`` preprocessor directive.  By disabling this check,
   we will run faster.


