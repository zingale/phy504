****************************************
In-Class Example: Euler Integrator Class
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

.. code::

   OrbitState operator+(const OrbitState& orbit);

.. note::

   The ``+=`` operator is a different operator, and we'd need to
   write a separate function for it.  We'll look at this later.

We will need to define two multiplications, one for the case where our class
is to the left of the ``*``, e.g., ``orbit * dt`` and one for the case where our
class is on the right of the ``*``, e.g., ``dt * orbit``.

The first case can be a class member and will have the signature:

.. code::

   OrbitState operator*(double a);

The second will be a friend, and have the signature:

.. code::

   friend OrbitState operator*(double a, const OrbitState& orbit);
