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



What happens when we do:

.. code::

   Vector2d v1(1.0, 2.0);

   auto v2 = v1;

?

This invokes the *copy constructor*, which should look like:

.. code::

   Vector2d (const Vector2d &v);

but we didn't write this.  It turns out that C++ will automatically generate
the copy constructor for us, and in most cases, it will work fine.  Only
if we have complicated member data (like pointers) would we need to explicitly write
the copy.

There is another special function that we haven't talked about -- the
`*destructor*
<https://en.cppreference.com/w/cpp/language/destructor>`_.  This cleans
up an objects resources when it goes out of scope, the program ends, or
an object is explicitly deleted.  For our class, the resources are just 2 doubles,
which C++ can handle on its own.

.. tip::

   The `Rule of Three <https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)>`_
   says that if you define any of: the *destructor*, *copy constructor*, or *copy assignment*,
   then you should define all three.




