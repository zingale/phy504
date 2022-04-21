*******************
Monte Carlo Methods
*******************

Monte Carlo methods involve using random numbers to produce different
realizations of a system and then building up statistics.


Pseudo-random numbers
=====================

Generally, producing truly random numbers is hard and we most often
use *pseudo-random* numbers.  These should have the following properties:

* The are fast to generate

* Each number is not correlated with the one that came before it

* They uniformly sample the range of interest (usually :math:`[0, 1)`)


Example: computing :math:`\pi`
==============================

A fun way to compute :math:`\pi` is to pick pairs of random numbers in
the range :math:`[0, 1)` -- these will all fall inside a unit square,
but we also check to see if they fall inside a circle of diameter
``1`` inscribed inside the unit square.

We can write

.. math::

   \pi = \frac{\pi (d/2)^2}{d^2} = \frac{A_\mathrm{circle}}{A_\mathrm{square}}

We then pick a large number (:math:`N`) of random number pairs.  We
approximate the area of the circle and square as simply the number of
random pairs that fall inside each shape.  If we call the number of
random numbers that fall inside the circle :math:`N_\mathrm{circle}`
and note that all :math:`N` fall inside the square, so we can
approximate :math:`\pi` as:

.. math::

   \pi \approx \frac{N_\mathrm{circ}}{N}
