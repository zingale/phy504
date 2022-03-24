*****************************
Example: Mathematical Vectors
*****************************

Consider a two-dimension vector:

.. math::

   \vec{v} = a \hat{x} + b \hat{y}

We know that we can add and subtract vectors, multiply and divide by a
scalar, and do operations like dot and cross products.

Let's write a class that manages a 2-d vector and learn how to
`overload the basic mathematical operators
<https://en.cppreference.com/w/cpp/language/operators>`_.

.. tip::

   Operators still follow the standard precedence even when overloaded.

Let's imagine that we have a class ``Vector2d`` that stores the ``x``
and ``y`` value of a two-dimensional vector.  What are some things
we'd like to be able to do with a vector?

We'd like to be able to output it:

.. code:: c++

   Vector2d v;

   std::cout << v << std::endl;

we already saw that this is controlled by the ``std::ostream
operator<< ()`` function.  This is an example over operator
overloading.  In this case, we want to make ``<<`` understand our
``Vector2d`` class.

We'd also like to be able to add and subtract:

.. code:: c++

   Vector2d v1;
   Vector2d v2;

   auto v3 = v1 + v2;
   auto v4 = v1 - v2;

In this case, the ``+`` and ``-`` operations will return a new ``Vector2d``.

What if we want to change ``x`` or ``y`` directly in a ``Vector2d``?
We will make the data private (this is a form of `encapsulation
<https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)>`_).
So we will create *setters* that allow us to change these values.

Here's an implementation:

.. literalinclude:: ../../examples/vector_class/vector2d.H
   :language: c++
   :caption: ``vector2d.H``


