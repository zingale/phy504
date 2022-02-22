*******
Strings
*******

.. admonition:: reading

   Cyganek section 3.6

A C++ ``std::string`` has many similarities to a vector (in
particular, you could imagine doing ``std::vector<char>``.  But it is
specific to strings, and as such, has many useful functions that
operate on strings.

.. note::

   C++ can also use older C-style strings, which are essentially a
   null-terminated array of characters, e.g.,

   .. code:: c++

      char c_string[] = "this is my string";

   These are quite inflexible and can lead to coding errors if you are
   not careful, and we will avoid them as much as possible.

When working with strings, we include the ``<string>`` header.

Here's a first example.  We'll create a string and we'll concatenate
another string onto it using the ``+`` operator:

.. literalinclude:: ../../examples/strings/string_example.cpp
   :language: c++

Note that in this example, the strings that we add to our initial
string are actually C-style strings, but ``std::string`` knows how to
work with them.

Just like with vectors, we can use a constructor to create an initial
string filled with a character repeated many times.  For instance,
here's an 80-character line:

.. code:: c++

   std::string line(80, '-');

Note that ``'-'`` is a ``char`` and not a string.


