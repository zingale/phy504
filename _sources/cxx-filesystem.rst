******************
Filesystem Library
******************

.. admonition:: reading

   See the `cppreference.com page on filesystem <https://en.cppreference.com/w/cpp/filesystem>`_

C++17 introduced the filesystem library to deal with paths and file operations.

By creating a ``path`` object, full paths to files can be built up
using ``/`` as an operator, just like we would do on the commandline:

.. literalinclude:: ../../examples/filesystem/paths.cpp
   :language: c++
   :caption: ``paths.cpp``

Here's an example of looking at the path and different parts of a filename:

.. literalinclude:: ../../examples/filesystem/filesystem_example.cpp
   :language: c++
   :caption: ``filesystem_example.cpp``

