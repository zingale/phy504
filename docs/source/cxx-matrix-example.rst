***************
Example: Matrix
***************

.. _sec:cxx_matrix:

Let's look at an example from your text that create a very simple matrix container as a vector-of-vectors.

We'll write our own version of what the text does.

.. literalinclude:: ../../examples/vectors/simple_matrix.cpp
   :language: c++
   :caption: ``simple_matrix.cpp``

.. tip::

   Notice that we use some type aliases to make it easy to reuse this datatype:

   .. code:: c++

      using real_vec_t = std::vector<double>;
      using real_mat_t = std::vector<real_vec_t>;

Some comments:

* For our matrix ``M``, ``M[0]`` is the first row.  It is a vector,
  and the columns in that row are all stored together in that vector.
  This is an example of `row major ordering
  <https://en.wikipedia.org/wiki/Row-_and_column-major_order>`_ of the
  data.

* To access an element at row ``irow`` and column ``jcol``, we do:
  ``M[irow][jcol]``.  The first indexing, ``M[irow]`` gives us the vector that
  holds the row ``irow`` data.  Then we just index that vector with
  ``[jcol]`` to get the position corresponding to the column we want.

* When we ``push_back()`` onto the matrix, we are adding a whole new row.

* When we loop over elements, we first loop over rows (outer loop) and
  then we loop over the columns in that row---that data is
  contiguous, so this looping will make the best use of memory cache.

* Both of our operations involve sums over elements---we are careful
  to first initialize the sum to ``0`` before adding to it.


.. danger::

   We do nothing here to enforce that every row has the same number of
   elements---this can potentially be unsafe if we try to access
   beyond the limits of a row.  We'll fix this later.


Looping over elements
=====================

We can loop over elements using range-based loops by first looping
over rows and then looping over the columns in the row:

.. code:: c++

    for (auto row : M) {
        for (auto e : row) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

Here, the first ``for`` loop results in ``row`` being a ``real_vec_t``
in each iteration, looping over the rows.  Then the second ``for``
loop gives us a single element in that row (it is a loop over the
columns of that row).

This way of looping also demonstrates how the data is stored in the
matrix---this is called `row-major ordering
<https://en.wikipedia.org/wiki/Row-_and_column-major_order#:~:text=In%20row%2Dmajor%20order%2C%20the,column%20in%20column%2Dmajor%20order.>`_.
We'll discuss this more shortly.
