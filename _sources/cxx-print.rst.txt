********************
Preview: C++23 Print
********************

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

Formatting
----------

The strings that are passed into ``print()`` or ``println()`` are
actually `std::format_string <https://en.cppreference.com/w/cpp/utility/format/basic_format_string>`_
and can specify where to insert variables and their formatting:

.. literalinclude:: ../../examples/print/formatting_example.cpp
   :language: c++
   :caption: ``formatting_example.cpp``

The format codes are described here:
https://en.cppreference.com/w/cpp/utility/format/spec
