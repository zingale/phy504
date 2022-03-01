**********
References
**********

.. admonition:: reading

   Cyganek section 3.11


*References* in C++ provide access to an object indirectly.  It
essentially becomes another name for the object and allows you to
read and write to its memory directly.

We use the ``&`` operator to create a reference.

Here's a simple example:

.. code:: c++

   int x{10};
   int &x_ref = x;

   x_ref++;

Since ``x_ref`` is a reference for ``x``, modifying its value directly
modifies ``x`` 's value as well.

.. note::

   You can define the reference as:

   .. code:: c++

      int& x;

   or

   .. code:: c++

      int &x;

.. important::

   A reference must be initialized when it is created.  You cannot do:

   .. code:: c++

      double x{3.14};
      double &x_ref;

      x_ref = x;


Here's an example showing different ways of accessing elements of a
vector and whether we can modify them:

.. literalinclude:: ../../examples/references/vector_modify.cpp
   :language: c++

