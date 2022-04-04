*******************
Convergence Testing
*******************

Previously we considered integrating the orbit of a planet (and you are looking
at this further with 2nd order Runge-Kutta) in your homework.

Consider the problem:

.. math::

   \frac{dy}{dt} = -y

This has the solution:

.. math::

   y(t) = y(0) e^{-t}

We can integrate this using first order Euler and 2nd order Runge
Kutta (RK2) and compute the error with respect to the analytic
solution.  As we reduce the timestep, the error in the Euler method
should decrease as :math:`\Delta t`, while for the RK2 method it will
decrease as :math:`(Delta t)^2`.

Here's an implementation that integrates with both Euler and RK2 using
a variety of timesteps (each time halving the timestep):

.. literalinclude:: ../../examples/ODEs/exponential.cpp
   :language: c++
   :caption: ``exponential.cpp``

When run, we get output like:

::

    #                  dt               Euler                 RK2
            1.000000e-01        1.920100e-02        6.615437e-04
            5.000000e-02        9.393519e-03        1.591805e-04
            2.500000e-02        4.647001e-03        3.904855e-05
            1.250000e-02        2.311297e-03        9.670584e-06
            6.250000e-03        1.152626e-03        2.406311e-06
            3.125000e-03        5.755613e-04        6.001677e-07
            1.562500e-03        2.875931e-04        1.498661e-07
            7.812500e-04        1.437497e-04        3.744456e-08
            3.906250e-04        7.186315e-05        9.358385e-09
            1.953125e-04        3.592865e-05        2.339293e-09

We see that we get the expected convergence for both solvers: when
cutting ``dt`` in half, the Euler error goes down by :math:`\sim 2`
and the RK2 error goes down by :math:`\sim 4`.

One key part of getting the convergence correct: roundoff error means that
our steps with ``dt`` may not exactly end at the final time.  So we need to
check for this and adjust the last timestep to ensure we hit the correct
time:

.. code:: c++

   if (t + dt > tmax) {
       dt = tmax - t;
   }

