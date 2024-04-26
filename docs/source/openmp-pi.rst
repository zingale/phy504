******************************
OpenMP Monte Carlo :math:`\pi`
******************************

Let's parallelize our :ref:`Monte Carlo example of computing pi <sec:computing_pi>`.

.. important::

   We want each thread to have *independent* random numbers.  We do
   this by creating a random number generator separately on each thread with
   different seeds.

   See, e.g., https://stackoverflow.com/questions/37305104/how-to-generate-random-numbers-in-a-thread-safe-way-with-openmp

   There is a worry still---if you are sampling a large fraction of
   the period of the pseudo-random number generator, than it is
   possible that the sequences will overlap.  This is discussed
   in the `SC08 presentation by Tim Mattson & Larry Meadows <https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf>`_ (look around slide 130).

.. tip::

   The Merseene twister has
   a period of $2^{19937}-1$, so it is unlikely for overlap to be an
   issue.

.. note::

   True parallel random number generators exist, where a
   single thread controls the generator and gives the numbers
   to each thread as needed.

   See also: `Improved Long-Period Generators Based on Linear Recurrences Modulo 2 <https://www.iro.umontreal.ca/~lecuyer/myftp/papers/lfsr04.pdf>`_
   by Panneton and L'Ecuyer.

Then this calculation can proceed in a trivially parallel fashion.
The only thing we need to do is mark the sum for a reduction at the
end of the parallel region.

.. literalinclude:: ../../examples/parallel/openmp/random_pi/pi.cpp
   :language: c++
   :caption: ``pi.cpp``

.. tip::

   There is one further trick here---all of the OpenMP stuff is
   wrapped in ``#ifdef _OPENMP``---the ``_OPENMP`` preprocessor
   variable is defined by the standard if we are building with OpenMP.
   By wrapping those features, this allows the code to be compiled
   without OpenMP if we desire.


.. tip::

   Other types of random number generators exist, beyond those in the C++ SL.
   Here's an example of a header-only library that works on CPUs and GPUs:
   `random123 <https://github.com/DEShawResearch/random123>`_.


