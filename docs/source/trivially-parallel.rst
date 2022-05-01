**************************
Trivially Parallel + BASH
**************************

Sometimes we have to run an analysis tool on a large number of files,
but each analysis is completely independent of the others.  This is a
*trivially parallel* application.

We can manage the analysis via a Bash script that looks for available
CPUs and starts up jobs as resources become free.

The basic flow is:

* Loop over files

  * Run jobs until all the processors are full

  * Use lockfiles to indicate when a job is running

  * When resources become free, start up the next job

Here's an implementation:

.. literalinclude:: ../../example/parallel/bash/parallel.sh
   :language: bash
   :caption: ``parallel.sh``

This looks for files with the name ``plt*`` and then runs an analysis
tool on them (for this simple example, it is just ``echo``).  You can
control the number of processors that are used at the top of the
script.

