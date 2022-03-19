*******
Vectors
*******

C++ has the *standard template library* or STL which adds an immense
amount of functionality to the language.  Let's look at
``std::vector``.  A ``vector`` is a container that can hold data of
the same type (e.g., ``double``).  It differs from an array that you
might have used in other languages in that it is not a fixed size --
it can grow as needed to hold more data.

Vectors are very useful to store data and loop over it, etc.

Information on the properties of C++ vectors can be found at the
`CPlusPlus vector page
<https://www.cplusplus.com/reference/vector/vector/>`_.

From that description, we see that vectors:

* store the data contiguously in memory

* can grow as needed (but occasionally, this means creating a new
  vector of larger size and copying data into it -- a slow operation)

* have a lot of functions that can work on them

* can access any location directly

* are very efficient at adding data to the end, but not efficient for
  inserting data in the middle

Your text has an example of creating a vector to store student grades
and then computing an average.  We'll write our own version.

First lets see how to create a vector and add some data to it.

Here's a simple example:

.. literalinclude:: ../../examples/vectors/simple_vector.cpp
   :language: c++
   :caption: ``simple_vector.cpp``

Notice the following:

* We specify the data type when creating a vector

* We use ``push_back`` to add data to the end of a vector.  Here we
  are using the ``.`` operator to indicate that we are performing the
  ``push_back`` on the vector ``container`` that we created.

* We access elements of a vector using ``[]`` with an index, and that
  indices start at 0.

Looping
=======

Often we will want to loop over the elements contained in a vector,
and C++ provides a `range-based loop
<https://en.cppreference.com/w/cpp/language/range-for>`_ for this
purpose.  For example to loop over all elements and output them to the
terminal, we could do:

.. code:: c++

   for (auto e : container) {
       std::cout << e << std::endl;
   }

Here we see a new keyword, ``auto``.  Each pass through this loop,
``e`` will take on the next value in our ``vector`` called
``container``.  The body of the loop is contained in the ``{...}``.

C++ requires that we declare the data type of
``e``.  In this case, the compiler knows that it will have to be a
``double``, since the ``vector`` is a vector of ``double`` s, so we can
use the ``auto`` keyword to have the compiler automatically deduce the
data type.

Let's try this in our code.

There is another more classic type of loop in C++ that takes the form:

.. code:: c++

   for (start; end; incremement) {
       // do stuff
   }

For example, to loop from 0 to 9, we could do:

.. code:: c++

   for (int i = 0; i < 10; ++i) {
      // do stuff depending on i
   }

.. admonition:: try it...

   Try out the loop above, printing out the value of ``i`` each iteration.


Example: averaging grades
=========================

You text has an example of reading and averaging student grades.  It
uses a few more bits of C++ syntax (like conditional statements) that
we'll see in detail shortly.  Let's look over that code:

https://github.com/BogCyg/BookCpp/blob/master/Grades/src/main.cpp

