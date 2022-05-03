******************************
OpenMP Monte Carlo :math:`\pi`
******************************

Let's parallelize our :ref:`sec:computing_pi`.

We now want each thread to have independent random numbers.  We do
this by creating a random number generator separately on each thread.
To future ensure that they are independent, we create a different seed
on each thread.

Then this calculation can proceed in a trivially parallel fashion.
The only thing we need to do is mark the sum for a reduction at the
end of the parallel region.

.. literalinclude:: ../../examples/parallel/openmp/random_pi/pi.cpp
   :language: c++
   :caption: ``pi.cpp``

.. tip::

   There is one further trick here -- all of the OpenMP stuff is
   wrapped in ``#ifdef _OPENMP`` -- the ``_OPENMP`` preprocessor
   variable is defined by the standard if we are building with OpenMP.
   By wrapping those features, this allows the code to be compiled
   without OpenMP if we desire.


