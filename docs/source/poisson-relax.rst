*******************************
Poisson Equation and Relaxation
*******************************

We want to solve the Poisson equation:

.. math::

   \nabla^2 \phi = f

We'll do it in 1-d, writing our equation as:

.. math::

   \frac{d^2 \phi}{dx^2} = f

on a domain :math:`[a, b]`.

Discretization
==============

We will represent :math:`\phi` and :math:`f` on a 1-d uniform grid:

.. figure:: fd_grid_bnd.png
   :align: center

   Our 1-d finite difference grid

Here we represent the discrete value of :math:`\phi` with a subscript:

.. math::

   \phi_i = \phi(x_i)

and similarly for :math:`f_i`.

Notice that with this grid we have a point on each boundary.  We will set these points to the boundary conditions:

.. math::

   \phi(a) = A

.. math::

   \phi(b) = B

We now discretize the Poisson equation, writing it as:

.. math::

   \frac{\phi_{i+1} - 2 \phi_i + \phi_{i-1}}{\Delta x^2} = f_i

Since the boundary values are fixed, for a grid of :math:`N` points, we need to
update the points :math:`1 \ldots N-2` using this expression.

We can solve for the update for a single zone:

.. math::

   \phi_i = \frac{1}{2} (\phi_{i+1} + \phi_{i-1} - \Delta x^2 f_i)

Our solution procedure is to iteratively apply this, updating the
values :math:`\phi_i` as we go along.  This process is called
*relaxation* or *smoothing*, and the approach we will use, where we
use the new information immediately as it becomes available is called
*Gauss-Seidel relaxation*.

Stopping
========

We need a measure to determine when we should stop relaxing the solution.  We define
the *residual*, :math:`r`, as:

.. math::

   r_i =    \frac{\phi_{i+1} - 2 \phi_i + \phi_{i-1}}{\Delta x^2} - f_i

This is a measure of how we'll we satisfy the discrete equation.

We will keep iterating until the norm of the residual is small
compared to the norm of the source:

.. math::

   \| r \| < \epsilon \| f \|

Once that is satisfied, then we have solved the problem as well as we
can do with the number of points we are using in the discretization.

Implementation
==============

Here's a class that implements smoothing:

.. literalinclude:: ../../examples/numerical_algorithms/poisson/poisson.H
   :language: c++
   :caption: ``poisson.H``

Let's try it on the problem:

.. math::

   \phi^{\prime\prime} = \sin(x)

on :math:`[0, 1]` with the boundary conditions:

.. math::

   \phi(0) = 0

.. math::

   \phi(1) = 1

This has the analytic solution:

.. math::

   \phi(x) = -\sin(x)  + (1 + \sin(1)) x

Here's the driver that implements this problem:

.. literalinclude:: ../../examples/numerical_algorithms/poisson/poisson.cpp
   :language: c++
   :caption: ``poisson.cpp``

