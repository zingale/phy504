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

.. code:: python

   import numpy as np
   a = np.ones((5, 4), dtype=np.float64)
   sum.sum(a)


Mutable array
-------------

Here's a similar C++ function, but now we use
``mutable_unchecked<DIM>()`` to get our view into the passed array.

.. literalinclude:: ../../examples/pybind11/mutate_from_python/mutate.cpp
   :language: c++
   :caption: ``mutate.cpp``

And again, the same ``GNUmakefile`` (just changing the module name):

.. literalinclude:: ../../examples/pybind11/mutate_from_python/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

Here's how we can use it from python:

.. literalinclude:: ../../examples/pybind11/mutate_from_python/test_mutate.py
   :language: python
   :caption: ``test_mutate.py``
