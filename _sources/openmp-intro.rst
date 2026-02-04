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


Compiler support
================

In order to build an OpenMP application, you need a compiler that
supports it.  Fortunately, most recent compilers support OpenMP.  For
g++, the OpenMP standards are fully supported (up to version 5.0)

See this table for `compiler support for OpenMP <https://www.openmp.org/resources/openmp-compilers-tools/>`_.


Threads
=======

In an OpenMP application, threads are spawned as needed.

* When you start the program, there is one thread---the master thread

* When you enter a parallel region, multiple threads run concurrently

This looks like:

.. figure:: 1280px-Fork_join.svg.png
   :align: center

   (A1 / Wikipedia)




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

* OpenMP directives are specified via ``#pragma omp``

* When we run this, the threads are all printing independent of one
  another, so the output is all mixed up.  Run it again and you'll see
  a different ordering.

* There are a few library functions that we access, by including ``omp.h``


Critical regions
================

We can use a *critical region* in an OpenMP parallel region to force
the threads to operate one at a time.  For example, in the above
``hello.cpp``, we can get the prints to be done one at a time as:

.. literalinclude:: ../../examples/parallel/openmp/hello-critical.cpp
   :language: c++
   :caption: ``hello-critical.cpp``



Controlling the number of threads
=================================

The easiest way to control the number of threads an OpenMP application
uses is to set the ``OMP_NUM_THREADS`` environment variable.  For
instance, you can set it globally in your shell as:

.. prompt:: bash

   export OMP_NUM_THREADS=2

or just for the instance of your application as:

.. prompt:: bash

   OMP_NUM_THREADS=2 ./hello

.. tip::

   Your code will still run if you specify more threads than there are
   cores in your machine.  On a Linux machine, you can do:

   .. prompt:: bash

      cat /proc/cpuinfo

   To see the information about your processor and how many cores Linux thinks
   you have.

   Note: modern processors sometimes use hyperthreading, which makes a
   single core look like 2 to the OS.  But OpenMP may not benefit from
   this hardware threading.



Parallelizing Loops
===================

Here's a matrix-vector multiply:

.. literalinclude:: ../../examples/parallel/openmp/matmul.cpp
   :language: c++
   :caption: ``matmul.cpp``


.. warning::

   There is an overhead associated with spawning threads, and some
   regions might not have enough work to offset that overhead.  Some
   experimentation may be necessary with your application.


.. tip::

   We cannot put the ``{`` on the same line as the ``#pragma``, since the
   ``#pragma`` is dealt with by the preprocessor.  So we do:

   .. code:: c++

      #pragma omp parallel
      {
        ...
      }

   and not

   .. code:: c++

      #pragma omp parallel {
        ...
      }

One thing we want is for the performance to scale with the number of
cores---if you double the number of cores, does the code run twice as
fast?

Reductions
==========

Reductions (e.g., summing, min/max) are trickier, since each thread
will be updating its local sum or min/max, but then at the end of the
parallel region, a reduction over the threads needs to be done.

A reduction clause takes the form:

.. code:: c++

   #openmp parallel reduction (operator | variable)

Each thread will have its own local copy of ``variable`` and they will
be reduced into a single quantity at the end of the parallel region.

The possible operators are listed here: https://www.openmp.org/spec-html/5.0/openmpsu107.html
and include:

* ``+`` for summation
* ``-`` for subtraction
* ``*`` for multiplication
* ``min`` for finding the global minimum
* ``max`` for finding the global maximum

Here's an example where we construct the sum:

.. math::

   S = \sum_{i = 0}^{N-1} \left [ e^{i \% 5} - 2 e^{i \% 7} \right ]

.. note::

   This will give slightly different answers depending on the number of threads
   because of different roundoff behavior.

.. literalinclude:: ../../examples/parallel/openmp/reduce.cpp
   :language: c++
   :caption: ``reduce.cpp``


