Passing a NumPy Array into C++
==============================

Imagine we want to create a NumPy array in python and pass it into C++ to
operate on.

In C++, we refer to the incoming array using the ``pybind11::array_t<T>`` class.
We then create a view (the pybind11 docs call it a proxy) that allows us to index
the array.  To do this, we need to specify the dimensions of the array via the template
parameter.

Note that this array is immutable because of the method we used to access its contents.

.. literalinclude:: ../../examples/pybind11/sum_from_python/sum.cpp
   :language: c++
   :caption: ``sum.cpp``

To compile it, we can essentially the same ``GNUmakefile``:

.. literalinclude:: ../../examples/pybind11/sum_from_python/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

We can use this in python as:

.. literalinclude:: ../../examples/pybind11/sum_from_python/test_sum.py
   :language: python
   :caption: ``test_sum.py``

Notice that the creation of the view / proxy into the array fails if we pass
in an array with the incorrect number of dimensions.

Mutable array
-------------

Here's a similar C++ function, but now we use
``mutable_unchecked<DIM>()`` to get our view into the passed array.

.. literalinclude:: ../../examples/pybind11/mutate_from_python/mutate.cpp
   :language: c++
   :caption: ``mutate.cpp``

And again, the same ``GNUmakefile`` (just changing the module name): :download:`GNUmakefile <../../examples/pybind11/mutate_from_python/GNUmakefile>`.

Here's how we can use it from python:

.. literalinclude:: ../../examples/pybind11/mutate_from_python/test_mutate.py
   :language: python
   :caption: ``test_mutate.py``

.. note::

   It doesn't matter if we declare our function as:

   .. code:: c++

      void update(pybind11::array_t<double>& a)

   or

   .. code:: c++

      void update(pybind11::array_t<double> a)

   The making the ``array_t`` a reference doesn't matter, since ``array_t`` is
   just a wrapper that has a pointer to a buffer where the data is stored.
