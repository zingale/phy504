****************
Function Objects
****************



Often we want to write numerical algorithms to be general, so we'd like to be able to
pass a function as an argument for the algorithm to operate on.  ``std::function`` provides
the mechanism for us to pass a function to a function.  It has the form:

.. code:: c++

   std::function<return_type(arg1_type, arg2_type)> f

where we specify both the function's return type (as ``return_type``)
and the type of any arguments that the function takes (as
``arg1_type`` and ``arg2_type`` above, for a function with 2
arguments).


First example
=============

Here we write a function ``doit()`` that takes a value and a function
that operates on that value and it just prints out some information
before and after calling the passed-in function.

.. literalinclude:: ../../examples/functional/simple_function.cpp
   :language: c++
   :caption: ``simple_function.cpp``

Templated example
=================

Here's a more complicated example that performs an operator on an
input vector, where the operation is determined by a function passed
into our ``reduce()`` function.

To make it more general, we template everything, so our ``reduce()``
can operate on a vector of any type.  (Note: there are routines in the
C++ SL that already do this, but here we can see a simple
implementation.)

We will apply a function of the form:

.. code:: c++

   template <typename T>
   T op(T x, T y);

to the elements of the vector.  We assume that the order of ``x`` and ``y`` doesn't matter.

.. literalinclude:: ../../examples/functional/functional_reduce.cpp
   :language: c++
   :caption: ``functional_reduce.cpp``


.. note::

   In some cases, we can remove the specialization in the ``reduce()`` call
   if the compiler can infer it from the arguments.  For instance, we can
   do:

   .. code:: c++

      std::cout << "sum b: " <<
         reduce(b, 0.0, add<double>) << std::endl;

   But note that this does not work if we write ``0`` instead of ``0.0``.


.. tip::

   We can also use a lambda function with the same interface, e.g.,

   .. code:: c++

      std::cout << "min b: " <<
        reduce<double>(b, std::numeric_limits<double>::max(),
                       [] (double x, double y) {return std::min(x, y);}) << std::endl;
