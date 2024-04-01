.. _simple_grid_class:

********************************
In-Class Example: A Simple Grid
********************************

Let's create a class to represent `a structured grid
<https://en.wikipedia.org/wiki/Grid_classification>`_ that we can use
to represent data for solving PDEs via finite-difference methods.

We want our grid class to store:

* The domain limits, ``xmin``, and ``xmax``
* The number of points in the discretization, ``nx``
* The coordinate vector, ``x``
* A solution vector, ``phi``

We can then write functions to:

* Output the solution to the screen or file (as ``x[i]`` ``phi[i]`` in
  columns)

* Compute the norm of a vector on our grid, e.g., the L2 norm:

  $$\|e\|_2  = \left ( \Delta x \sum_i | e_i | {}^2 \right )^{1/2} $$

