************
More Vectors
************

Let's look at some more ways we can work with vectors.

Initializing
============

We can initialize a vector when we declare it.  The following creates a vector with 5 elements, all initialized to 0:

.. code:: c++

   vector<double> container{5, 0.0};

Here we instead initialize a vector by telling it the values of each of the elements:

.. code:: c++

   vector<double> container2{10.0, 20.0, 30.0};

Size
====

We can always get the number of elements in a vector via the ``size()`` function:

.. code:: c++

   vector<int> int_vec{1, 2, 3, 4, 5};

   int nlen = int_vec.size();

Insert

Find

accumulate


Resizing

Clear

Indexing out of bounds

