*********************
Preview: C++23 mdspan
*********************

C++23 introduces `mdspan
<https://en.cppreference.com/w/cpp/container/mdspan>`_, a
multidimensional view into a contiguous memory space.  It also allows
us to use the ``,`` operator in subscripts.  This allows us to more
easily create a multidimensional array.  Here's an example:

.. literalinclude:: ../../examples/mdspan/mdspan.cpp
   :language: c++
   :caption: ``mdspan.cpp``

.. note::

   You need a *very* recent compiler for this to work.  I am using
   LLVM/clang++ 17 and build as:

   .. prompt:: bash

      clang++ -std=c++23 -stdlib=libc++ -o mdspan mdspan.cpp

   On my machine (Fedora 39), I needed to install the ``libcxx`` and
   ``libcxx-devel`` packages to get everything I need.

.. tip::

   You can see the status of C++23 support here:
   `compiler / library support for C++23 <https://en.cppreference.com/w/cpp/compiler_support/23>`_

