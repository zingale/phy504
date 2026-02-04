********************************
Preview: C++23 enumerate and zip
********************************

Two useful *views* for iterating over containers and ``enumerate`` and ``zip``.  These
were introduced in C++23 and are defined in the ``<ranges>`` header.

``enumerate``
=============

.. literalinclude:: ../../examples/enumerate/enumerate_example.cpp
   :language: c++
   :caption: ``enumerate_example.cpp``

Note that ``enumerate`` returns a reference to the data even if you add ``const`` before
the ``auto``.

``zip``
=======

.. literalinclude:: ../../examples/enumerate/zip_example.cpp
   :language: c++
   :caption: ``zip_example.cpp``

In this example, the two containers are not the same length, so the looping ends when
the first container runs out of objects.

