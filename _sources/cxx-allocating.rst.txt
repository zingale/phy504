*****************
Allocating Memory
*****************

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

