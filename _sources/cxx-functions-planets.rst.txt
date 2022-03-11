************************
Example: Sorting Planets
************************

Let's use our new understanding of lambda functions to enable ``std::sort()``
to sort our planets vector based on eccentricity.

And, let's add one more trick -- we'll create a function that tells C++
how to output our ``Planet`` object directly.

Recall, that our ``Planet`` is a ``struct`` of the form:

.. code:: c++

   struct Planet
   {
       std::string name{};
       double a{};            // semi-major axis
       double e{};            // eccentricity
   };

We'd like to be able to do:

.. code:: c++

   Planet p;
   ...
   std::cout << p << std::endl;

We need to write a function that takes an output stream (``std::ostream``)
and returns a reference to that same output stream.

Here's how this function looks:

.. code:: c++

   std::ostream& operator<< (std::ostream& os, const Planet& p) {

       os << std::setw(12) << p.name << " : ("
          << std::setw(8) << p.a << " , "
          << std::setw(8) << p.e << ")";

       return os;
   }

.. note::

   Previously we saw that we could not write a function that returns a
   reference to a local object.  But here, the return value, ``os``, is
   not local -- we pass a reference to it via the argument list.

   This construction is what allows us to string ``<<`` together.

Here's the full code of initializing our planets, sorting by eccentricity,
and then outputting them.

.. literalinclude:: ../../examples/functions/planet_sort.cpp
   :language: c++


