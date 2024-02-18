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

In C++20, the ``contains()`` member function was added to maps:

.. literalinclude:: ../../examples/map/map_contains.cpp
   :language: c++
   :caption: ``map_contains.cpp``

.. tip::

   To compile this, you likely need to add ``-std=c++20`` to the compilation
   line.
