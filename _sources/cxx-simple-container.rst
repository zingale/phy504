***************************
Example: A Simple Container
***************************

We want to combine what we learned about allocating memory and move semantics
into a class that exercises both.

.. note::

   We could rewrite our ``Array`` class to manage its own memory via a ``unique_ptr``,
   but here we do something simpler.


A simple container: attempt I
=============================

Here's a simple container that manages its own memory (dynamic allocation on the heap),
via a ``unique_ptr``---this is a pointer that the compiler will automatically clean up
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

Here we are using member list initialization to set ``_data`` to be the
same pointer as ``c._data``---the ``.get()`` function on a
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

We want the copy constructor to do a *deep copy*---it should create
its own memory space and copy the data, element-by-element from the
input ``Container`` to the new one.

C++ provides a `memcpy function
<https://www.cplusplus.com/reference/cstring/memcpy/>`_ to
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

.. note::

   In case 4,

   .. code:: c++

      auto c2 = fill_new();

   we might expect that the compiler would do a move constructor here, but instead it
   does `return value optimization <https://en.wikipedia.org/wiki/Copy_elision>`_.  We can disable this with LLVM as:

   .. prompt:: bash

      clang++ -fno-elide-constructors -o test_container test_container.cpp

   to see that it will do a move constructor when it is not allowed to do RVO.

