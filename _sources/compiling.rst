*********
Compiling
*********

When we write C++ code, there are a few concepts we need to understand:

* *source code* : this is the C++ instructions we directly write.  We
  will use our text editor and create a file with the extension
  ``.cpp``, like ``hello.cpp``.

  This is readable to us, but it does not contain the instructions
  that the processor can interpret directly.

* *compiler* : a compiler is a program that takes the source code file
  (e.g. ``hello.cpp``) and translates it into machine code
  instructions specific to the processor in our computer.  We will use
  the compiler ``g++``.

* *executable* : this is the name of the program output by the
  compiler that is able to be run by the operating system.

  Traditionally it will not have an extension on Unix (so
  ``hello.cpp`` will produce an executable named ``hello``), while on
  Windows, you will often see the extension ``.exe``.


Online Compilers
================

We can compile this using an online compiler.  Let's try https://godbolt.org/

This will show us the assembly instructions it generated for our code
and by checking "Execute the code" in the "Output" dropdown, it will
run the code for us.


Compiling on the Command Line
=============================

Now let's see how to invoke ``g++`` on the command line.

With your editor, create a file ``hello.cpp`` with the above source code in it.

Then we build our executable (compiling and linking all in a single command) via:

.. prompt:: bash

   g++ -o hello hello.cpp

This turns our source code, ``hello.cpp`` into the executable ``hello``.

The option ``-o`` is used to name the executable.  If we do not
provide a name, then the name ``a.out`` will be used.

We can then run our program as:

.. prompt:: bash

   ./hello

.. tip::

   If you are using your own computer, then you will need to ensure that the compiler is
   using a recent C++ standard to build the code we will discuss in this class.

   You can add the option ``-std=c++17`` to the compilation line to ensure it uses C++ 17.


