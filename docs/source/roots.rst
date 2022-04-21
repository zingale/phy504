************
Root finding
************

Given a function :math:`f(x)`, the *root-finding* problem is to find
all of the :math:`x` such that :math:`f(x) = 0`.

Bisection
=========



Newton's method
===============

For `Newton's method
<https://en.wikipedia.org/wiki/Newton's_method>`_, we start by Taylor
expanding the function about some initial guess for the root,
:math:`x_0`:

.. math::

   f(x_0 + \delta x) \approx f(x_0) + \left . \frac{df}{dx} \right |_{x_0} + ...

if :math:`x_0` is close to the actual root, then :math:`\delta x` is a correction that
will bring it closer to the actual root, and the higher order terms in this expansion
will be small, so we can neglect them.  This tells us that the correction is:

.. math::

   \delta x = -\frac{f(x_0)}{df/dx|_{x_0}}

Then we can correct our guess:

.. math::

   x_0 \leftarrow x_0 + \delta x

and iterate on this procedure until :math:`|\delta x|` is small.

There are a few things to note here:

* The initial guess needs to be good -- if it is not, then the higher
  order terms, which start with :math:`\delta x^2` are not small, and
  we should not have neglected them.

* We need a good estimate of the derivative.  Ideally this means that we
  supply a function that computes the derivative analytically.

* Newton's method can fail in a variety of ways, including `entering a cycle <https://en.wikipedia.org/wiki/Newton's_method#Starting_point_enters_a_cycle>`_.



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
