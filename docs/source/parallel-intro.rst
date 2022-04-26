************************************
Introduction to Parallel Programming
************************************

Modern computers have multiple CPU cores.  So far, we've only been
doing work on a single core, but a lot of computational physics
numerical work can be spread across multiple CPUs.

A lot of the considerations in parallel program involve how we access
the memory where the data is stored.  There are generally two
approaches:

* shared memory: all computing cores have direct access to the memory
  (perhaps not all with the same speed though)

  OpenMP is a popular approach here.

* distributed memory: the memory is separated in ways that only
  certain cores can access certain pools of memory.  This could be,
  for example, because the computer is a cluster comprised of multiple
  computers (nodes) connected via a high-speed network.

  MPI is a popular approach here.

Often we will do a little of each -- shared memory parallelism inside
a compute node and distributed memory parallelism across nodes.
