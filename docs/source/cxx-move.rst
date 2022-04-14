**************
Move Semantics
**************

.. admonition:: reading

   Cyganek section 4.5

   `Rvalue references and move constructors <https://en.wikipedia.org/wiki/C%2B%2B11#Rvalue_references_and_move_constructors>`_


.. tip::

   We are discussing this for completeness, but move semantics can be complicated.
   I'll show a "simple" example of a class that manages its own memory and implements
   move semantics.


C++11 introduced move semantics, which make it possible for objects to
take the data region from one another, instead of having to copy.  We
first saw this when we did our orbit integrator and returned a
``std::vector`` from our function (see :ref:`sec:more_functions`).


For objects that store large data regions, move is much faster than a
copy.  The C++ compiler will know when it can use a move and
automatically do it for you.

.. note::

   This is where the `Rule of 3
   <https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)>`_
   becomes the *Rule of 5*: now we consider the (1) copy
   constructor, (2) assignment operator, (3) destructor, (4) move
   constructor, (5) move assignment operator.  If we write any one of
   these, we should write all 5.

Right-value references
======================

To allow for move operations, C++11 introduced *right-value
references* or *rvalue references*.  These use ``&&`` and as the name
suggests, they can appear to the right of the assignment operator,
``=``.

.. note::

   ``&&`` here does not mean "reference-to-a-reference", it is just the
   syntax that was chosen for an rvalue reference.

The object that an rvalue reference is a temporary object and it is assumed that
it will never be used again, therefore we are free to steal its data.
This is sometimes called a *destructive read*

We can convert an object into an rvalue reference (indicating that it can be moved) via `std::move <https://en.cppreference.com/w/cpp/utility/move>`_.

Here's an example where we use the *move constructor* of a string to steal the data of the input string:

.. literalinclude:: ../../examples/move/move_example.cpp
   :language: c++
   :caption: ``move_example.cpp``

Allocating memory
=================

A simple container: attempt I
=============================

Here's a simple container that manages its own memory (dynamic allocation on the heap),
via a ``unique_ptr`` -- this is a pointer that the compiler will automatically clean up
after once it goes out of scope.

.. tip::

   We previously used ``std::vector`` for this role, and that remains a good option.
   Here's a discussion on `unique pointers vs arrays <https://stackoverflow.com/questions/16711697/is-there-any-use-for-unique-ptr-with-array>`_.

First the class:

.. literalinclude:: ../../examples/move/container_basic.H
   :language: c++
   :caption: ``container_basic.H``

Now a simple driver that creates a ``Container`` and then creates a new one via copying:

.. literalinclude:: ../../examples/move/test_copy.cpp
   :language: c++
   :caption: ``test_copy.cpp``

When we try to compile this, we get:

::

    test_copy.cpp: In function ‘int main()’:
    test_copy.cpp:15:14: error: use of deleted function ‘Container::Container(const Container&)’
       15 |     auto b = a;
          |              ^
    In file included from test_copy.cpp:3:
    container_basic.H:9:7: note: ‘Container::Container(const Container&)’ is implicitly deleted because the default definition would be ill-formed:
        9 | class Container {
          |       ^~~~~~~~~
    container_basic.H:9:7: error: use of deleted function ‘std::unique_ptr<_Tp [], _Dp>::unique_ptr(const std::unique_ptr<_Tp [], _Dp>&) [with _Tp = double; _Dp = std::default_delete<double []>]’
    In file included from /usr/include/c++/11/memory:76,
                     from container_basic.H:6,
                     from test_copy.cpp:3:
    /usr/include/c++/11/bits/unique_ptr.h:723:7: note: declared here
      723 |       unique_ptr(const unique_ptr&) = delete;
          |       ^~~~~~~~~~

Here the compiler is telling us that for this class, it the default
copy constructor would not be correct, so it doesn't create one.  Therefore we need to explicitly write one.

A simple container: attempt II
==============================

What if we try to implement the copy constructor as:

.. code:: c++

   Container(const Container& c)
       : _size(c._size), _data(c._data.get()) {}

Here we are using member list initialization to set `_data` to be the
same pointer as `c._data` -- the ``.get()`` function on a
``unique_ptr`` returns the underlying pointer to the data.

If we add this, and run with it, we will see:

::

    in parametric constructor
    0 1 2 3 4 5 6 7 8 9 

    0 0 0 0 0 0 0 0 0 0 

    0 0 0 0 0 0 0 0 0 0 

    free(): double free detected in tcache 2
    Aborted (core dumped)

Two things happened here: first we did a *shallow-copy* of the data.
The two objects shared the same underlying data region, so anything we
did to one was reflected in the other.  And second, when the
destructor was called at the very end, it tried to free the data
pointer twice.


A simple container: attempt III
===============================

We want the copy constructor to do a *deep copy* -- it should create
its own memory space and copy the data, element-by-element from the
input ``Container`` to the new one.

C++ provides a `memcpy
<https://www.cplusplus.com/reference/cstring/memcpy/>`_ function to
copy from one buffer to another.  We'll use that.

Here's a final implementation of the class.  This also implements the
move operations, which we'll talk about in a minute.

.. literalinclude:: ../../examples/move/container.H
   :language: c++
   :caption: ``container.H``

If we use this version in ``test_copy.cpp``, then it works as expected.


Moving
======

