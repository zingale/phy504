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

