******
OpenMP
******

`OpenMP <https://www.openmp.org/>`_ provides a *directive-based*
approach to marking regions of code for parallelism.  It supports
shared-memory parallelism and offloading to accelerators.

Some nice examples are provided in the `OpenMP Application Programming
Interface Examples document
<https://www.openmp.org/wp-content/uploads/openmp-examples-4.5.0.pdf>`_.

.. tip::

   The `OpenMP Reference Guide <https://www.openmp.org/wp-content/uploads/OpenMPRef-5.0-111802-web.pdf>`_ provides
   a quick overview of the different syntax in OpenMP.


Hello, World
============

Here's a simple "Hello, World" in OpenMP.  We print out the number of
threads and then enter a parallel region where each thread prints its
id separately:

.. literalinclude:: ../../examples/parallel/openmp/hello.cpp
   :language: c++
   :caption: ``hello.cpp``

When we compile this, we need to tell the compiler to interpret the OpenMP directives:

.. prompt:: bash

   g++ -fopenmp -o hello hello.cpp

A few notes:

* When we run this, the threads are all printing independent of one
  another, so the output is all mixed up.  Run it again and you'll see
  a different ordering.


Parallelizing Loops
===================

Here's a matrix-vector multiply:

.. literalinclude:: ../../examples/parallel/openmp/matmul.cpp
   :language: c++
   :caption: ``matmul.cpp``


Reductions
==========

Reductions (e.g., summing, min/max) are trickier, since each thread
will be updating its local sum or min/max, but then at the end of the
parallel region, a reduction over the threads needs to be done.

.. literalinclude:: ../../examples/parallel/openmp/reduce.cpp
   :language: c++
   :caption: ``reduce.cpp``


Example: Monte Carlo :math:`\pi`
================================

