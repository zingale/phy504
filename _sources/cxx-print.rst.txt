*****
Print
*****

C++23 introduced ``std::print()`` and ``std::println()`` as an easier way to output
formatting strings to the console.

Here's a Hello, World:

.. literalinclude:: ../../examples/print/print_hello.cpp
   :language: c++
   :caption: ``print_hello.cpp``

The only difference between ``print()`` and ``println()`` is that the
latter adds a newline.

.. tip::

   Just like with our ``mdspan`` example, we need to use a compiler and library
   that support C++23.  We can compile, for example, as:

   .. prompt:: bash

      clang++ -std=c++23 -stdlib=libc++  -o print_example print_example.cpp

