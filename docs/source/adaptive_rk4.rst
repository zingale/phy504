********************
Adaptive Runge-Kutta
********************

Previously we looked at the simple Euler and 2nd-order Runge-Kutta
methods for integration.  Now we will look at 4th order Runge-Kutta.
We will also:

* Write our integrator as a class that works with any
  ODE system of the form:

  .. math::

     \frac{d{\bf y}}{dt} = {\bf f}(t, {\bf y})

* Adapt the timestep taken internally to achieve a user-desired
  error in the solution.


4th order RK
============

Fourth-order Runge-Kutta consists of 4 stages and a final update, illustrated below:

.. tab-set::

   .. tab-item:: Stage 1

      The advance begins by estimating the derivatives (righthand side or
      slope) at time $t^n$.  We'll call this ${\bf k}_1$.

      $${\bf k}_1 = {\bf f}(t^n, {\bf y}^n)$$

      .. figure:: rk4_k1.png
         :align: center
         :width: 90%


   .. tab-item:: Stage 2

       We then follow the slope ${\bf k}_1$ to the midpoint in time,
       $t^{n+1/2}$ and evaluate the slope there.  We call the new slope ${\bf
       k}_2$.

       $${\bf k}_2 = {\bf f}(t^n + \tau/2, {\bf y}^n + (\tau/2) {\bf k}_1)$$

       .. figure:: rk4_k2.png
          :align: center
          :width: 90%


   .. tab-item:: Stage 3

      We then go back to the start, but this time follow the new slope,
      ${\bf k}_2$ to the midpoint in time, $t^{n+1/2}$.  We again evaluate
      the slope here, and call it ${\bf k}_3$.

      $${\bf k}_3 = {\bf f}(t^n + \tau/2, {\bf y}^n + (\tau/2) {\bf k}_2)$$

      .. figure:: rk4_k3.png
         :align: center
         :width: 90%

   .. tab-item:: Stage 4

      Finally, we go back to the start and follow ${\bf k}_3$ for the full
      timestep, to $t^{n+1}$ and evaluate the slope there, calling it ${\bf
      k}_4$.

      $${\bf k}_4 = {\bf f}(t^n + \tau, {\bf y}^n + \tau {\bf k}_3)$$

      .. figure:: rk4_k4.png
         :align: center
         :width: 90%

   .. tab-item:: Final update

       We then get the updated solution using a linear combination of the 4
       slopes:

       $${\bf y}^{n+1} = {\bf y}^n + \frac{\tau}{6} ({\bf k}_1 + 2 {\bf k}_2 + 2 {\bf k}_3 + {\bf k}_4)$$

       .. figure:: rk4_final.png
          :align: center
          :width: 90%

       Note the similarity of RK4 to Simpson's rule for integration.

Adaptive timesteps
==================

So far we've been integrating with a fixed timestep.  This gives us no real control over the error.  What we would like to do is take a small timestep when the solution is changing fast, and a larger timestep when the solution changes more slowly.

To do this, we need to be able to assess the error in our solution as
we integrate.  There are lots of different ways to do this in the
literature:

* Take two half steps and compare to one full step

* Compare higher and lower order methods (sometimes the lower order
  method is *embedded* in the higher-order method, for instance this
  is the `RK45 method used by SciPy <https://en.wikipedia.org/wiki/Dormand%E2%80%93Prince_method>`_).

We'll do the first method here, as it is the simplest.  Consider
integrating a function $y(t)$ through some timestep $\tau$:

.. figure:: adaptive_timestep.png
   :align: center
   :width: 90%

   Adaptive timestep comparing $\tau/2$ steps to a single $\tau$ step.

The top evolution takes a single step of size $\tau$ while the bottom
takes two steps each of $\tau/2$.  These two integrations both end at
$y(t+\tau)$, but we expect the one that took 2 half steps to be more
accurate (since the truncation error is smaller).

Now, we know that RK4 is *locally* 5th order accurate, so that means that
for our single step, the error will be:

$$\epsilon \sim \tau^5$$

