pybind11
========

The `pybind11 <https://pybind11.readthedocs.io/en/stable/>`_ library allows you to
call C++ code from python.  It is a header-only library, and requires that you
only add a few lines describing your module and C++ functions to the source
to get it to work.

You can install ``pybind11`` via ``pip``:

.. prompt:: bash

   pip install pybind11

Since it is a header-only library, the main thing you need in order to
compile source is the location of the headers (so you can specify the
include path via the ``-I`` option).  You can find this via:

.. prompt:: bash

   python -m pybind11 --includes

on my machine, this gives:

::

   -I/usr/include/python3.12 -I/home/zingale/.local/lib/python3.12/site-packages/pybind11/include

When we compile the ``.cpp`` code, we need to make a shared-object library that can be imported
into python as a module.  This needs to have a specific name, with the suffix given by

.. prompt:: bash

   python3-config --extension-suffix

on my machine, this gives:

::

   .cpython-312-x86_64-linux-gnu.so


Simple function example
-----------------------

Here's a very simple example.  We will write a C++ function that computes
$f(x) = \sin(x)$.

.. literalinclude:: ../../examples/pybind11/simple/simple.cpp
   :language: c++
   :caption: ``simple.cpp``

We add a ``PYBIND11_MODULE`` macro that defines the entry point
from python---see: https://pybind11.readthedocs.io/en/stable/reference.html#macros

To compile it, we can use this ``GNUmakefile``:

.. literalinclude:: ../../examples/pybind11/simple/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

We can use this in python as:

.. code:: python

   import simple
   simple.f(1.0)


