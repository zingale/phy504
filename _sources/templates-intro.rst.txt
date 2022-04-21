*********
Templates
*********

C++ templates are a form of *generic programming*.  They allow us to
write functions that work on a variety of data types.  Here's a simple
example:

.. code:: c++

   template <typename T>
   T add(const T& x, const T& y) {
       return x + y;
   }

Here ``T`` stands in for the data type that we will use when calling
this function.  The compiler will determine which data types are used
with ``add`` and it will create and compile a version of the function
that works with each of the types.

.. tip::

   We can use either ``typename`` or ``class`` for the template parameters.  Only
   in rare instances is the difference important.

   https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates

We can call this with ``double`` s as:

.. code:: c++

   double x{3}, y{4};
   double z = add<double>(x, y);

But in this case, the compiler can infer the type ``T`` from the
inputs, so we don't need to include ``<double>``, and can instead simply do:

.. code:: c++

   double z = add(x, y);

Here's an example illustrating all of this:

.. literalinclude:: ../../examples/templates/simple_template.cpp
   :language: c++
   :caption: ``simple_templates.cpp``




