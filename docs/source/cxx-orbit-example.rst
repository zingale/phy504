.. _planetary_orbit:

************************
Example: Planetary Orbit
************************

Let's consider an example of integrating the orbit of Earth around the
Sun (we'll consider the mass of the Earth to be tiny compared to the
Sun so we can neglect the Sun's motion around the center of mass).

Kepler's third law tells us:

.. math::

   4\pi^2 a^3 = G M_\star P^2

where :math:`a` is the semi-major axis and :math:`P` is the period of the orbit.  If we work in 
units of solar masses, astronomical units, and years, then this becomes:

.. math::

   a^3 = P^2

which implies that :math:`G M_\star = 4 \pi^2`.

The evolution of the planet is given by

.. math::

   \dot{\bf r} = {\bf v}

.. math::

   \dot{\bf v} = - \frac{G M_\star {\bf r}}{r^3}

where :math:`{\bf r} = (x, y)` and :math:`{\bf v} = (v_x, v_y)`.

Euler's Method
==============

The simplest method to advance the solution begins with a first-order accurate difference approximation
to the derivative:

.. math::

   \frac{{\bf r}^{n+1} - {\bf r}^n}{\tau} = {\bf v}^n + \mathcal{O}(\tau)

.. math::

   \frac{{\bf v}^{n+1} - {\bf v}^n}{\tau} = {\bf a}({\bf r}^n,{\bf v}^n) + \mathcal{O}(\tau)

or

.. math::

   {\bf r}^{n+1} = {\bf r}^n + \tau {\bf v}^n + \mathcal{O}(\tau^2)

.. math::

   {\bf v}^{n+1} = {\bf v}^n + \tau {\bf a}({\bf r}^n,{\bf v}^n) + \mathcal{O}(\tau^2)

This shows that each time we take a step, we make an error (called
*truncation error*) of :math:`\mathcal{O}(\tau^2)`.  Over the course
of the orbit we will take :math:`N = T / \tau` steps, so the global
error will be :math:`\mathcal{O}(\tau)`.

This method is *first-order accurate* in time.


Graphically, Euler's method looks like:

.. figure:: rk2_Euler.png
   :align: center
   :width: 90%

   Euler's method: we evaluate the slope at the start of the timestep and then follow
   this through to the new time.

Implementation
==============

We'll store the state of the solution at a single instance in time in a ``struct``:

.. code:: c++

   struct OrbitState {
       double t;
       double x;
       double y;
       double vx;
       double vy;
   };

and we'll save the solution at each step in a vector:

.. code:: c++

   std::vector<OrbitState> orbit_history{};

This corresponds to the "array-of-structs" storage scheme we discussed earlier.


To make our code flexible, we'll write the following functions:

* A righthand side function, with the forward declaration:

  .. code:: c++

     OrbitState rhs(const OrbitState& state);

  we can evaluate this as needed by passing in an ``OrbitState`` and
  returning the derivative of that state with respect to time.

* A function to write out the history:

  .. code:: c++

     void write_history(const std::vector<OrbitState>& history);

  We can adapt this as desired to write to the screen or a file.

* An integration function:

  .. code:: c++

     std::vector<OrbitState> integrate(const double a, const double tmax, const double dt);

  This manages the time-stepping, implementing Euler's method and
  storing the solution in our history vector each step.  At the end of
  integration it will return the history.


.. admonition:: try it...

   Implement the solver by filling in the details of the functions described above.

   .. dropdown:: solution

      .. literalinclude:: ../../examples/functions/orbit_example.cpp
         :language: c++
         :caption: ``orbit_example.cpp``

.. tip::

   We can plot the solution using ``gnuplot``.

   First, when you run, redirect the output to a file:

   .. prompt:: bash

      ./orbit_example > orbit.dat

   Now run ``gnuplot``:

   .. prompt:: bash

      gnuplot

   A simple plot in ``gnuplot`` is made using the ``plot`` command, specifying the file with the 
   data, the columns to use for x and y axes, and any styling (like ``w l`` for *with-lines*):

   .. prompt::
      :prompts: gnuplot>

      plot 'orbit.dat' using 2:3 w l
      set size square
      replot

   This will make something like:

   .. figure:: orbit.png
     :align: center
     :width: 80%

   You can save the plot as:

   .. prompt::
      :prompts: gnuplot>

      set term png
      set output "orbit.png" 
      replot


   For more info, see: http://www.gnuplot.info/
 
