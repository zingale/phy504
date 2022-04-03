*********
Operators
*********

l-value vs. r-value
===================


Precedence
==========

What happens when we have an expression like:

.. code:: c++

   a + b * c;

The language defines the order that operators are considered, called
*operator precedence*.

This table: `C++ Operator Precedence
<https://en.cppreference.com/w/cpp/language/operator_precedence>`_
lists the order in which operators are evaluated.

In the example above, multiplication has higher precedence, so it is
evaluated first, and then the addition is done.

.. admonition:: try it...

   Play around with some expressions to explore the precedence of operators.



Prefix and postfix operators
============================

We haven't yet discussed the difference between ``++a`` and ``a++``.  These are the prefix
and postfix increment operators.  Let's do that now.

The prefix operator is:

.. code:: c++

   int a{0}, b{0};
   b = ++a;

The prefix increment operator first increments the value of the object
and then returns a reference to the result.
So in the above example, the result would be ``b = 1``.

Now consider the postfix operator:

.. code:: c++

   int c{0}, d{0};
   d = c++;

Here, a copy of ``c`` is made, then ``c`` is incremented, and finally the copy is returned.
So in the above example, the result would be ``d = 0``.

.. tip::

   The behavior of the prefix and postfix operator is essentially the same when it is 
   on its own line.  Also in the ``for`` construction:

   .. code:: c++

      for (int i = 0; i < 10; ++i) {
          ...

   it doesn't matter much which version you use -- although you will
   commonly see the prefix version used since it does not make a copy,
   and therefore can be faster.


Associativity
=============
