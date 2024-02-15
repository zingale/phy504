**************************
Aside: Sequence Containers
**************************

``std::vector`` is one example of a `sequence container
<https://en.wikipedia.org/wiki/Sequence_container_(C%2B%2B)#Vector>`_
in C++.  There are 5 such containers that each offer different
performance attributes:

* `std::array <https://en.cppreference.com/w/cpp/container/array>`_ : fixed size contiguous storage.

  Complexity:

  * random access: $\mathcal{O}(1)$
  * insertion: not supported

* `std::vector <https://en.cppreference.com/w/cpp/container/vector>`_ : automatically resizing array (as needed).

  Complexity:

  * random access: $\mathcal{O}(1)$
  * insertion at end: amortized constant $\mathcal{O}(1)$
  * insertion / removal elsewhere: $\mathcal{O}(N)$ (actually depends on distance to the end)

* `std::deque <https://en.cppreference.com/w/cpp/container/deque>`_ :
  a double-ended queue---this means that it is easy to add elements to
  either end.  Data is not stored contiguously in memory.

  Complexity:

  * random access: $\mathcal{O}(1)$
  * insertion / removal at beginning or end: $\mathcal{O}(1)$
  * insertion / removal elsewhere: $\mathcal{O}(N)$

* `std::list <https://en.cppreference.com/w/cpp/container/list>`_ : this is a doubly-linked list.  It is an easy
  operation to insert an element, but there is not random access to a
  particular element, instead you must walk through the list.

  Complexity:

  * random access: not supported
  * insertion / removal anywhere: $\mathcal{O}(1)$

* ``std::forward_list`` : this is a singly-linked list.  You can only walk through in one direction.

  Complexity:

  * random access: not supported
  * insertion / removal anywhere: $\mathcal{O}(1)$
