********************
Adaptive Runge-Kutta
********************

Previously we looked at the simple Euler and 2nd-order Runge-Kutta
methods for integration.  Now we will look at 4th order Runge-Kutta.
We will also:

* Write our integrator as a templated class that works with any
  ODE system of the form:

  .. math::

     \frac{d{\bf y}}{dt} = {\bf f}(t, {\bf y})

* Adaptive the timestep taken internally to achieve a user-desired
  error in the solution.

Here's the code:

.. literalinclude:: ../../examples/general_ODE_class/ode_integrator.H
   :language: c++
   :caption: ``ode_integrator.H``

