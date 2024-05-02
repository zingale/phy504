Vectoring a C++ Function
========================

We can use ``pybind11`` to convert a C++ function that takes scalars
to work with NumPy arrays as input.  This uses the `py::vectorize functionality <https://pybind11.readthedocs.io/en/stable/advanced/pycpp/numpy.html#vectorizing-functions>`_ in ``pybind11``.


