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

In C++ we can allocate memory using ``new`` and then explicitly free it up with ``delete``.
But this can be dangerous -- a very frequent bug is forgetting to free up memory that you
manually allocated.

Instead, we'd like to be able to have the memory freed automatically for us
when the object managing it goes out of scope.  This is where a unique pointer
comes into play.

``std::unique_ptr`` is a *smart pointer* that manages another object and cleans up
after it when the ``unique_ptr`` goes out of scope.

In particular, `make_unique <https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique>`_
is used to create an object and wrap it in ``std::unique_ptr``.

Here's how we can allocate memory for an array of doubles and wrap it in a ``unique_ptr``
(we also compare to the old C++ way here):

.. literalinclude:: ../../examples/unique_ptr/unique_pointer.cpp
   :language: c++
   :caption: ``unique_pointer.cpp``


Why would we want to do this?
Compared to ``std::array``, this allows us to specify the size at
runtime, instead of compile time.  Compared to ``std::vector``, there
is no additional overhead to allow the array to grow, since its size
is fixed once it is created.

.. admonition:: try it...

   Test this example with valgrind to see if any memory is not freed.
   Remove the ``delete`` and try again.  Notice that the
   ``unique_ptr`` version was freed when it went out of scope.


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

Also take a look at the assignment operator.  We need to be careful
that we don't try to do a copy when if we try something like:

.. code:: c++

   Container a(10);

   a = a;

Moving
======

The latest iteration of the class also implements the move constructor:

.. code:: c++

   Container(Container&& c) noexcept
       : _size(0), _data(nullptr)
   {
       std::cout << "in move constructor" << std::endl;

       std::swap(_size, c._size);

       // swap the data pointers

       _data.swap(c._data);
   }

This first invalidates the pointer of the data region and then it uses
``std::swap()`` to swap the size from the incoming ``Container`` to
ours and also does a swap on the pointers.

At the end of this operation, the incoming ``Container c`` will be invalid.

The move assignment works in a similar fashion.

Here's a driver that exercises all of these functions:

.. literalinclude:: ../../examples/move/test_container.cpp
   :language: c++
   :caption: ``test_container.cpp``

There are prints in each of the functions so we can see where each comes into play.
