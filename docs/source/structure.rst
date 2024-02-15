**************************
Structure of a C++ Program
**************************

.. admonition:: reading

   * `Structure of a program <https://cplusplus.com/doc/tutorial/program_structure/>`_ from cplusplus.com

Let's look at a simple "Hello, World" program:

.. important::

   Every C++ program needs to have a ``main()`` function

.. code:: c++

   #include <iostream>

   // our Hello, World program

   int main()
   {
      std::cout << "Hello World!" << std::endl;
   }

A nice breakdown of a "Hello, World" program is shown here: https://www.cplusplus.com/doc/tutorial/program_structure/ ---let's walk through that.

A few important bits:

* A preprocessor is used to bring additional functionality into our code
  (the ``#include``)

* C++ comments start with ``//``

* Each C++ program needs to have a function called ``main()`` and that function
  is of type ``int``.

* ``{`` and ``}`` are used to denote blocks of code in C++

* The C++ Standard Library provides a lot of useful functions and
  capabilities.  Here we use ``std::cout`` from the standard library
  to output.

* ``<<`` is an operator in C++.  Its meaning can depend on context.
  Here it is used to pass ``"Hello, World!"`` to ``cout``

* ``::`` is the scope operator.  This tells us that ``cout`` is part of a *namespace*
  called ``std``, and the compiler should look there for its implementation.

* Statements end with ``;``

.. note::

   C++ files can have a variety of extensions, including: ``.C``,
   ``.cxx``, ``.cc``, and ``.cpp``.

   I'll use ``.cpp`` throughout this course.
