*****************************************************
In-Class Example: Orbit Integrator Compound Operators
*****************************************************

Let's go back to the class version
of our orbit integrator from  :ref:`orbit_class` and add the ``+=`` and ``-=``
operators to allow us to further simplify the code to do:

.. code:: c++

   state += dt * state_derivs;

Here's the code we created in class for this example:

* :download:`orbit.H <../../examples/orbits/orbit_class/orbit.H>`
* :download:`orbit_integrator.cpp <../../examples/orbits/orbit_class/orbit_integrator.cpp>`
* :download:`test_orbit.cpp <../../examples/orbits/orbit_class/test_orbit.cpp>`
* :download:`GNUmakefile <../../examples/orbits/orbit_class/GNUmakefile>`
