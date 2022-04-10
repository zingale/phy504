********
``this``
********

All C++ classes have a pointer called ``this`` that refers to the
current object.  This is useful, since some functions, as we will see,
need to return a reference to the object we are working on.

Here's a very simple example that creates a class that only holds a
string and then defines a member function, ``get_ref()``, that returns
a reference to itself (by returning ``*this`` as a reference).

.. literalinclude:: ../../examples/this/this_example.cpp
   :language: c++
   :caption: ``this_example.cpp``

Another way we could use ``this`` is to access the member data inside of
the class.  Since ``this`` is a pointer, we will use the member selection
operator for pointers, e.g., ``this->data``.
