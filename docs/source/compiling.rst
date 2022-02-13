*********
Compiling
*********


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

The option ``-o`` is used to name the executable.  If we do not
provide a name, then the name ``a.out`` will be used.

We can then run our program as:

.. prompt:: bash

   ./hello


