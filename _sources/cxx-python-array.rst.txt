Returning an Array to Python
============================

``pybind11`` allows us to construct a NumPy array in C++ and have it
returned to python.  To do this, we need to use the ``pybind11``
classes that create a python array.

In ``pybind11``, the array class is ``pybind11::array_t<>``.  The constructor 


Here's an example that computes a `Hilbert matrix <https://en.wikipedia.org/wiki/Hilbert_matrix>`_
in C++ and returns it to python.

.. literalinclude:: ../../examples/pybind11/arrays/array.cpp
   :language: c++
   :caption: ``array.cpp``

The ``GNUmakefile`` is essentially the same, but we just need to
give the name of the library (``BASE`` in the ``GNUmakefile``):
:download:`GNUmakefile <../../examples/pybind11/arrays/GNUmakefile>`.
