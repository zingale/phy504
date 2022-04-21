************
Root finding
************

Given a function :math:`f(x)`, the *root-finding* problem is to find
all of the :math:`x` such that :math:`f(x) = 0`.

Bisection
=========


Newton's method
===============


Implementation
==============

We want to write a function that takes as input the function we want to zero.





Here's the header that implements both bisection and Newton's method:

.. literalinclude:: ../../examples/numerical_algorithms/roots/roots.H
   :language: c++
   :caption: ``roots.H``



A few features:

* We use a ``namespace`` to hold the parameters that affect the
  behavior of the root finding algorithms.  This ensures that if we
  ``#include "roots.H"`` in a file, these names don't conflict with
  any that might be locally defined.

* We use both a relative and absolute tolerance for assessing the error.  Convergence
  is met when:

  .. math::

     \epsilon < \mathrm{RTOL} |x_0| + \mathrm{ATOL}

  This ensures that if the current estimate of the root, :math:`x_0`,
  is close to zero then :math:`\mathrm{ATOL}` is used but if the root
  :math:`x_0` is large, then :math:`\mathrm{RTOL}` use used for the
  error.
