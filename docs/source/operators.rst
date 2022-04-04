*********
Operators
*********

.. admonition:: reading

   Cyganek section 3.19

lvalue vs. rvalue
===================

We will often see *lvalue* and *rvalue* used:

* lvalue: an object that can be assigned to -- i.e., it can be put on
  the lefthand side of the ``=`` operator.

* rvalue: an object that can appear on the righthand side of the ``=``
  operator -- it acts as a value.

see, e.g., `Assignment: l-values and r-values <https://en.wikipedia.org/wiki/Value_(computer_science)#Assignment:_l-values_and_r-values>`_.

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

When an expression has two operators at the same precedence, `operator
associativity rules
<https://en.wikipedia.org/wiki/Operator_associativity>`_ come into
play.  Most operators in C++ are *left associative* -- that is, they
are grouped from the left, but some are right associative (like the
unary operators and assignment) meaning that they are grouped from the
right.

Consider assignment:

.. code:: c++

   a = b = c

Since ``=`` has right associativity, we interpret this as ``a = (b = c)``, which can further
be thought of as ``b = c; a = c``.

.. note:: 

   In C++, assignment evaluates to the left value.

In the expression:

.. code:: c++

   a + b - c

Both ``+`` and ``-`` have the same precedence, and these are
left-associative, so first ``a + b`` is evaluated and then ``c`` is
subtracted from that result.

