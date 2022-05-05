*********************
Stuff We Didn't Cover
*********************


``std::map``
============

With a ``std::map`` you can create an object that looks like a python
dictionary.  And C++17 offers an easy way to iterate over keys and
values:

.. literalinclude:: ../../examples/map/map_test.cpp
   :language: c++
   :caption: ``map_test.cpp``


``if constexpr``
================

An ``if constexpr`` is a compile-time if-test.  It essentially allows
you to template a general function and have the compiler write
specific versions based on the template paramters.  One way this is
used is to cut out expensive computations if we know we won't need
them, while still being able to write just a single implementation
that handles the general case.

Here's a trivial example:

.. literalinclude:: ../../examples/constexpr-if/constexpr_example.cpp
   :language: c++
   :caption: ``constexpr_example.cpp``


Virtual functions
=================


``static`` member data
======================


Memory management
=================


Regular expressions
===================

Regular expressions are a powerful way to search for patterns and
extract substrings out of strings.  The C++ `regular expressions
library <https://en.cppreference.com/w/cpp/regex>`_ provides all the
capability needed to work with regular expressions.

Profiling
=========

A profiler will allow you to time independent functions or even lines
of code and generate a report telling you where your code spends most
of its time.

`GNU gprof <https://sourceware.org/binutils/docs/gprof/>` is the GNU profiler
than can be used with ``g++``.

