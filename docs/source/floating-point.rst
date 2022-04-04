**************
Floating Point
**************

.. admonition:: reading

   `What Every COmputer Scientist Should Know About Floating-Point Arithmetic <https://dl.acm.org/doi/10.1145/103162.103163>`_


We can think of a floating point number as having the form:

.. math::

   \mbox{significand} \times 10^\mbox{exponent}

Most computers follow the IEEE 754 standard for floating point, and we commonly work
with 32-bit and 64-bit floating point numbers (single and double precision).  These bits
are split between the signifcand and exponent as well as a single bit for the sign:

.. figure:: 1024px-IEEE_754_Double_Floating_Point_Format.svg.png
   :align: center
   :width: 80%

Since the number is stored in binary, we can think about expanding a number in powers of 2:

.. math::

   0.1 \sim (1 +
             1 \cdot 2^{-1} +
             0 \cdot 2^{-2} +
             0 \cdot 2^{-3} +
             1 \cdot 2^{-4} +
             1 \cdot 2^{-5} + \ldots) \times 2^{-4}

Roundoff vs. truncation error
==============================

Consider the Taylor expansion of :math:`f(x)` about some point :math:`x_0`:

.. math::

   f(x) = f(x_0 + \Delta x) = f(x_0) + \left . \frac{df}{dx} \right |_{x_0} \Delta x + \mathcal{O}(\Delta x^2)

where :math:`\Delta x = x - x_0`

We can solve for the derivative to find an approximation for the first derivative:

.. math::

   \left . \frac{df}{dx} \right |_{x_0} = \frac{f(x_0 + \Delta x) - f(x_0)}{\Delta x} + \mathcal{O}(\Delta x)

This shows that this approximation for the derivative is first-order accurate in :math:`\Delta x` -- that is the truncation error of the approximation.

We can see the relative size of roundoff and truncation error by using this approximation
to compute a derivative for different values of :math:`\Delta x`:

.. literalinclude:: ../../examples/roundoff/truncation_vs_roundoff.cpp
   :language: c++
   :caption: ``truncation_vs_roundoff.cpp``

when we run this, we get:

::

   1.00000000e-01 4.29385533e-02
   5.00000000e-02 2.12574901e-02
   2.50000000e-02 1.05741192e-02
   1.25000000e-02 5.27319544e-03
   6.25000000e-03 2.63310585e-03
   3.12500000e-03 1.31567674e-03
   1.56250000e-03 6.57618923e-04
   7.81250000e-04 3.28754549e-04
   3.90625000e-04 1.64363540e-04
   1.95312500e-04 8.21783356e-05
   9.76562500e-05 4.10883092e-05
   4.88281250e-05 2.05439403e-05
   2.44140625e-05 1.02719161e-05
   1.22070313e-05 5.13594041e-06
   6.10351563e-06 2.56797303e-06
   3.05175781e-06 1.28400298e-06
   1.52587891e-06 6.41936098e-07
   7.62939453e-07 3.20993608e-07
   3.81469727e-07 1.60631502e-07
   1.90734863e-07 8.05959686e-08
   9.53674316e-08 3.92685293e-08
   4.76837158e-08 1.94779246e-08
   2.38418579e-08 1.24930053e-08
   1.19209290e-08 3.17977955e-09
   5.96046448e-09 3.17977955e-09
   2.98023224e-09 1.54466719e-08
   1.49011612e-09 5.90591340e-08
   7.45058060e-10 5.90591340e-08
   3.72529030e-10 8.99524779e-08
   1.86264515e-10 8.99524779e-08
   9.31322575e-11 5.06093970e-07
   4.65661287e-11 5.06093970e-07
   2.32830644e-11 1.87809182e-06
   1.16415322e-11 1.87809182e-06
   5.82076609e-12 7.65865134e-06
   2.91038305e-12 1.14148350e-05
   1.45519152e-12 1.14148350e-05
   7.27595761e-13 1.14148350e-05
   3.63797881e-13 1.41173056e-04
   1.81898940e-13 1.41173056e-04
   9.09494702e-14 4.69178507e-04
   4.54747351e-14 1.68988163e-03
   2.27373675e-14 3.19293087e-03
   1.13686838e-14 3.19293087e-03
   5.68434189e-15 6.57269413e-03
   2.84217094e-15 6.57269413e-03
   1.42108547e-15 7.15523059e-02
   7.10542736e-16 7.15523059e-02
   3.55271368e-16 8.46976941e-02

It is easier to see the trend if we make a plot:

.. figure:: error_plot.png
   :align: center
   :width: 80%

Let's discuss the trends:

* Starting with the largest value of :math:`\Delta x`, as 
  we make :math:`\Delta x` smaller, we see that the error decreases.
  This is following the expected behavior of the truncation error
  derived above.

* Once our :math:`\Delta x` becomes really small, roundoff error starts
  to dominate.  In effect, we are seeing that:

  .. math::

     (x_0 + \Delta x) - x_0 \ne 0

  because of roundoff error.

* The minimum error here is around :math:`\sqrt{\epsilon}`, where :math:`\epsilon` is
  machine epsilon.


Testing for equality
====================

Because of roundoff error, we should never exactly compare two floating point numbers,
but instead ask they they agree within some tolerance.


Minimizing roundoff
===================

Consider subtracting the square of two numbers -- taking the difference of two very close-in-value numbers is a prime place where roundoff can come into play.

Instead of doing:

.. math::

   x^2 - y^2

we can instead do:

.. math::

   (x - y)(x + y)

by factoring this, we are subtracting more reasonably sized numbers, reducing the roundoff.

We can see this directly by doing this with single precision (`float`) and comparing to an answer computed via double precious (`double`)

Here's an example:

.. literalinclude:: ../../examples/roundoff/subtraction.cpp
   :language: c++
   :caption: ``subtraction.cpp``


