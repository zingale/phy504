**********
Structures
**********

.. admonition:: reading

   Cyganek section 3.9

A structure (or ``struct``) is a compound datatype that can hold a mix
of data.  In C++, a ``struct`` shares many similarities to a ``class``
-- both hold data as well as functions that work on the data (called
*members*).

.. _sec:structplanet:

Consider the following:

.. code:: c++

   struct Planet
   {
       std::string name{};
       double a{};            // semi-major axis
       double e{};            // eccentricity
   };

If we create ``Planet`` object via:

.. code:: c++

   Planet p;

Then we can access the different members of the ``struct`` using the "``.``" operator,
e.g. ``p.name``, ``p.a``, and ``p.e``.

This is a structure that can describe some basic properties of a planet, including its
name, semi-major axis, and eccentricity of the orbit.

Let's look at a program that stores the basic properties for the
planets in our solar system and then loops over them and computes
their orbital period using Kepler's third law:

.. math::

   \left ( \frac{P}{\mathrm{year}} \right )^2 = \left ( \frac{a}{\mathrm{AU}} \right )^3

.. literalinclude:: ../../examples/structs/struct_example.cpp
   :language: c++
   :caption: ``struct_example.cpp``

Some notes:

* We put the defintion of ``Planet`` outside of the ``main()`` function.

* In the initialization of the ``planets`` vector, we use
  list-initialization for each of the planets in its own set of
  ``{}``.

* Notice that our vector ``planets`` is ``const``.  This means that we
  cannot add to it (e.g., via ``.push_back()``).


.. tip::

   A common mistake is to forget the ``;`` after the definition of the ``struct``.

.. note::

   As mentioned above, a ``class`` is very similar to a ``struct`` in
   C++.  The main difference is that in a ``struct`` all of the
   members are publicly accessible while in a ``class``, they are
   private unless we make them public.

.. note::

   A common consideration when organizing data that is associated
   together is whether to do a struct-of-arrays or an
   array-of-structs.  See this discussion on `AoS and SoA
   <https://en.wikipedia.org/wiki/AoS_and_SoA>`_.

   In our planet example above, we created an array of structs.  This
   is a natural organization if we want to loop over planets and
   access their data individually.


