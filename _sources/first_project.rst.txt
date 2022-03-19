*******************
A First C++ Project
*******************

.. admonition:: reading

   Cyganek section 2.5

Compound interest
=================

We want to write a program that calculates compound interest.  The general expression for this is:

.. math::

   A = P \left ( 1 + \frac{r}{n} \right )^{nt}

where

* :math:`P` is the principal

* :math:`r` is the interest rate on an annual basis (in units of 1 / year)

* :math:`n` is the compounding frequency (in units of 1 / year)

* :math:`t` is the investment time (in units of years)

* :math:`A` is the final amount

.. note::

   I am expressing this differently than you text, which seems to use
   somewhat non-standard notation.

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

   C++ is statically typed -- this means we need to declare what type
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
      std::cout << "Enter the principal (P): ";
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

Letter histogram
================

Your text has another example problem that shows how to create a
histogram of the frequency of letters in a word.  It introduces a few
more concepts.  Here is the implementation from your text:

https://github.com/BogCyg/BookCpp/blob/master/CCppBookCode/src/letter_histogram.cpp
