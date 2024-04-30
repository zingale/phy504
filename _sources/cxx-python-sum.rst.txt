Passing a NumPy Array into C++
==============================

Imagine we want to create a NumPy array in python and pass it into C++ to
operate on.

In C++, we refer to the incoming array using the ``pybind11::array_t<T>`` class.
We then create a view (the pybind11 docs call it a proxy) that allows us to index
the array.  To do this, we need to specify the dimensions of the array via the template
parameter

.. literalinclude:: ../../examples/pybind11/sum_from_python/sum.cpp
   :language: c++
   :caption: ``sum.cpp``

To compile it, we can essentially the same ``GNUmakefile``:

.. literalinclude:: ../../examples/pybind11/sum_from_python/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

We can use this in python as:

.. code:: python

   import numpy as np
   a = np.ones((5, 4), dtype=np.float64)
   sum.sum(a)


