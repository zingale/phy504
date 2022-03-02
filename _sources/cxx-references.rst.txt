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

We can create a ``const`` reference that provides only read access to
an object:

.. code:: c++

   int a = 1.0
   const int& a_ref = a;

Now if we try to update ``a`` through ``a_ref``, we'll get an error.

``const`` references will be very useful when we start writing
functions and wish to pass objects in a *read-only*.

.. note::

   You cannot make a reference to a reference.

A great use of references is to access and modify data in containers
(like strings, vectors, and arrays) via a ranged-for loop.

.. note::

   Recall in our ``array`` examples, we used references to loop over
   rows and columns and set the elements.  :ref:`Let's look at that again.<sec:multidimensionalarrays>`

Here's an example showing different ways of accessing elements of a
vector and whether we can modify them:

.. literalinclude:: ../../examples/references/vector_modify.cpp
   :language: c++


.. admonition:: try it...

   Let's modify :ref:`our example from last class <sec:structplanet>` with the ``Planet`` type
   to add the period as a member and fill the period automatically via
   Kepler's law in a loop.

.. admonition:: try it...

   What do you think happens with this code?

   .. code:: c++

      int a{0}, b{1};
      int& r = a, rr = b;

