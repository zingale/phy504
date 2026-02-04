**********
clang-tidy
**********

`clang-tidy <https://clang.llvm.org/extra/clang-tidy/>`_ is part of
the `LLVM project <https://llvm.org/>`_, and can identify programming
errors and suggest improvements to code.

Here's an example using it on our array code:

.. prompt:: bash

   clang-tidy test_array.cpp  -checks=-*,bugprone-*,misc-*,modernize-*,performance-*,readibility-* -- test_array.cpp

