*******
Casting
*******

Sometimes we want to change the data type of an object---this is called *casting*.
There are several different types of casts in C++.  We'll look at ``static_cast``,
which is interpreted at compile time.

Here's an example:

.. literalinclude:: ../../examples/casting/cast_example.cpp
   :language: c++
   :caption: ``cast_example.cpp``

We use ``static_cast<double>`` to promote an ``int`` to a ``double`` before doing the division.
