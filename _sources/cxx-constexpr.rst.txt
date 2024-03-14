*************
``constexpr``
*************

A ``constexpr`` variable or function is one that can be evaluated at compile time.  In particular, it can be used in `constant expressions <https://en.cppreference.com/w/cpp/language/constant_expression>`_.

One place where ``constexpr`` will be useful in the future is when we
start working with templates and want to compiler to do some
evaluations for us.

We can use ``constexpr`` in place of ``const`` to define constants, e.g.,

.. code:: c++

   constexpr double pi{3.1415926535897932384626433};


An ``if constexpr`` is a compile-time if-test.  It essentially allows
you to template a general function and have the compiler write
specific versions based on the template parameters.  One way this is
used is to cut out expensive computations if we know we won't need
them, while still being able to write just a single implementation
that handles the general case.

Here's a trivial example:

.. literalinclude:: ../../examples/constexpr/constexpr_example.cpp
   :language: c++
   :caption: ``constexpr_example.cpp``



We can also use it to define a function where we want the function to
be evaluated at compile time.  For example, here's a function that
computes integer powers, which can be faster than using
``std::pow()``.

.. literalinclude:: ../../examples/constexpr/powers.cpp
   :language: c++
   :caption: ``powers.cpp``
