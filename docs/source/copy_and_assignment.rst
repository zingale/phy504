*********************************
Copy, Assignment, and Destructors
*********************************


.. admonition:: reading

   Cyganek section 4.4

So far, we've been relying on the compiler to provide a default
copy constructor, assignment operator, and destructor.  As long
as our data is simple, we can do this, since the compiler will know
how to work with it.

Here we'll explicitly write this out anyway, just to understand how
they would look.

We'll use the :ref:`sec:vector2d` ``Vector2d`` class as our example here.

The copy constructor is invoked when we do something like:

.. code:: c++

   Vector2d vec(1, 2);

   auto vec2(vec);
   auto vec3 = vec;

In both of these cases, we need to create a separate ``Vector2d`` with
its own memory and copy the data over.  The copy constructor has
the function signature:

.. code:: c++

   Vector2d(const Vector2d& vec)

The assignment operator is invoked when we do something like:

.. code:: c++

   Vector2d vec(1, 2);
   Vector2d vec2;

   vec2 = vec;

The assignment operator has the signature:

.. code:: c++

   Vector2d& operator= (const Vector2d& vec)


.. note::

   The reason that the assignment operator returns a reference is to
   allow us to chain assignment, e.g.:

   .. code:: c++

      v1 = v2 = v3;

Finally, the *destructor* is written as:

   .. code:: c++

      ~Vector2d()

Its job is to clean up any of the memory we allocated.  But for our
``Vector2d`` class, all the data are automatic variables, so they will
be deleted when they go out of scope by the stack.  This is the reason
we really don't need to write a destructor for this class.

.. tip::

   Unless our class is complicated and manages its own memory (e.g.,
   via pointers), we don't need to write these functions.  The
   compiler will automatically generate them for us.

   This is the `Rule of 3
   <https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)>`_
   (or Rule of 5, as we'll see later) that we previously mentioned.

Here's an example of our ``Vector2d`` class that explicitly implements
the copy constructor, assignment operator, and destructor.
Additionally, we add a print to stdout in each of these so we can see
when each of them are called.

.. literalinclude:: ../../examples/more_classes/dtor/vector2d.H
   :language: c++
   :caption: a newer ``vector2d.H``

Here's a driver that exercises them.

.. literalinclude:: ../../examples/more_classes/dtor/more_test_vectors.cpp
   :language: c++
   :caption: ``test_vectors.cpp``

Some notes:

* We see that the destructor is called for each of the ``Vector2d`` 's we created.

