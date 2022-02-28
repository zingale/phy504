******
Arrays
******

.. admonition:: reading

   Cyganek section 3.10

Vectors can grow in size as needed to accommodate additional data.  In contrast, arrays are fixed-size.  


stack vs. heap

.. note::

   In C and older C++, you will see fixed-side arrays declared as:

   .. code:: c++

      double x[10];
      int p[10][20];

   For a nice discussion of the differences between C-arrays and ``std::array`` see:
   `https://coders-corner.net/2018/06/16/stdarray-vs-c-style-array/ <https://coders-corner.net/2018/06/16/stdarray-vs-c-style-array/>`_


