.. _orbit_class:

****************************************
In-Class Example: Orbit Integrator Class
****************************************

Let's go back to our :ref:`planetary_orbit` example and make the ``OrbitState``
a class and define the ability to add ``OrbitState`` objects together and
multiply them by a scalar.  This would allow us to do something like:

.. code:: c++

   OrbitState orbit{};
   OrbitState dodt{};
   double dt{};

   ...

   orbit = orbit + dt * dodt;

and make our evolution code look simpler as a result.

The addition will look like:

.. code:: c++

   OrbitState operator+(const OrbitState& orbit);

.. note::

   The ``+=`` operator is a different operator, and we'd need to
   write a separate function for it.  We'll look at this later.

We will need to define two multiplications, one for the case where our class
is to the left of the ``*``, e.g., ``orbit * dt`` and one for the case where our
class is on the right of the ``*``, e.g., ``dt * orbit``.

The first case can be a class member and will have the signature:

.. code:: c++

   OrbitState operator*(double a);

The second will be a friend, and have the signature:

.. code:: c++

   friend OrbitState operator*(double a, const OrbitState& orbit);


.. note::

   Our ``OrbitState`` contains position, velocity, and time.  Previously we were
   not defining the time in the output from ``rhs()``, but now we will need to, since
   our operators will act on it.  Since the output of ``rhs()`` is just the time-derivative
   of the state, we can just set ``dodt.t = 1`` in  the output, since $d/dt (t) = 1$.

Here's the version of the code split up into files (we did this in
:ref:`orbit_split`)---we'll use this as the starting point:

* :download:`orbit.H <../../examples/orbits/orbit_split/orbit.H>`
* :download:`orbit_integrator.cpp <../../examples/orbits/orbit_split/orbit_integrator.cpp>`
* :download:`test_orbit.cpp <../../examples/orbits/orbit_split/test_orbit.cpp>`
* :download:`GNUmakefile <../../examples/orbits/orbit_split/GNUmakefile>`
