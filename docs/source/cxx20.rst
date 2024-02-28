***************
Coming in C++20
***************

The main features in C++20 of interest to scientific computing are:

Modules
=======



Concepts
========


Range Adaptors
==============

Range adaptors look like pipes that we saw when discussing Bash (see:
https://learn.microsoft.com/en-us/cpp/standard-library/range-adaptors?view=msvc-170)

Here's an example of using an adaptor to reverse the iteration through a vector using
a range-based for loop:

.. literalinclude:: ../../examples/range_adaptors/reverse_adaptor.cpp
   :language: c++
   :caption: ``reverse_adaptor.cpp``



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
