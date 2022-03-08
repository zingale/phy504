*********
Functions
*********

As we write increasingly complex code, it becomes helpful to split it apart into functions.  This has
several advantages:

* We can reuse the functionality provided by a function easily

* It becomes easier to test the code -- we can test each function
  separately (unit tests)

* We can use the functions in other codes

* The design process becomes easier if we think of our code in terms
  of what functions are needed.  Then once we layout the flow of the
  code in terms of the major functions, we can implement them
  one-by-one.

Quite often in C++ we will split our code into multiple files, but for
now we'll work all within a single file.

Let's start with a simple example, and then we'll talk about the structure:

.. literalinclude:: ../../examples/simple_function.cpp
   :language: c++

