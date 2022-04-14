**************
Move Semantics
**************

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

