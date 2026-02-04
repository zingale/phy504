****
Maps
****

.. admonition:: reading

   https://en.cppreference.com/w/cpp/container/map

A ``map`` holds a key-value pair, with the requirement that the key is unique.

.. tip::

   A C++ ``map`` is functionally the same as a dictionary in python.

Here's an example:

.. literalinclude:: ../../examples/map/map_example.cpp
   :language: c++
   :caption: ``map_example.cpp``

We use a `structured binding
<https://en.cppreference.com/w/cpp/language/structured_binding>`_ to
unpack the key and value into separate variables.

.. tip::

   If we instead loop over our map, ``a``, as:

   .. code:: c++

      for (auto e : a) {
          ...
      }

   Then ``e`` will be a ``std::pair`` object inside the loop.  We would then
   use ``e.first`` and ``e.second`` to access the key and value.

Notice that we can freely add to the ``map`` simply by using a new key.

In C++20, the ``contains()`` member function was added to maps to test
if a key is part of a map:

.. literalinclude:: ../../examples/map/map_contains.cpp
   :language: c++
   :caption: ``map_contains.cpp``

.. tip::

   To compile this, you likely need to add ``-std=c++20`` to the compilation
   line.

   For older versions of ``g++``, you may instead need ``-std=c++2a``.
