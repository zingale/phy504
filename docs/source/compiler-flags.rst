*******************************
Making the Compiler Do the Work
*******************************

Compilers have lots of options that affect the compilation.  So far,
with ``g++`` we've just been using ``-o`` to name the executable.  But
we can also have the compiler warn us about problematic C++ code we may
have written.  A useful set of options is:

.. prompt:: bash

   g++ -Wall -Wextra -Wpedantic

Here's a brief summary:

* ``-Wall`` : this turns on options that warn about things most users deem problematic.

* ``-Wextra`` : enabled additional warnings that most people think are good to check
   for.

* ``-Wpedantic`` : makes sure that you conform to the language standard and not rely
  on any extensions that the compiler might support.

Here's an example of a case of using the wrong type in a loop that can be caught with these flags:

.. literalinclude:: ../../examples/compiler-warnings/types.cpp
   :language: c++
   :caption: ``types.cpp`

Here's an example of catching unused variables:

.. literalinclude:: ../../examples/compiler-warnings/unused.cpp
   :language: c++
   :caption: ``unused.cpp`
