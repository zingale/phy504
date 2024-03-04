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

