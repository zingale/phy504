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

.. warning::

   This is a very bad discretization of advection.  Our concern here
   is not on the accuracy of the method, but to demonstrate how to do
   the domain decomposition.  For better methods for advection, see
   `my lecture notes on advection <https://zingale.github.io/computational_astrophysics/advection/advection-intro.html>`_.


Domain decomposition
====================

We will divide our domain along the x-direction:

.. image:: domain-oned.png
   :align: center
   :width: 80%

Each MPI process will manage their own subdomain.  To make things
easier, we will refer to a global index space on the entire domain.

For the figure above, the indices of the boxes, (``ilo``, ``ihi``, ``jlo``, ``jhi``) are:

* left box: (``0``, ``5``, ``0``, ``9``)

* middle box: (``5``, ``9``, ``0``, ``9``)

* right box: (``10``, ``14``, ``0``, ``9``)

Each of these boxes will be managed by a separate MPI task.  To deal
with the boundaries of each box, we will have a perimeter of ghost
cells, shown as the red outline for the middle box.  We will use MPI
send/recv to exchange data with the neighboring boxes to fill these
ghost cells.

For the physical boundaries, we will assume we are periodic.

``Array``
---------

We want a version of our ``Array`` class that can
start at an arbitrary index, e.g., for the middle box above (excluding ghost cells):

.. code:: c++

   Array a(5, 9, 0, 9)

This is easy to do by adapting our existing ``Array`` class to include an offset:

.. literalinclude:: ../../examples/parallel/mpi/advect/array.H
   :language: c++
   :caption: ``array.H``

``Grid``
--------

We will manage each processor's subdomain with a ``grid`` class:

.. literalinclude:: ../../examples/parallel/mpi/advect/grid.H
   :language: c++
   :caption: ``grid.H``

