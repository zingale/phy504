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

The C++ standard library has these methods and more for us to use in the
`random <https://www.cplusplus.com/reference/random/>`_ library.

.. caution::

   Some (historical) pseudo-random number generators provided by compiler
   vendors have been "truly horrible", such as the `IBM RANDU generator <https://en.wikipedia.org/wiki/RANDU>`_.

Uniform distribution
--------------------

Here's a simple example of a uniform random number distribution:

.. literalinclude:: ../../examples/numerical_algorithms/random/test_random.cpp
   :language: c++
   :caption: ``test_random.cpp``

Some notes:

* In C++ ``<random>``, the generator and distribution are separate
  concepts.  Here we pick the Mersenne Twister ``std::mt19937``
  generator and use it with the uniform distribution
  ``std::uniform_real_distribution``.

* To initialize the generator, we use ``std::random_device``---this is a true
  random number generator (depending on system support) and will provide a seed
  as the starting point for our pseudo-random number generator.

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

Sometimes we want reproducible random numbers---i.e. we want the sequence of numbers we
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


.. _sec:computing_pi:

Example: computing :math:`\pi`
==============================

A fun way to compute :math:`\pi` is to pick pairs of random numbers in
the range :math:`[0, 1)`---these will all fall inside a unit square,
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


Example: Hypersphere Volume
===========================

Consider a $d$-dimensional hypersphere with radius 1 defined on a domain $[-1, 1]^d$.
The volume is:

.. math::

   V_d(R) = \frac{\pi^{d/2}}{\Gamma \left (\tfrac{d}{2} + 1\right )} R^d

We can integrate this using Monte Carlo methods.

Mean value integration works by sampling the domain that the function is defined on
to estimate the mean.  In one-dimension, we know:

.. math::

   \langle f \rangle = \frac{1}{b - a} \int_a^b f(x) dx = \frac{I}{b -a}

where $I$ is the integral we desire:

.. math::

   I = \int_a^b f(x) dx

This means we can approximate $I$ by doing $N$ samples as:

.. math::

   I \approx \frac{b - a}{N} \sum_{i = 1}^{N} f(x_i)

where $x_i$ is a randomly selected point in $[a, b]$.

This extends to an arbitrary dimension easily, as:

.. math::

   I = \int_\omega f(x_0, x_1, \ldots x_{d-1}) dx_0 dx_1, \ldots dx_{d-1} \approx
         \frac{V}{N} \sum_{i = 1}^{N} f({\bf x}_i)

where ${\bf x}_i$ is a randomly-selected point in the $d$-dimensional domain.

For $d > 3$, Monte Carlo integration is usually less computationally-expensive than
doing the trapezoid rule in each dimension.

Here's an example of computing the volume of the $d$-dimensional hypersphere using
mean-value Monte Carlo integration:

.. literalinclude:: ../../examples/numerical_algorithms/monte_carlo_integration/hypersphere.cpp
   :language: c++
   :caption: ``hypersphere.cpp``

Here's the output for $d = 5$:

::

   Enter dimensionality of the hypersphere: 5
   samples:      10; volume = 12.8
   samples:     100; volume = 8.32
   samples:    1000; volume = 5.504
   samples:   10000; volume = 5.2416
   samples:  100000; volume = 5.31168
   samples: 1000000; volume = 5.26419
   analytic result: 5.26379

