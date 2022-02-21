************
More Vectors
************

Let's look at some more ways we can work with vectors.

Initializing
============

We can initialize a vector when we declare it.  The following creates a vector with 5 elements, all initialized to 0:

.. code:: c++

   vector<double> container(5, 0.0);

Notice that we are using ``()`` here instead of ``{}``.  As we'll see
later, this means that we are calling a function here to do the
initialization (the constructor).

Here we instead initialize a vector by telling it the values of each of the elements:

.. code:: c++

   vector<double> container2{10.0, 20.0, 30.0};

Size
====

We can always get the number of elements in a vector via the ``size()`` function:

.. code:: c++

   vector<int> int_vec{1, 2, 3, 4, 5};

   int nlen = int_vec.size();


.. admonition:: try it...

   We saw that we access an element via ``[]``.  What happens if we
   access the vector out of bounds?

Bounds, iterators, and pointers
===============================

There are 2 ways to access the beginning and end of a ``vector``:

* ``.cbegin()``, ``.begin()`` : these will give you an interator that
  points to the first element.  The difference is that accessing with
  ``.cbegin()`` will not allow you to modify the vector (the ``c`` is
  for ``const``).  You can increment an *iterator* loop over the
  contents of the vector.

* ``.cend()``, ``.end()`` : these will return an iterator that points
  *to one past the last element*.

An iterator can be thought of as a special type of *pointer* -- a
topic that we will discuss much more later.  Iterators have
restrictions on their use, depending on the container -- this makes
them more safe to use.

If we think about an iterator like:

.. code:: c++

   auto it = container.cbegin();

Then we can access the next element in ``container`` by incrementing the iterator, ``it++``.

If we want to see the value in ``container`` that the iterator is
pointing to, then we need to *dereference* it -- this is done with the
``*`` operator:

.. code:: c++

   std::cout << "cbegin is " << *it << std::endl;


These can also be used in some powerful algorithms provided by the
``algorithms`` header.  Here's an example of using ``find`` on a vector:

.. literalinclude:: ../../examples/vectors/find_example.cpp
   :language: c++

We'll see more algorithms provided by the STL later.


Inserting
=========

We saw that ``.push_back()`` is used to add an element to the end of a
vector.  To insert in the middle of the vector, we use
``.insert(it_pos)``, where ``it_pos`` is an iterator pointing to the
element in the vector we want to insert *in front of*.  (Note:
``insert()`` can actually allow you to insert multiple elements by
specifying an additional argument.)

.. admonition:: try it...

   Create a vector that initially has the elements ``100``, ``200``,
   ``300`` and then use ``insert()`` to put ``150`` in between ``100``
   and ``200``.

   Finally loop over and print out all the elements of the vector.


Resize and clear
================

If we have an existing vector we can resize it with ``.resize(num,
init)`` where ``num`` is the number of new elements and (optionally) ``init`` is
their initial value.

We can remove everything from the vector using ``.clear()``.  Here's an example:

.. literalinclude:: ../../examples/vectors/resize_example.cpp
   :language: c++



