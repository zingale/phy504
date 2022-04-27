*******************
Monte Carlo Methods
*******************

Monte Carlo methods involve using random numbers to produce different
realizations of a system and then building up statistics.


Pseudo-random numbers
=====================

Generally, producing truly random numbers is hard and we most often
use `pseudo-random numbers
<https://en.wikipedia.org/wiki/Pseudorandom_number_generator>`_.
These should have the following properties:

* The are fast to generate

* Each number is not correlated with the one that came before it (actually, there
  are a number of statistical tests they should satisfy).

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

Uniform distribution
--------------------

Here's a simple example of a uniform random number distribution:

.. literalinclude:: ../../examples/numerical_algorithms/random/test_random.cpp
   :language: c++
   :caption: ``test_random.cpp``

Notice that each time we run it we get a different sequence of random numbers.

Other distributions
-------------------
We can create other distributions.  Imagine that :math:`q(z)` is the probably of getting
a number between :math:`z` and :math:`z +dz`.  For the uniform distribution, :math:`q(z) = 1`.
We want to find an :math:`x(z)` that maps the uniformly-distributed numbers into another distribution.
Since the total probability is :math:`1`, we require:

.. math::

   p(x) dx = q(z) dz

where :math:`p(x)` will be the new distribution function.  Integrating
this allows us to map the uniform distribution to other distributions.

.. tip::

   The cppreference site has a `nice example of a normal distributon
   <https://en.cppreference.com/w/cpp/numeric/random/normal_distribution>`_
   that also introduces ``std::map`` to hold "key:value" pairs.

Seeding
-------

Sometimes we want reproducible random numbers -- i.e. we want the sequence of numbers we
get to be random but we want to get the same sequence each time we run.  To accomplish
this, we can explicitly feed a seed into our random generator:

.. code:: c++

   std::mt19937 generator(12345);

To do better, you can use ``std::seed_seq``
(https://en.cppreference.com/w/cpp/numeric/random/seed_seq) to build a
better seed:

.. code:: c++

   std::seed_seq seed{1, 2, 3, 4, 5};
   std::mt19937 generator(seed);

.. warning::

   For applications that require security, you need to be more
   careful.  But for physics simulations where we are not worried
   about someone being able to guess our sequence, seeding allows for
   reproducibility, and is good for testing.



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

Here's an implementation of our computing :math:`\pi`:

.. literalinclude:: ../../examples/numerical_algorithms/random/pi.cpp
   :language: c++
   :caption: ``pi.cpp``