And imagine that we wanted to achieve an error of
$\epsilon_\mathrm{want}$---there is a timestep $\tau_\mathrm{est}$ that would
get this:

$$\epsilon_\mathrm{want} \sim \tau_\mathrm{est}^5$$

If we take the ratio of these, then any proportionality cancels, and
we have

$$\tau_\mathrm{est} = \tau \left (\frac{\epsilon_\mathrm{want}}{\epsilon} \right)^{1/5}$$

If we were not accurate enough, this would predict a finer timestep
that would give us our desired accuracy.  And if we were too accurate,
then this would tell us how much we could increase the timestep while
maintaining our desired accuracy.

Let's consider doing this with RK4.  Our approach will be:

1. Integrate from $y(t)$ to $y(t+\tau)$ using a single timestep, $\tau$.

   Call the solution $y^\mathrm{single}$

2. Integrate from $y(t)$ to $y(t+\tau)$ using two steps of size $\tau/2$.

   Call the solution $y^\mathrm{double}$

3. Compute an estimate of the *relative error* in the solution as:

   .. math::

      \epsilon_\mathrm{rel} =
         \left | \frac{y^\mathrm{double} - y^\mathrm{single}}
                      {y^\mathrm{double}} \right |

4. Compute the timestep that would give us our desired accuracy,
   $\epsilon_\mathrm{want}$:

   $$\tau_\mathrm{est} = \tau \left (\frac{\epsilon_\mathrm{want}}{\epsilon_\mathrm{rel}} \right)^{1/5}$$

5. If $\epsilon_\mathrm{rel} < \epsilon_\mathrm{want}$ then our
   timestep was good, and store the solution at time $t + \tau$ as
   $y^\mathrm{double}$.  Increase the timestep according to
   $\tau_\mathrm{est}$ for the next step.

   If $\epsilon_\mathrm{rel} > \epsilon_\mathrm{want}$ then throw away
   our solution and go back to $y(t)$ and retry the integration with
   the new, smaller $\tau_\mathrm{est}$.

In practice, we usually limit the amount that the timestep can change
from one attempt to the next by a factor of $\sim 4$ or so.

.. note::

   For a different method, the timestep estimate will likely be
   different, since it depends on the scaling of the local truncation
   error with the timestep, $\tau$.

Implementation
==============

Here's the code:

:download:`ode_integrator.H <../../examples/numerical_algorithms/adaptive_rk4/ode_integrator.H>`

.. dropdown:: ``ode_integrator.H``

   .. literalinclude:: ../../examples/numerical_algorithms/adaptive_rk4/ode_integrator.H
      :language: c++
      :caption: ``ode_integrator.H``

.. note::

   With C++23 we can write things a little cleaner using ``std::views::zip()``,
   for example, replacing:

   .. code:: c++

      rel_error = 0.0;
      for (auto n = 0ul; n < y_new.size(); ++n) {
           rel_error = std::max(rel_error,
                                std::abs((y_new[n] - y_single[n]) / y_new[n]));
      }

   with:

   .. code:: c++

      rel_error = 0.0;
      for (const auto [yd, ys] : std::views::zip(y_new, y_single)) {
           rel_error = std::max(rel_error, std::abs((yd - ys) / yd));
      }

Some notes:

* We use ``std::vector`` internally to store the data for the system of ODEs.
  We could have used ``std::array``, but that would have required us to template
  the ``ODE`` class on the number of equations.

* At each point in time, the state of the system is stored in a ``struct`` called
  ``solution``.  There is a simple constructor that can fill the data.

  We have an overload for the stream operation, ``<<``, that works with a ``solution`` object.

* Our righthand side function can have one of 2 signatures:

  * A simple function of the form $f(t, y)$:

    .. code:: c++

       std::vector<double> f(double t, const std::vector<double>& y)

  * A version that allows for a vector of parameters, $f(t, y, p)$:

    .. code:: c++

       std::vector<double> f(double t, const std::vector<double>& y,
                             std::vector<double>& params)

  The second case allows us to pass a vector of parameters that the
  system may depend on that are not the integration variables.  This
  is a common feature in ODE integrators.

