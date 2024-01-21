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
specific versions based on the template parameters.  One way this is
used is to cut out expensive computations if we know we won't need
them, while still being able to write just a single implementation
that handles the general case.

Here's a trivial example:

.. literalinclude:: ../../examples/constexpr-if/constexpr_example.cpp
   :language: c++
   :caption: ``constexpr_example.cpp``


.. Virtual functions
.. =================



``static`` member data
======================

``static`` members of a class are not associated with objects that are instances of the class
but instead there is one value for all instances of the class.  In this sense, they act as
global data in the class's namespace.

Memory management
=================

We've been relying mainly on objects that manage their own memory
internally (like ``std::vector``).  We saw one instance of allocating memory
on our own using ``new`` or by ``make_unique``.  The latter is the safest way
to deal with allocating memory.

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

`GNU gprof <https://sourceware.org/binutils/docs/gprof/>`_ is the GNU profiler
than can be used with ``g++``.

