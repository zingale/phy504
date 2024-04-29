***************
Coming in C++20
***************

The main features in C++20 of interest to scientific computing are:

Modules
=======

Modules are source files that are compiled independently of your program that can
then be imported.  They replace the role of headers in C++20.  Note that compiler
support is not that great at the moment.

See `Overview of modules in C++ <https://learn.microsoft.com/en-us/cpp/cpp/modules-cpp?view=msvc-170>`_

One of the advantages of modules is that they can greatly speed up compilation times.

.. note::

   Compiler support for modules is not very good at the moment.

Here's a simple example.  First the module:

.. literalinclude:: ../../examples/modules/example.cpp
   :language: c++
   :caption: ``example.cpp``

Now the main program:

.. literalinclude:: ../../examples/modules/main.cpp
   :language: c++
   :caption: ``main.cpp``

and finally, a ``GNUmakefile``:

.. literalinclude:: ../../examples/modules/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

.. note::

   This compiles with GCC 11.4, but curiously not with GCC 14...

Concepts
========

Views
=====

C++ 20 introduces the `ranges library <https://en.cppreference.com/w/cpp/ranges>`_.  This allows us to more easily consider views into our containers.

Here's an example of using a range-based for loop over a set of integers:

.. literalinclude:: ../../examples/views/iota_loop.cpp
   :language: c++
   :caption: ``iota_loop.cpp``


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

