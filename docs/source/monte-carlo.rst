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

There are a few popular methods for `generating pseudo-random numbers
<https://en.wikipedia.org/wiki/Pseudorandom_number_generator>`_,
including:

* `linear congruential generators
  <https://en.wikipedia.org/wiki/Linear_congruential_generator>`_ :
  these are easy to code up and fast but don't give the best
  statistical properties.

* `Mersenne twister <https://en.wikipedia.org/wiki/Mersenne_Twister>`_ :
  this method is one of the most widely used now and generates good quality
  random numbers.  It is more complicated to code up.

The C++ standard library has these methods and more for us to use.

Here's a simple example of a uniform random number distribution:

.. literalinclude:: ../../examples/random/test_random.cpp
   :language: c++
   :caption: ``test_random.cpp``

Other distributions exist, like a normal distribution.

.. tip::

   The cppreference site has a `nice example of a normal distributon
   <https://en.cppreference.com/w/cpp/numeric/random/normal_distribution>`_
   that also introduces ``std::map`` to hold "key:value" pairs.

Example: computing :math:`\pi`
==============================

A fun way to compute :math:`\pi` is to pick pairs of random numbers in
the range :math:`[0, 1)` -- these will all fall inside a unit square,
but we also check to see if they fall inside a circle of diameter
``1`` inscribed inside the unit square.

We can write

.. math::

   \frac{A_\mathrm{circle}}{A_\mathrm{square}} = \frac{\pi (d/2)^2}{d^2} = \frac{\pi}{4}

We then pick a large number (:math:`N`) of random number pairs.  We
approximate the area of the circle and square as simply the number of
random pairs that fall inside each shape.  If we call the number of
random numbers that fall inside the circle :math:`N_\mathrm{circle}`
and note that all :math:`N` fall inside the square, so we can
approximate :math:`\pi` as:

.. math::

   \pi \approx 4 \frac{N_\mathrm{circ}}{N}
