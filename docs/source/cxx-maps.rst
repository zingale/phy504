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
