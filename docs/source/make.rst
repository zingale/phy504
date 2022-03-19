*********
Makefiles
*********

We'll look at `GNU Make <https://www.gnu.org/software/make/>`_ to
manage building projects that are split across multiple files.  Make
allows us to specify rules for how to compile and link the code.

.. note::

   A popular alternative to GNU Make is `CMake <https://cmake.org/>`_.

We'll use this to manage our :ref:`planets + multiple files <sec:multiplefiles>`
example.

A first ``GNUmakefile``
=======================

Here's a basic makefile, which we'll name ``GNUmakefile``:

.. literalinclude:: ../../examples/multiple_files/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

There are a few different types of lines, but the most important are
the rules that are of the form::

    target:   dependencies ...
              commands
              ...

.. note::

   make uses a tab character to indent the commands, not spaces.

For example, the rule:

.. code:: make

   planet_sort_split.o: planet_sort_split.cpp planet.H
           g++ -c planet_sort_split.cpp

says that ``planet_sort_split.o`` depends on the files
``planet_sort_split.cpp`` and ``planet.H``.  And the rule to make it
is ``g++ -c planet_sort_split.cpp``.  By specifying the dependencies,
``make`` knows whether it needs to recompile a file by looking at
whether its dependencies changed.

It is common to put a target called ``ALL`` at the top, since by
default ``make`` will try to build the first target it encounters.


We build the project by doing:

.. prompt:: bash

   make


.. admonition:: try it...

   If you type ``make`` again, it doesn't do anything, since none of the source
   files changed, so it does not need to update the build.

   If you modify one file, e.g.,

   .. prompt:: bash

      touch planet.cpp

   and then do make again:

   .. prompt:: bash

      make

   Then it will only execute the rules that depend on the file that
   changed.


Generalizing our ``GNUmakefile``
================================

