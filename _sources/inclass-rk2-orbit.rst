*************************************
In Class: 2nd Order Runge-Kutta Orbit
*************************************

The main utility of functions is that we can reuse them in a code.
Let's look at this by extending our Euler integration of an orbit
to do 2nd-order `Runge-Kutta <https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods>`_ integration.

The Euler method was based on a first-order difference approximation
to the derivative.  But a centered-difference approximation to $df/dt$
is second order accurate at the midpoint in time, so we can try to
update our system in the form:

$$\frac{{\bf r}^{n+1} - {\bf r}^n}{\tau} = {\bf v}^{n+1/2} + \mathcal{O}(\tau^2)$$

$$\frac{{\bf v}^{n+1} - {\bf v}^n}{\tau} = {\bf a}^{n+1/2} + \mathcal{O}(\tau^2)$$

Then the updates are:

$${\bf r}^{n+1} = {\bf r}^n + \tau \, {\bf v}^{n+1/2} + \mathcal{O}(\tau^3)$$

$${\bf v}^{n+1} = {\bf v}^n + \tau \, {\bf a}^{n+1/2} + \mathcal{O}(\tau^3)$$

This is locally third-order accurate (but globally second-order
accurate), but we don't know how to compute the state at the
half-time.

To find the $n+1/2$ state, we first use Euler's method to predict the
state at the midpoint in time.  We then use this provisional state to
evaluate the accelerations at the midpoint and use those to update the
state fully through $\tau$.

The two step process appears as:

$${\bf r}^\star = {\bf r}^n + (\tau / 2) {\bf v}^n$$

$${\bf v}^\star = {\bf v}^n + (\tau / 2) {\bf a}^n$$

then we use this for the full update:

$${\bf r}^{n+1} = {\bf r}^n + \tau \,  {\bf v}^\star$$

$${\bf v}^{n+1} = {\bf v}^n + \tau \, {\bf a}({\bf r}^\star)$$


Graphically this looks like the following:

First we take a half step and we evaluate the slope at the midpoint:

.. figure:: rk2_halfEuler.png
   :align: center
   :width: 90%

   The predictor part of RK2 integration.

.. figure:: rk2_final.png
   :align: center
   :width: 90%

   The corrector / final update of RK2 integration.

Notice how the final step (the red line) is parallel to the slope we
computed at $t^{n+1/2}$.  Also note that the solution at $t^{n+1}$ is
much closer to the analytic solution than in the figure from Euler's
method.

To implement this, it would be nice to have a function that updates
the state based on the derivatives, like:

.. code:: c++

   OrbitState update_state(const OrbitState& state, const double dt, const OrbitState& state_derivs);

This way we can easily do the update both times as needed via a simple function call.

.. tip::

   Later we'll learn how to use operator overloading to do something like:

   .. code:: c++

      OrbitState state{};
      double dt{};
      OrbitState state_derivs{};

      ...

      auto state_new = state + dt * state_derivs;


Here's a solution:

.. dropdown:: solution

   .. literalinclude:: ../../examples/functions/orbit_rk2_example.cpp
      :language: c++
      :caption: ``orbit_rk2_example.cpp``
