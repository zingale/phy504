*********
Debugging
*********

    *Every code has at least one bug and one extra line.  Apply recursively.*

A debugger lets you step through your code one line at a time and
examine the state of any objects.  This can help you understand why
the code is not producing the results you expect.

We'll look at two ways to debug.  One on the command line using ``gdb``
and the other in VS Code directly.

Example: integrating a function
===============================

Let's consider writing a program to compute the integral of a function:

.. math::

   I = \int_a^b f(x) dx

In your calculus class, you learned that you can approximate an integral
by dividing it into slabs and then adding up the area of each of those slabs:

.. math::

   I = \int_a^b f(x) dx = \lim_{\Delta x\rightarrow 0} \sum_{i=1}^N f(x_i) \Delta x

where :math:`N` is defined such that :math:`N = (b - a)/\Delta x`.

If we use just a single interval, this looks like:

.. figure:: rectangle_N1.png
   :align: center
   :width: 80%

and the integral would be:

.. math::

   I \approx f(a)(b-a)

We can do slighly better by connecting the two endpoints:

.. figure:: trapezoid_N1.png
   :align: center
   :width: 80%

This looks like a trapezoid, and therefore this is called the *trapezoid rule*
and has the integral:

.. math::

   I \approx \frac{1}{2} (b -a) \left(f(a) + f(b)\right)

To do better, we add intervals, for example, with :math:`N = 6`, we have:

.. figure:: trapezoid_N6.png
   :align: center
   :width: 80%

and the integral approximation is:

.. math::

   I = \frac{1}{2} \Delta x \sum_{i = 1}^N \left (f(x_i) + f(x_{i+1})\right)

This is called the *compound trapezoid rule*

bugs!
=====

Here's a buggy implementation of integrating

.. math::

   I = \int_0^{2\pi} \sin^2(x) dx

We know that the answer is :math:`I = \pi`.

.. literalinclude:: ../../examples/debugger/integrate.cpp
   :language: c++
   :caption: ``integrate.cpp``

There is *more than one bug*.

When we run this with 10 intervals, we get a result of ``0`` -- that's clearly not correct!


We want to learn how to use a debugger to help us locate any issues.

gdb
===

`gdb <https://www.sourceware.org/gdb/documentation/>`_ is the GNU debugger.  This runs on the command line and
let's us:

* set breakpoints in the code where the execution pauses

* step line-by-line through the code, diving into, or skipping over functions

* inspect the value of any objects

Here's a summary of some useful commands:

* ``run`` : run the code

* ``break`` : set a break point (give the line number)

* ``step`` : execute the next instruction

* ``next`` : run the next line of code without diving into functions

* ``list`` : show the code (give a line number to show code in that region)

* ``info breakpoints`` : show the current break points

* ``bt`` : show a backtrace

for most of these commands, we can just use the first letter, like ``b`` instead of ``break``.

First we compile the code with the ``-g`` option:

.. prompt:: bash

   g++ -g -o integrate integrate.cpp

then we run it though ``gdb`` as:

.. prompt:: bash

   gdb ./integrate

Let's set a breakpoint at line ``21`` -- that's the start of the ``for`` loop in the ``integrate()`` function.
And then let's run the code up to then:

.. prompt::
   :prompts: (gdb)

   b 21
   run

we can see where we are using ``l`` and print out a variable with ``p``, e.g.:

.. prompt::
   :prompts: (gdb)

   l
   p xleft
   p fleft

Now let's step through the code and see if we can understand why ``I`` is not changing from 0, as well as whether
there are any other bugs...


VS Code
=======

We can `debug directly in VS code <https://code.visualstudio.com/docs/editor/debugging>`_.  The same concepts
described above apply.  Let's work our way through this.


