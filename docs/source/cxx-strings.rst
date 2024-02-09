*******
Strings
*******

.. admonition:: reading

   Cyganek section 3.6

A C++ ``std::string`` has many similarities to a vector (in
particular, you could imagine doing ``std::vector<char>``.  But it is
specific to strings, and as such, has many useful functions that
operate on strings.

.. warning::

   C++ can also use older C-style strings, which are essentially a
   null-terminated array of characters, e.g.,

   .. code:: c++

      char c_string[] = "this is my string";

   These are quite inflexible and can lead to coding errors if you are
   not careful, and we will avoid them as much as possible.

.. note::

   In C++, single characters (``char``) are enclosed in single-quotes, e.g., ``'A'``,
   while strings are enclosed in double quotes, e.g. ``"string"``.

When working with strings, we include the ``<string>`` header.

Here's a first example.  We'll create a string and we'll concatenate
another string onto it using the ``+`` operator:

.. literalinclude:: ../../examples/strings/string_example.cpp
   :language: c++
   :caption: ``string_example.cpp``

Note that in this example, the strings that we add to our initial
string are actually C-style strings, but ``std::string`` knows how to
work with them.

Just like with vectors, we can use a constructor to create an initial
string filled with a character repeated many times.  For instance,
here's an 80-character line:

.. code:: c++

   std::string line(80, '-');

Note that ``'-'`` is a ``char`` and not a string.

.. note::

   A nice overview of working with C++ strings is provided by "hacking C++":
   `std::string <https://hackingcpp.com/cpp/std/string.png>`_

Find and Replace
================

``string`` has find and replace member functions.  Here's an example of
extracting the basename of a file from a path and then replacing the
extension.

Note: there are a lot of different ways we can do a replace:
`std::string::replace calls
<https://www.cplusplus.com/reference/string/string/replace/>`_ .

.. literalinclude:: ../../examples/strings/string_replace.cpp
   :language: c++
   :caption: ``string_replace.cpp``

Other Functions
===============

There are a large number of member functions that work on strings.
See for instance: https://www.cplusplus.com/reference/string/string/


.. admonition:: try it...

   Let's try to use ``std::string::find_first_of``, following this:
   https://www.cplusplus.com/reference/string/string/find_first_of/
