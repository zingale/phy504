***
MPI
***


Hello, World
============

.. literalinclude:: ../../examples/parallel/mpi/hello.cpp
   :language: c++
   :caption: ``hello.cpp``


Integrating :math:`\pi`
=======================

Here we want to construct the integral:

.. math::

   \pi = 4 \int_0^1 \frac{1}{1 + x^2} dx

using a simple midpoint method.  We will break the domain :math:`[0,
1]` into :math:`N` intervals, and spread those over the different MPI
processes.

.. literalinclude:: ../../examples/parallel/mpi/pi.cpp
   :language: c++
   :caption: ``pi.cpp``

