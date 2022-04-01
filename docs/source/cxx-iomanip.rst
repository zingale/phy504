****************
I/O Manipulators
****************

.. admonition:: reading

   See the `cppreference.com page on iomanip <https://en.cppreference.com/w/cpp/header/iomanip>`_

We've been using the stream operators for I/O and have occasionally changed the formatting.
Let's look at this in more detail now.

There are a few ways to specify the format of numbers:

* ``std::fixed`` : output all floating point numbers in fixed form, e.g. ``0.00001``

* ``std::scientific`` : output all floating point numbers in scientific notation, e.g., ``1.e-5``

* ``std::defaultfloat`` : use the default formatting.

We can control the precision of the output with

* ``std::setprecision(N)`` : outputs ``N`` decimal places

To output in columns, we can use:

* ``std::setw(N)`` : use a column with a ``N`` characters

* ``set::setw(c)`` : fill empty places in a column with the ``char c``.

* ``std::left`` : flush left in the column

* ``std::right`` : flush right in the column


.. note::

   Most of these are persistent -- once you set them, the format will remain in place until
   it is reset.  The one exception is ``std::setw()`` -- this needs to be set before each
   output.

Here's an example using these different formats:

.. literalinclude:: ../../examples/iomanip/io_examples.cpp
   :language: c++
   :caption: ``io_examples.cpp``

