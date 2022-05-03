***
MPI
***

In contrast to OpenMP, MPI does not use directives / pragmas to
specify the parallelism, but instead we call functions.  The `MPI
standard <https://www.mpi-forum.org/>`_ is big, but we only actually
need a few routines to be able to express any type of parallelism.
However, the additional capabilities allow us to do things more
efficiently.


.. note::

   There is no separate C++ interface to the MPI library -- we use the
   C interface.  This means that the functions accept arguments as
   pointers and not references, so we need to pass the address of the
   data we are using.

Hello, World
============

Here's a "Hello, World!" with MPI.  Every MPI application begins with
``MPI_Initialize()`` and end with ``MPI_Finalize()``.  Note that
``MPI_Initialize()`` can take 2 arguments that are the command line
parameters passed into the code.  Since we are not using this, we pass
``nullptr``.

There are 2 other function we use here:

* ``MPI_Comm_size()`` : this tells us the total number of MPI processes

* ``MPI_Comm_rank()`` : this tells us which processor the current
  program represents out of the total number used by MPI.

.. literalinclude:: ../../examples/parallel/mpi/hello.cpp
   :language: c++
   :caption: ``hello.cpp``

There is one additional bit that we won't explore here.  MPI allows
you to setup communicators that are subgroups of the total number of
processors.  This can be useful to divide tasks up between the total
number of processors.  We'll stick to ``MPI_COMM_WORLD`` which
represents all processors.

To compile this, we need to supply the path where the header file is
located as well as explicitly link in the libraries we use.
Thankfully, most MPI implementation provide a wrapper for that: ``mpic++``:

.. prompt:: bash

   mpic++ -o hello hello.cpp

This will pass any compiler flags onto the actual compiler, so we can
use this the same way we've been using ``g++``.


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

