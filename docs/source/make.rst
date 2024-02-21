.. _sec:makefiles:

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

Our first makefile required us to write a rule for every ``.cpp`` file
explicitly.  Instead, we can use `pattern rules
<https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html>`_
and `wildcards
<https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html>`_
to automate a lot of the logic.

Here's the improved ``GNUmakefile``:

.. literalinclude:: ../../examples/multiple_files/GNUmakefile.new
   :language: make
   :caption: new ``GNUmakefile``

The first thing we do is find all of the sources and headers:

.. code:: make

   SOURCES := $(wildcard *.cpp)
   HEADERS := $(wildcard *.H)

The ``:=`` operator evaluates these expressions immediately when
``make`` encounters them and stores the results in the variables
``SOURCES`` and ``HEADERS``.  To reference the list of files in
these variables, we use ``${}``, e.g., ``${SOURCES}``.

The next trick is that we create a list of object files by automatically
replacing the ``.cpp`` extension with a ``.o`` extension via the ``make``
expression:

.. code:: make

   OBJECTS := $(SOURCES:.cpp=.o)

Finally, we have a generic rule to compile a C++ file:

.. code:: make

   %.o : %.cpp ${HEADERS}
   	g++ -c $<

Note that we make every header file a dependency for every object
file, whether or not it is included in the source file.  This is not
necessary, but simplifies how we specify the dependencies.

We use a make `automatic variable
<https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html>`_,
``$<`` to indicate the first name in the dependencies.

We use another automatic variable in the final rule, ``$@`` to indicate
the name of the target, to be used as the executable name:

.. code:: make

   planet_sort_split: ${OBJECTS}
   	g++ -o $@ ${OBJECTS}


Going further
=============

There are more things we can do to generalize our makefile.

* We can use `g++ to automatically determine dependencies <https://stackoverflow.com/questions/11855386/using-g-with-mmd-in-makefile-to-automatically-generate-dependencies>`_.  Also see the `GNU make automatic prerequisites <https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html>`_.

* We can have the makefile create code at build time, for instance, writing
  a function that contains the current git hash of the code

* We can different levels of build: optimized and debug

.. https://slashvar.github.io/2017/02/13/using-gnu-make.html

.. http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/

.. https://stackoverflow.com/questions/66118766/what-is-include-in-gnu-make-and-how-it-works

.. admonition:: try it...

   Modify the ``GNUmakefile`` to add the warning flags we discussed earlier to
   the compilation of each source.

.. tip::

   A common target in makefiles is ``clean``, which will delete the intermediate
   ``*.o`` files and the executable.

.. tip::

   Here's a `Makefile <https://github.com/zingale/phy504/blob/main/examples/vectors/Makefile>`_
   I use with some of the in-class examples to build several executables in the same directory.