* We use `emplace_back
  <https://en.cppreference.com/w/cpp/container/vector/emplace_back>`_
  instead of ``push_back()`` to add a ``solution`` to our history
  vector.  This eliminates the need to create a temporary ``solution``
  object to push to the vector (likely through a move), e.g., as:

  .. code:: c++

     history.push_back(solution(t, y));

  instead ``emplace_back`` simply passes the arguments we give it to the constructor
  and operates directly on the vector.

* The ``ODE`` class manages the solution.  There are 2 constructors, one for each
  type of righthand side function.  Each takes the set of initial conditions.

The basic usage is:

.. code:: c++

   std::vector<double> y0(0.0, 1.0, 2.0);
   o = ODE(f, y0);
   auto history = o.integrate(dt, tmax);

The integrator will take the number of equations in the system from
the number of initial conditions, and it will expect that the
righthand side function, ``f`` returns a vector of this length (this
is asserted).

We can also use an initialization list like:

.. code:: c++

   o = ODE(f, {0.0, 1.0, 2.0});

Finally, the ``integrate`` member function can optionally take the relative
tolerance with which to find the solution.

Example: elliptical orbits
==========================

Here's a driver for integrating orbits.  We pick a high eccentricity which means
that the planet's speed will vary a lot over the orbit.

The initial conditions put the planet on the +x axis, at perihelion, with a
counterclockwise orbit.  They are:

.. math::

   \begin{align*}
     x &= a (1 - e) \\
     y &= 0 \\
     u &= 0 \\
     v &= \sqrt{\frac{GM}{a} \frac{1+e}{1-e}}
   \end{align*}


.. literalinclude:: ../../examples/numerical_algorithms/adaptive_rk4/test_orbit.cpp
   :language: c++
   :caption: ``test_orbit.cpp``

.. note::

   Notice that in our RHS function, we don't explicitly create the ``std::vector``
   that we will return, but instead our return looks like:

   .. code:: c++

      return {dxdt, dydt, dudt, dvdt};

   This is an example of using a braced initialization list for the return.

.. tip::

   When run, the output will show the range of timesteps taken.

Here's a plot of the output, showing the points computed during the solution.  Notice that
at perihelion they are much more closely spaced than at aphelion.

.. figure:: orbit_adaptive.png
   :align: center
   :width: 80%

.. admonition:: try it...

   How does our solution compare (in terms of accuracy and number of steps) if we
   force the code to use a uniform timestep?


Example: Lorenz system
======================

Here's a driver for integrating the `Lorenz system <https://en.wikipedia.org/wiki/Lorenz_system>`_.
This system appears as:

.. math::

   \begin{align*}
     \frac{dx}{dt} &= \sigma (y - x) \\
     \frac{dy}{dt} &= x (\rho - z) - y \\
     \frac{dz}{dt} &= xy - \beta z
   \end{align*}

and is a simple model for convection.  Here, $x$ is a measure of the rate of convection,
$y$ is related to the horizontal temperature variation, and $z$ is related to the vertical
temperature structure.  There are 3 parameters: $\sigma$ is the Prandtl number, $\rho$
is the Rayleigh number, and $\beta$ is related to the system size.

Lorenz chose $\sigma = 10$, $\beta = 8/3$, and $\rho = 28$.

.. literalinclude:: ../../examples/numerical_algorithms/adaptive_rk4/test_lorenz.cpp
   :language: c++
   :caption: ``test_lorenz.cpp``

The Lorenz system is interesting because it is chaotic---small changes to the initial
conditions will lead to very large differences in the solution.

.. admonition:: try it...

   Try changing the initial conditions by $1$ part in $10^6$ and compare plots of
   $x$ vs. $t$.

Example: using a lambda-function
================================

For a simple system, we can use a lambda-function.  Here we solve:

.. math::

   \frac{dy}{dt} = -y

with $y(0) = 1$.

.. literalinclude:: ../../examples/numerical_algorithms/adaptive_rk4/test_lambda.cpp
   :language: c++
   :caption: ``test_lambda.cpp``
