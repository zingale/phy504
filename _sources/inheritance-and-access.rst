**********************
Inheritance and Access
**********************

.. admonition:: reading

   * Cyganek section 4.3
   * `Inheritance (Wikipedia) <https://en.wikipedia.org/wiki/Inheritance_(object-oriented_programming)>`_

With inheritance, we create a *base class* that has member functions that
should be generally applicable to any class that we build off of the
base.  We then create a *sub class* that inherits the functionality of
the base class and can extend it.

.. tip::

   Sometimes inheritance is described as being applicable when there is an *is-a relationship*.

   E.g.:

   * A dog is an animal

   * A square is a shape

Access
======

There are different modes of access that come into play.  First within the base
class, we expand *private* and *public* to include *protected*:

* private : member data and functions is only available to the base class.

* protected : member data and functions is available to the base class
  as well as any class that inherits from it.

* public: anyone can access the member data and functions.

If we expect to derive from our class and still want to practice encapsulation, then
we would generally make the member data *protected*.

The second way access comes into play is when we define the class that inherits from
the base.  Shortly we'll look at an example that defines a base class called ``Quadrilateral``
and then a class ``Rectangle`` that inherits from it.  We will define the class as:

.. code:: c++

   class Rectangle : public Quadrilateral

The ``:`` says that ``Rectangle`` inherits from ``Quadrilateral`` and
the ``public`` keyword here means that the member data and functions
are inherited with the same access restrictions as in the base class.
We could alternately use ``protected`` or ``private`` here to change
the access to the inherited data.


Constructor
===========

How do we write the constructor of the sub class?

For our ``Rectangle`` example, we might think that we could
just use a member initialization list to initialize the data,
but this does not work.

.. note::

   C++ prevents us from initializing *inherited* member variables in the
   member initialization list of the sub-class constructor.

   Instead we can explicitly call the constructor of the base class to
   initialize any data in the base class and then use a member
   initialization list to initialize anything specific to the sub class.

Now, when we create a ``Rectangle``, the constructor of the base class
is first executed and then the remainder of the sub class constructor
is executed.

.. tip::

   A nice description of how the constructor of the sub class works is
   given in the `Learn C++ tutorials
   <https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/>`_.

Example
=======

Here's an example of the base ``Quadrilateral`` class and the
``Rectangle`` class that inherits from it.

.. literalinclude:: ../../examples/inheritance/shapes.H
   :language: c++
   :caption: ``shapes.H``

A few notes:

* The ``Rectangle`` constructor takes only 2 arguments, since opposite
  sides of a rectangle are the same length.  We then call the base
  class constructor to store these in the ``vector sides``,
  duplicating the information as needed to initialize all 4 sides.

* There is no additional member data in ``Rectangle``, so no further
  initialization is needed.

* The ``perimeter`` function is general to any quadrilateral, so
  ``Rectangle`` does not need to define it.

Here's a test driver:

.. literalinclude:: ../../examples/inheritance/test_shapes.cpp
   :language: c++
   :caption: ``test_shapes.cpp``

