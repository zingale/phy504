*************************
Floating Point Exceptions
*************************

What happens when we do something bad?  Consider this example:

.. literalinclude:: ../../examples/floating_point/undefined.cpp
   :language: c++
   :caption: ``undefined.cpp``

Here, we pass ``-1`` to ``trouble()`` which then takes the square root
of it---this results in a NaN.  But if we run the code, it goes
merrily about its way, using that result in the later computations.

Unix uses `signals <https://en.wikipedia.org/wiki/Signal_(IPC)>`_ to
indicate that a problem has happened during the code execution.  If a
program created a *signal handler* then that signal can be trapped and
any desired action can be taken.

.. note::

   This example was only tested on a Linux machine with GCC.  Other OSes
   or compilers might have slightly different headers or functionality.

There are a few parts to trapping a floating point exception (FPE).  First we need
to enable exception trapping via:

.. code:: c++

   feenableexcept(FE_INVALID|FE_DIVBYZERO|FE_OVERFLOW);

That catches 3 different types of floating point exceptions---invalid,
divide-by-zero, and overflows.

.. note::

   See `cppreference floating point environment <https://en.cppreference.com/w/cpp/numeric/fenv>`_
   for a full list of the macros of exceptions that can be trapped.

Next we need to add a handler to deal with the exception:

.. code:: c++

   signal(SIGFPE, fpe_handler);

Here, ``SIGFPE`` is the standard name for a floating point exception,
and ``fpe_handler`` is the name of a function that will be called when
we detect a ``SIGFPE``.

Finally, we need to write the handler, and we'd like to get a backtrace.
There are two ways that we can approach this, which we see next.

Linux backtrace method
======================

We can use the Linux ``backtrace()`` function to access the stack of
our program execution.  This is really a C-function, so we need to use
C-style arrays here.

Here's the new version of our code:

.. literalinclude:: ../../examples/floating_point/undefined_trap.cpp
   :language: c++
   :caption: ``undefined_trap.cpp``

When we compile the code, we want to add the ``-g`` option to store the
symbols in the code---this allows us to understand where problems arise:

.. prompt:: bash

   g++ -g -o undefined_trap undefined_trap.cpp

Now when we run this, the program aborts and we see:

::

    floating point exception, signal 8
    0: ./undefined_trap() [0x401261]
    1: /lib64/libc.so.6(+0x42750) [0x7f3dc35dc750]
    2: /lib64/libm.so.6(+0x1435c) [0x7f3dc37d335c]
    3: ./undefined_trap() [0x4012ff]
    4: ./undefined_trap() [0x401347]
    5: /lib64/libc.so.6(+0x2d560) [0x7f3dc35c7560]
    6: /lib64/libc.so.6(__libc_start_main+0x7c) [0x7f3dc35c760c]
    7: ./undefined_trap() [0x401145]
    Aborted (core dumped)

This is the call stack for our program.  In the brackets are the address in
the program where the execution was when the FPE occurred.

.. note::

   The addresses you see might be different, and they will depend on the compiler
   and OS.

These lines are ordered such that the calling function is below the function
where the execution is.  So it usually is best to look at the
addresses near the top.

We can turn those into line numbers using ``addr2line``:

.. prompt:: bash

  addr2line  -e undefined_trap 0x4012ff

gives:

::

   /home/zingale/classes/phy504/examples/floating_point/undefined_trap.cpp:23

and that line is precisely where the ``sqrt()`` is!

We can get slightly nicer output (including the function name) by doing:

.. prompt:: bash

   addr2line  -C -f -p -e undefined_trap 0x4012ff

which gives:

::

    trouble(double) at /home/zingale/classes/phy504/examples/floating_point/undefined_trap.cpp:23


.. note::

   On the MathLab machines, the stack trace seems to include an offset, like:

   ::

      floating point exception, signal 8
      0: ./undefined_trap(+0xc03) [0x561d8799dc03]
      1: /lib/x86_64-linux-gnu/libc.so.6(+0x3ef10) [0x7f5461e3df10]
      2: /lib/x86_64-linux-gnu/libm.so.6(+0x11397) [0x7f5462201397]
      3: ./undefined_trap(+0xccf) [0x561d8799dccf]
      4: ./undefined_trap(+0xd21) [0x561d8799dd21]
      5: /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xe7) [0x7f5461e20c87]
      6: ./undefined_trap(+0xaaa) [0x561d8799daaa]
      Aborted (core dumped)

   and we need to use that offset instead with ``addr2line``, like:

   .. prompt:: bash

      addr2line -a -f -e ./undefined_trap +0xcd5


C++23 stacktrace library
========================

A more modern (and simpler) way to get the stacktrace is available in C++23
via the `stacktrace library <https://en.cppreference.com/w/cpp/utility/basic_stacktrace>`_.

.. literalinclude:: ../../examples/floating_point/undefined_stacktrace.cpp
   :language: c++
   :caption: ``undefined_stacktrace.cpp``

To build this, we need to load an extra library.  For GCC 12 or 13, we can do:

.. prompt:: bash

   g++ -g -std=c++23 -o undefined_stacktrace undefined_stacktrace.cpp -lstdc++_libbacktrace

For GCC 14, we would do:

.. prompt:: bash

   g++ -g -std=c++23 -o undefined_stacktrace undefined_stacktrace.cpp -lstdc++exp
