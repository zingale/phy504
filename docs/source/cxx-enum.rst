****
enum
****

An `enum <https://en.cppreference.com/w/cpp/language/enum>`_ is a special type that
holds named constants.

They syntax is:

.. code:: c++

   enum color {red, green, blue};

By default, the data types are ``int`` and the first value is ``0``.

You can also create a *scoped enum*, as:

.. code:: c++

   enum class color {red, green, blue};

and then you would access the data as ``color::red``, ...

A common use case is to provide integer names to indices that are physically
meaningful.  For example, imagine that we have a 2D array of data that has
N positions and M quantities at each position:


.. literalinclude:: ../../examples/enum/enum_components.cpp
   :language: c++
   :caption: ``enum_components.cpp``
