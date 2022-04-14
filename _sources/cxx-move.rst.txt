**************
Move Semantics
**************

.. admonition:: reading

   Cyganek section 4.5

   `Rvalue references and move constructors <https://en.wikipedia.org/wiki/C%2B%2B11#Rvalue_references_and_move_constructors>`_


.. tip::

   We are discussing this for completeness, but move semantics can be complicated.
   I'll show a "simple" example of a class that manages its own memory and implements
   move semantics.


C++11 introduced move semantics, which make it possible for objects to
take the data region from one another, instead of having to copy.  We
first saw this when we did our orbit integrator and returned a
``std::vector`` from our function (see :ref:`sec:more_functions`).


For objects that store large data regions, move is much faster than a
copy.  The C++ compiler will know when it can use a move and
automatically do it for you.

.. note::

   This is where the Rule of 3 becomes the Rule of 5: now we consider
   the (1) copy constructor, (2) assignment operator, (3)
   destructor, (4) move constructor, (5) move assignment operator.  If
   we write any one of these, we should write all 5.

Right-value references
======================

To allow for move operations, C++11 introduced *right-value
references* or *rvalue references*.  These use ``&&`` and as the name
suggests, they can appear to the right of the assignment operator,
``=``.

The object that an rvalue reference is a temporary object and it is assumed that
it will never be used again, therefore we are free to steal its data.
This is sometimes called a *destructive read*


