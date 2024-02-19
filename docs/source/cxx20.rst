***************
Coming in C++20
***************

The main features in C++20 of interest to scientific computing are:

Modules
=======



Concepts
========


3-way Comparison
================


``<numbers>``
=============

The `numbers header <https://en.cppreference.com/w/cpp/numeric/constants>`_
provides mathematical constants.  They are implemented as templates that
can be defined with whatever type you need:

.. literalinclude:: ../../examples/numbers/numbers_example.cpp
   :language: c++
   :caption: ``numbers_example.cpp``



``<format>``
============

We already saw the new style formatting when we looked at ``std::print()``.
The format is handled by the `format header <https://en.cppreference.com/w/cpp/header/format>`_.
