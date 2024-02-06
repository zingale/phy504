*******************
A First C++ Project
*******************

.. admonition:: reading

   Cyganek section 2.5 has a different first project (an interest calculator)
   than we do here.

Kepler's third law
==================

`Kepler's third law <https://en.wikipedia.org/wiki/Kepler%27s_laws_of_planetary_motion>`_ 
relates the period of a planet's orbit, $P$, to its semi-major axis, $a$:

.. math::

   P^2 = a^3

.. note::

   This version has $P$ in years and $a$ in astronomical units and the
   mass of the Sun in solar masses.  In those units, the gravitational
   constant is $G = 4 \pi^2$.

We want to write a program that allows us to specify either $P$ or $a$
and print the other quantity.


Looking at this expression, we need to learn how to raise something to
a power.  In C++, this is done by the ``std::pow()`` function, which
is part of ``cmath``.

Let's try this out:

.. code:: c++

   #include <cmath>
   #include <iostream>

   int main() {

      std::cout << std::pow(2.0, 3.0) << std::endl;

   }



We need to tell C++ what type of data we are going to be
storing.  We'll talk about data types next, but for now we'll use
``double``, which is double precision floating point format (more on
that later).

.. important::

   C++ is statically typed---this means we need to declare what type
   of data is to be stored in each variable we use before we can use
   that variable.  For instance:

   .. code:: c++

      double P;

   creates a variable ``P`` that can store a double precision number.


We will also want to take input.  For this we need to use ``std::cin``.  Let's look how this works:

.. code:: c++

   #include <iostream>

   int main() {
      double P = 0.0;
      std::cout << "Enter the period (P): ";
      std::cin >> P;

      std::cout << "P = " << P << std::endl;
   }

Notice that we initialize ``P`` to ``0.0`` just to be safe (we'll see
a more compact way of initializing later).

Now we will look at the complete code.  We shouldn't be expected to be
able to write something like this yet, but this will show us some of
the C++ constructs that we will learn in the next weeks.

.. literalinclude:: ../../examples/interest/interest.cpp
   :language: c++
   :caption: ``interest.cpp``
