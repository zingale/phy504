*****************************
MPI Linear Advection Equation
*****************************

Let's look at a very crude way to solve the linear advection equation in two-dimensions:

$$a_t + u a_x + v a_y = 0$$

We will do a very simple, first-order accurate discretization:

.. math::

  \frac{a^{n+1}_{i,j} - a^n_{i,j}}{\Delta t} =
          - u \frac{a^n_{i,j} - a^n_{i-1,j}}{\Delta x}
          - v \frac{a^n_{i,j} - a^n_{i,j-1}}{\Delta y}

This discretization assumes that $u > 0$ and $v > 0$.  In that case, it is *upwinded*.

.. note::

   This is only stable for $\mathcal{C} < 1/2$, where

   .. math::

      \mathcal{C} = \max \left \{ \frac{u \Delta t}{\Delta x}, \frac{v \Delta t}{\Delta y} \right \}


Domain decomposition
====================

We will divide our domain along the x-direction:

.. image:: domain-oned.png
   :align: center
   :width: 80%

Each MPI process will manage their own subdomain.  To make things
easier, we will refer to a global index space on the entire domain.
This means that we will want a version of our ``Array`` class that can
start at an arbitrary index:

.. literalinclude:: ../../examples/parallel/mpi/advect/array.H
   :language: c++
   :caption: ``array.H``


We will manage each processor's subdomain with a ``grid`` class:

.. literalinclude:: ../../examples/parallel/mpi/advect/grid.H
   :language: c++
   :caption: ``grid.H``

