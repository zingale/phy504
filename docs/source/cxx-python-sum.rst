Passing a NumPy Array into C++
==============================

Imagine we want to create a NumPy array in python and pass it into C++ to
operate on.


.. literalinclude:: ../../examples/pybind11/sum_in_python/sum.cpp
   :language: c++
   :caption: ``sum.cpp``

To compile it, we can essentially the same ``GNUmakefile``:

.. literalinclude:: ../../examples/pybind11/sum_in_python/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

We can use this in python as:

.. code:: python

   import numpy as np
   a = np.ones((5, 4), dtype=np.float64)
   sum.sum(a)


