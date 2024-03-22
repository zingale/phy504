.. _sec:vector2d:

*****************************
Example: Mathematical Vectors
*****************************

Consider a two-dimension mathematical vector:

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

Some notes:

* We explicitly mark the member data as private and the functions are public

* We have 2 constructors: the *default constructor* and a *parametric
  constructor*.  These both have the same name---that's fine, C++
  will call which ever one matches the argument list you use.

* We have 2 *setter* functions to modify the underlying vector data:

  .. code:: c++

     inline void set_x(double _x) {x = _x;}
     inline void set_y(double _y) {y = _y;}

  These are marked ``inline``, which is a hint to the compiler that
  it can replace the function call with just inserting the code where
  it is needed.  This gives us better performance.

* We have 3 operators that are member functions: ``+``, and two implementations of ``-``.
  The second ``-`` has the form:

  .. code:: c++

     Vector2d operator-();

  This is the *unary minus*, and is invoked when we do ``-v`` for a ``Vector2d v``.

* The stream operator, ``<<``, has the keyword ``friend``.  This is
  needed since technically this function is not a member of the class,
  but it needs to have access to the private member data.

  As an alternate to making this a ``friend``, we could have added *getter*
  functions to our class to get the private data.

.. hint::

   In the operator-overload function

   .. code:: c++

      Vector2d operator+(const Vector2d& vec)  {}

   ``vec`` is a second ``Vector2d`` object that we are going to
   add to our current one.  So why can we access the private data of ``vec``?
   i.e., ``vec.x`` and ``vec.y``?

   This is part of the design of C++.  Two instances of the same class can access
   private data of one another directly.  The ``private`` attribute is enforced
   on a class-basis, not an object-basis.

   See this `stackoverflow discussion <https://stackoverflow.com/questions/6921185/why-do-objects-of-the-same-class-have-access-to-each-others-private-data>`_

.. hint::

   When do we need to make something a ``friend``?

   Essentially, it is needed for an operator where our class is not to
   the left of the operator.

   Imagine that it did make sense to add a ``double`` to a
   ``Vector2d``, then we could imagine 2 different additions:

   .. code:: c++

      double a{};
      Vector2d vec{};

      auto new_vec = a + vec;   // our class is on the right -- this is not a member func
      auto new2_vec = vec + a;  // our class is on the left -- this is a member func

   When we write a member function, we don't include the object itself
   in the argument list, so for the second case, ``vec + a``, we would
   use the function signature:

   .. code:: c++

      Vector2d operator+ (const double& a);

   The current ``Vector2d`` object is implicitly part of the function,
   and C++ provides a pointer called ``this`` that points to the
   address of the object that we are working on.

.. tip::

   There is a nice FAQ of operator overloading on stack overflow:

   `What are the basic rules and idioms for operator overloading? <https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading>`_


What happens when we do:

.. code:: c++

   Vector2d v1(1.0, 2.0);

   auto v2 = v1;

This invokes the *copy constructor*, which should look like:

.. code:: c++

   Vector2d (const Vector2d &v);

but we didn't write this.  It turns out that C++ will automatically generate
the copy constructor for us, and in most cases, it will work fine.  Only
if we have complicated member data (like pointers) would we need to explicitly write
the copy.

There is another special function that we haven't talked about---the
`destructor <https://en.cppreference.com/w/cpp/language/destructor>`_.
This cleans up an objects resources when it goes out of scope, the
program ends, or an object is explicitly deleted.  For our class, the
resources are just 2 doubles, which C++ can handle on its own.

.. tip::

   The `Rule of Three <https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)>`_
   says that if you define any of: the *destructor*, *copy constructor*, or *copy assignment*,
   then you should define all three.

Now let's test this out.  Here's a test driver:

.. literalinclude:: ../../examples/vector_class/test_vectors.cpp
   :language: c++
   :caption: ``test_vectors.cpp``

There are a wide range of other capabilities we could imagine adding
to this class to make it easier to work with vectors.

.. admonition:: try it...

   Try overloading ``>>`` so we can read directly into a ``Vector2d`` object, e.g.,

   .. code:: c++

      Vector2d v;

      cin >> v;

   Your function should look like:

   .. code:: c++

      friend std::istream& operator>>(std::istream& is, Vector2d &v);

   Notice that the ``Vector2d`` is not ``const``, since we will be modifying it.

   You will want to read 2 pieces of data from the input stream and directly
   set ``v.x`` and ``v.y``.



