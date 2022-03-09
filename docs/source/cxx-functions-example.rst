**************
More Functions
**************

Consider wanting to write a vector that takes one vector as input and returns a new one.

We can imagine:

.. code:: c++

   std::vector<double> f(const std::vector<double>& v_in) {

       std::vector<double> v_out;

       // do stuff to fill v_out based on v_in

       return v_out;

   }

This looks like it is returning ``v_out`` by value and that when we do:

.. code:: c++

   auto v_new = f(v_old);

that we need to make a copy.  But C++ instead provides *move
semantics* -- this means that instead of copying the entire contents
of the local ``v_out`` to the vector in the caller ``v_new`` it simply
moves the data by setting the pointer to the data region in ``v_new``
to the data region in ``v_out`` before ``v_out`` is destroyed.


A second method if to pass it through the argument list as a reference:

.. code:: c++

   void f(const std::vector<double>& v_in, std::vector<double>& v_out) {

       // fill v_out based on v_in

   }

Then we can do:

.. code:: c++

   std::vector<double> v_old{};
   std::vector<double> v_new{};

   f(v_old, v_new);


.. danger::

   What about returning a reference?  We might think that we could do:

   .. code:: c++

      std::vector<double>& f(const std::vector<double>& v_in) {

          std::vector<double> v_out;

          // do stuff to fill v_out based on v_in

          return v_out;

      }

   The problem here is that ``v_out`` is destroyed at the end of the function
   ``f``, so the reference will be to something that no longer exists.
   This is not allowed -- we cannot return a reference to a local
   variable.


Let's play with this:

.. literalinclude:: ../../examples/functions/function_vector.cpp
   :language: c++


