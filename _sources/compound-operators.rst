*****************************
Compound Assignment Operators
*****************************

.. tip::

   If a class defines ``+``, ``-``, ``*``, and ``/``, then it is a
   good practice to also define the corresponding compound assignment
   operators, ``+=``, ``-=``, ``*=``, and ``/=``.

The compound assignment operators provide a shorthand, e.g.:

.. code:: c++

   a += b

is the same as

.. code:: c++

   a = a + b

So when we overload the operator, we not only need to do the
arithmetic operation, but we need to return a reference to the object
we are operating on.

Back to our vector class, this means that our overloaded operator ``+=`` will have
the form:

.. code:: c++

   Vector2d& operator+= (const Vector2d& vec) {
       x += vec.x;
       y += vec.y;
       return *this;
   }

(since ``this`` is a pointer, we dereference it and return it via reference).

Here's a full implementation (adding to our previous ``vector2d.H``:

.. literalinclude:: ../../examples/more_classes/compound/vector2d.H
   :language: c++
   :caption: updated ``vector2d.H``

and here's a driver:

.. literalinclude:: ../../examples/more_classes/compound/compound_test_vectors.cpp
   :language: c++
   :caption: updated ``compound_test_vectors.cpp``



