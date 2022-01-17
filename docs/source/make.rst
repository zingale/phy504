*********
Makefiles
*********

We'll look at `GNU Make <https://www.gnu.org/software/make/>`_ to manage building projects that are split across multiple files.
Make allows us to specify rules for how to compile and link the code.  

Note: A popular alternative to GNU Make is `CMake <https://cmake.org/>`_.


First example
=============

Take a look at the project in https://github.com/zingale/phy504/tree/main/examples/make/1

There are 3 C++ files and one header that need to be built and then linked together, with the
main driver in ``main.cpp``.

Here's a basic makefile that controls the building:

.. literalinclude:: examples/make/1/GNUmakefile
   :language: make
   :linenos:

There are a few different types of lines, but the most important are the rules that are of the form::

    target:   dependencies ...
              commands
              ...

.. note::

   make uses a tab character to indent the commands, not spaces.


We build the project by doing::

   make

