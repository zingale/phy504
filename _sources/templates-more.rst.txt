*****************
More On Templates
*****************

``static_assert``
=================

Notice that we can create an ``Array<std::string>`` -- but that's really not our intent,
and we are likely going to do things that only make sense with numbers.

.. code:: c++

   Array<std::string> x(5, 5, "x");

We can add a ``static_assert`` to disallow this -- a static assert is evaluated at compile time.
Just instead of our ``Array`` constructor, we just add:

.. code:: c++

   static_assert (std::is_arithmetic_v<T>);

This ensures that ``T`` is an arithmetic type (integer or floating point type).

There are additional type checks like ``is_integral_v`` and ``is_floating_point_v``

.. tip::

   The ``_v`` versions of these checks were introduced in C++17.  For C++11, you would do:

   .. code:: c++

      static_assert (std::is_arithmetic<T>::value);


