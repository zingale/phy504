**************************
Software Development Tools
**************************

.. admonition:: reading

   Cyganek section 2.2


There are a number of tools / concepts that we will use in the software development process:

* Editors / integrated development environments

  Beyond just letting us type in text, these can check syntax,
  highlight code, autocomplete function / variable names, etc. making
  it easier to write our code.

* Version control

  We already had an introduction to git.  Good version control is a
  critical part of the software development process.  We will put all of
  our projects under git control.

* Compiler

  The job of the compiler is to turn the source code in a file into
  machine instructions for the computer we are using.

  We will use the `GNU Compiler Collection <https://gcc.gnu.org/>`_
  for most of this class.  The name of the C++ compiler in GCC is ``g++``.

  ``g++`` supports different language standards depending on what
  version of the compiler we use.  Here is a list of `C++ standard
  support in GCC <https://gcc.gnu.org/projects/cxx-status.html>`_

* Linker

  When working with multiple source files or calling function in libraries
  we need to link all of the compiled code together.  ``g++`` will act as the
  frontend to the linker.

  Sometimes we will be able to compile and link with one command, but
  these are distinct steps in the process of building a program.

* Testing

  To ensure that our code gets the correct answer, there are a number
  of different testing methods we can employ.  A simple type of
  testing is called *unit testing*, where we write tests for each
  function (or program unit) to separately test that they work as
  intended.  We'll look at unit testing toward the end of the
  semester.

  Once we have some tests, we'd ideally like to automate them.  Github
  allows us to do this via *continuous integration*, where the tests
  are run before each change is merged into the ``main`` branch of our
  code repo.

* Debuggers

  When our code is not giving us the expected result, a `debugger
  <https://en.wikipedia.org/wiki/Debugger>`_ (like ``gdb``) allows us
  to step through the execution of the code bit-by-bit and inspect the
  variables to understand where it is going wrong.

* Profiler

  One our code is working, we can think about performance.  A
  `profiler
  <https://en.wikipedia.org/wiki/Profiling_(computer_programming)>`_
  (like ``gprof``) will give use a report of which functions or even
  lines in our code are taking the most time.  This helps us identify
  where to spend our time optimizing the code to perform better.

* Static analysis tools

  A static analysis tool looks through your code and identifies
  problematic expressions (things like buffer overflows, using memory
  that has been freed, ...).  They can also sometimes tell you how to
  write code more efficiently, to use modern C++ constructs, etc.

  There are a `large number of static code analysis tools <https://en.wikipedia.org/wiki/List_of_tools_for_static_code_analysis>`_.
  We'll mostly look at `clang-tidy <https://clang.llvm.org/extra/clang-tidy/>`_.

* Documentation

  Ultimately, when we make our code available, we would like to have
  documentation explaining how to use our code *and* how to contribute
  to its development.  We'll look at some standard documentation tools
  and how to host a website.

