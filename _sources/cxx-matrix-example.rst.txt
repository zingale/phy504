**************
Matrix Example
**************

Let's look at an example from your text that create a very simple matrix container as a vector-of-vectors.

We'll write our own version of what the text does.

.. literalinclude:: ../../examples/vectors/simple_matrix.cpp
   :language: c++

Some comments:

* Notice that we use some type aliases to make it easy to reuse this data.

* For our matrix ``M``, ``M[0]`` is the first row.  It is a vector,
  and the columns in that row are all stored together in that vector.
  This is an example of `row major ordering
  <https://en.wikipedia.org/wiki/Row-_and_column-major_order>`_ of the
  data.

* To access an element at row ``r`` and column ``c``, we do:
  ``M[r][c]``.  The first indexing, ``M[r]`` gives us the vector that
  holds row ``r`` 's data.  Then we just index that vector with
  ``[c]`` to get the position corresponding to the column we want.

* When we ``push_back()`` onto the matrix, we are adding a whole new row.

* When we loop over elements, we first loop over rows (outer loop) and
  then we loop over the columns in that row -- that data is
  contiguous, so this looping will make the best use of memory cache.

* We do nothing here to enforce that every row has the same number of
  elements -- this can potentially be unsafe if we try to access
  beyond the limits of a row.  We'll fix this later.

* Both of our operations involve sums over elements -- we are careful
  to first initialize the sum to ``0`` before adding to it.
