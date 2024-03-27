************************
Example: Templated Array
************************

With templates we can easily extend our contiguous array class to work
with any data type.  We will mark it as:

.. code:: c++

   template <typename T>
   class Array

and our member data will now be:

.. code:: c++

   std::size_t _rows;
   std::size_t _cols;
   std::vector<T> _data;

Here's a full implementation:

.. literalinclude:: ../../examples/templates/array.H
   :language: c++
   :caption: templated version of ``array.H``

Now we can create arrays of different types like:

.. code:: c++

   Array<double> a(10, 10);
   Array<int> b(5, 10);

Here's a test driver:

.. literalinclude:: ../../examples/templates/test_array.cpp
   :language: c++
   :caption: ``test_array.cpp``

.. admonition:: try it...

   Add another constructor to our class that creates a square array.  It will
   only need to take a single dimension, ``N``, which is then used to set both
   ``_rows`` and ``_cols``.
