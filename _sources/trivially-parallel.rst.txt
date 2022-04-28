**************************
Trivially Parallel + BASH
**************************

Sometimes we have to run an analysis tool on a large number of files,
but each analysis is completely independent of the others.  This is a
*trivially parallel* application.

We can manage the analysis via a Bash script that looks for available
CPUs and starts up jobs as resources become free.
