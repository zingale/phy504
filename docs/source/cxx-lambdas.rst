****************
Lambda Functions
****************

C++ has another type of function called a *lambda function*.  You can
think of a lambda as an `anonymous function
<https://en.wikipedia.org/wiki/Anonymous_function>`_ that can capture
data directly from its environment and work on it.  Lambda functions
are typically used when you only need to use a function in a single
place.

Lambdas make it easy to provide simply functions as arguments
to other functions (like we did with ``std::sort()`` previously).



Sort Example
============

.. literalinclude:: ../../examples/functions/algorithms_functions_lambda.cpp
   :language: c++

