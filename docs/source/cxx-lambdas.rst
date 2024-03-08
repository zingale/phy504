****************
Lambda Functions
****************

.. admonition:: reading

   A nice `lambda cheatsheet
   <https://hackingcpp.com/cpp/lang/lambdas.png>`_ is available from
   hackingcpp.com.


C++ has another type of function called a *lambda function*.  You can
think of a lambda as an `anonymous function
<https://en.wikipedia.org/wiki/Anonymous_function>`_ that can capture
data directly from its environment and work on it.  Lambda functions
are typically used when you only need to use a function in a single
place.

The general form of a lambda is:

   ``[`` *capture clause* ``] (`` *arguments* ``) {`` *statements* ``};``

with optionally some *specifiers* between the arguments and statements.

The capture clause tells the compiler how it can access data from the
surrounding scope:

* ``[=]`` means it captures objects by value
* ``[&]`` means it captures objects by reference

mixed types of capture are also possible, where you can capture some
data by value and others by reference

Here's a simple example:

.. literalinclude:: ../../examples/functions/lambda_examples.cpp
   :language: c++
   :caption: ``lambda_examples.cpp``




Sort Example
============

Lambdas make it easy to provide simply functions as arguments
to other functions (like we did with ``std::sort()`` previously).
Here's an implementation of that using a lambda function:

.. literalinclude:: ../../examples/functions/algorithms_functions_lambda.cpp
   :language: c++
   :caption: ``algorithms_functions_lambda.cpp``

.. admonition:: try it...

   We can change the sort to alphabetically by the last letter in the title
   by doing:

   .. code:: c++

      [] (const std::string& a, const std::string& b) {return a.back() < b.back();}
