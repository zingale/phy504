*************************
``auto`` and ``decltype``
*************************

.. admonition:: reading

   Cyganek section 3.7

We've already seen how using ``auto`` can make it easier to declare a
variable when the compiler can infer the proper type.

For instance, consider a vector:

.. code:: c++

   std::vector<int> int_vec{0, 1, 2, 3, 4, 5};

   auto it = int_vec.cbegin();

If we wanted to use the actual type for ``it``, we'd need to look in
the ``vector`` header file for the ``cbegin()`` function definition to
see what it returned (or use a smart IDE that could do that for us).
And then this is what we would have to write:

.. code:: c++

   std::vector<int>::const_iterator it = int_vec.cbegin();

That's a lot more verbose.  So using ``auto`` is a very convenient way
of declaring this iterator.

We could also use ``auto`` in situations like this:

.. code:: c++

   auto x{0.0};

Here the compiler will make ``x`` a ``double``, since we have a
floating point number in the initialization list, ``{}``.  But this
case is less useful, and perhaps less clear to someone reading the
code.  Usually when you are defining a variable, you have in mind what
type it should be, so erring on the side of being explicit is a good
idea.

Note that if we intended for ``x`` to be a ``const`` (and indeed,
``0.0`` is a const, so why didn't it deduce that?), then we need to be
explicit:

.. code:: c++

   const auto x{0.0};

Again, I would advise against using ``auto`` in this situation.

decltype
========

``decltype`` is in some ways the opposite of ``auto``.  Imagine that
we want to declare a new variable to be of the same type as an
existing one -- this is where ``decltype`` comes into play.

Here's an example:

.. literalinclude:: ../../examples/vectors/vector-decltype.cpp
   :language: c++
   :caption: ``vector-decltype.cpp``
