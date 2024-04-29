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

   There is no separate C++ interface to the MPI library---we use the
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
you to set up communicators that are subgroups of the total number of
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

using a simple midpoint method.  We will break the loop over the
$N$ intervals in  :math:`[0,
1]`  across the different MPI
processes using a stride.

We have 2 communications here.

* At the start, one processor (we pick ``0`` since it will always
  exist) reads in the number of intervals and then *broadcasts* that
  to all the other processors.

* At the end of the integration, we do a *reduce* to add up the partial
  sums from each processor into the total.  In our case, we only add them
  up on processor ``0``, since that's out I/O processor.

.. literalinclude:: ../../examples/parallel/mpi/pi.cpp
   :language: c++
   :caption: ``pi.cpp``


MPI Concepts
============

With MPI, a separate instance of your program is run on each
processor---these are the MPI processes.  We don't need to worry about
thread-safety is not an issue here, since each instance of the program
is isolated from the others.

A few considerations:

* You need to tell the library the datatype of the variable you are communicating and how big it is (the buffer size).

  * Together with the address of the buffer specify what is being sent

* Processors can be grouped together

  * Communicators label different groups

  * ``MPI_COMM_WORLD`` is the default communicator (all processes)

MPI has many types of operations, including:

  * Send / receive

  * Collective communications (broadcast, gather/scatter, reduce)

On supercomputers, system vendors will often provide their own MPI
implementation that is tuned to their hardware / network.  On your own
machine, `MPICH <https://www.mpich.org/>`_ is a popular
implementation.


