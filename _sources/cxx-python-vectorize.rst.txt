Vectoring a C++ Function
========================

We can use ``pybind11`` to convert a C++ function that takes scalars
to work with NumPy arrays as input.  This uses the `py::vectorize functionality <https://pybind11.readthedocs.io/en/stable/advanced/pycpp/numpy.html#vectorizing-functions>`_ in ``pybind11``.

Here's the same simple function as before, but now we simply pass the function
into the ``pybind11`` macros as ``pybind11::vectorize(f)``:

.. literalinclude:: ../../examples/pybind11/vectorize/vectorize.cpp
   :language: c++
   :caption: ``vectorize.cpp``

Here's a driver:

.. literalinclude:: ../../examples/pybind11/vectorize/test_vectorize.py
   :language: python
   :caption: ``test_vectorize.py``

