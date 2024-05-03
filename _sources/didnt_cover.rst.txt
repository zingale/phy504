*********************
Stuff We Didn't Cover
*********************


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

We can compile our code to be instrumented for profiling by simply adding the ``-pg``
flag to the compiler arguments.  Then we run as normal and use ``gprof`` to examine
the timing.

Here's an example, using our :ref:`poisson_relax` application.  The ``GNUmakefile`` there will compile with profiling if we set ``PROFILE=TRUE``:

.. prompt:: bash

   make PROFILE=TRUE
   ./poisson
   gprof poisson > gprof.out

We can then look at the ``gprof.out`` file to see where we are spending the most time.
