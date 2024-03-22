********
Valgrind
********

`Valgrind <https://valgrind.org/>`_ is a tool that can detect memory
leaks, using uninitialized variables, In essence, valgrind translates
the executable to an intermediate, architecture-independent form, and
the tools in valgrind interpret this code.  As a result, it can
instrument the code with a lot of different checks, but this comes at
a performance cost.

Usually you will run your code through valgrind even if there are no
apparently bugs, just to ensure that you didn't miss anything.  If you
know you have bugs, valgrind can help you find them.

We have not (yet) been doing manually memory management (because
modern C++ really makes it rare that we need to), so this greatly
reduces our chance of memory leaks.  But if we did, valgrind would be
able to tell us if we didn't free up any memory.


Uninitialized variables
=======================

Consider the following example:

.. literalinclude:: ../../examples/valgrind/uninitialized.cpp
   :language: c++
   :caption: ``uninitialized.cpp``


here we are using the object ``b`` without initializing it.  If we run this directly,
the code seems to work.  Now if we instead run it via valgrind:

.. prompt::

   g++ -g -o uninitialized uninitialized.cpp
   valgrind ./uninitialized

we see that there are errors.  Here's the first:

::

    ==1457506== Conditional jump or move depends on uninitialised value(s)
    ==1457506==    at 0x4BDC2C8: __printf_fp_l (printf_fp.c:397)
    ==1457506==    by 0x4BF5FF7: __vfprintf_internal (vfprintf-internal.c:1646)
    ==1457506==    by 0x4C06CD9: __vsnprintf_internal (vsnprintf.c:114)
    ==1457506==    by 0x49664F2: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h:92)
    ==1457506==    by 0x4996400: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
    ==1457506==    by 0x49A4B4F: put (locale_facets.h:2458)
    ==1457506==    by 0x49A4B4F: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:73)
    ==1457506==    by 0x401313: main (uninitialized.cpp:16)
    ==1457506==

That's where we use the resulting vector, but the tool also tells us to turn on ``--track-origins=yes`` to see
where the problem first arises:

.. prompt:: bash

   valgrind --track-origins=yes ./uninitialized

::

    ==1457650== Conditional jump or move depends on uninitialised value(s)
    ==1457650==    at 0x4BDC2C8: __printf_fp_l (printf_fp.c:397)
    ==1457650==    by 0x4BF5FF7: __vfprintf_internal (vfprintf-internal.c:1646)
    ==1457650==    by 0x4C06CD9: __vsnprintf_internal (vsnprintf.c:114)
    ==1457650==    by 0x49664F2: std::__convert_from_v(__locale_struct* const&, char*, int, char const*, ...) (c++locale.h:92)
    ==1457650==    by 0x4996400: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, char, double) const (locale_facets.tcc:1023)
    ==1457650==    by 0x49A4B4F: put (locale_facets.h:2458)
    ==1457650==    by 0x49A4B4F: std::ostream& std::ostream::_M_insert<double>(double) (ostream.tcc:73)
    ==1457650==    by 0x401313: main (uninitialized.cpp:16)
    ==1457650==  Uninitialised value was created by a stack allocation
    ==1457650==    at 0x401226: main (uninitialized.cpp:4)

Now it is telling us that the uninitialized variable is on the stack.  In our code, ``b`` is the only stack
variable.



Bounds checking
===============

Consider the following code:

.. literalinclude:: ../../examples/valgrind/bounds.cpp
   :language: c++
   :caption: ``bounds.cpp``

Here, we are accessing the ``vector a`` out of bounds.  When we just run it on the command line, it works fine.

When we run it through valgrind, we see:

.. prompt:: bash

   g++ -g -o bounds bounds.cpp
   valgrind ./bounds

we see:

::

    ==1458835== Invalid read of size 4
    ==1458835==    at 0x401281: main (bounds.cpp:8)
    ==1458835==  Address 0x4da4c94 is 0 bytes after a block of size 20 alloc'd
    ==1458835==    at 0x4844FF5: operator new(unsigned long) (vg_replace_malloc.c:422)
    ==1458835==    by 0x401A17: __gnu_cxx::new_allocator<int>::allocate(unsigned long, void const*) (new_allocator.h:127)
    ==1458835==    by 0x4018DD: std::allocator_traits<std::allocator<int> >::allocate(std::allocator<int>&, unsigned long) (alloc_traits.h:464)
    ==1458835==    by 0x401791: std::_Vector_base<int, std::allocator<int> >::_M_allocate(unsigned long) (stl_vector.h:346)
    ==1458835==    by 0x4015DE: void std::vector<int, std::allocator<int> >::_M_range_initialize<int const*>(int const*, int const*, std::forward_iterator_tag) (stl_vector.h:1582)
    ==1458835==    by 0x4013DE: std::vector<int, std::allocator<int> >::vector(std::initializer_list<int>, std::allocator<int> const&) (stl_vector.h:629)
    ==1458835==    by 0x401263: main (bounds.cpp:6)

This shows us that on line 8, we did an invalid read of size 4 (bytes).

