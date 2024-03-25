*******
Testing
*******

As we write increasingly complex codes, we want some way to automate
testing to ensure that our changes don't break the functionality.

There are a wide variety of tests for general codes (the Wikipedia
`software testing <https://en.wikipedia.org/wiki/Software_testing>`_
page gives a good overview):

* *unit testing* : for each of your functions, you provide one or more
  tests that exercise that function alone, ensuring that it gives the
  expected result.

* *integration testing* : you test the several pieces of the program
  or the entire program interacting.  Since unit tests are done in isolation,
  integration tests will catch issues in how the different functions work
  together.

* *regression testing* : you store a "correct answer" from your code and
  you run the code regularly to see if any changes have unexpectedly
  changed the answer.

For numerical algorithms, we also can discuss:

* *convergence testing* : some algorithms have a formal order of
  accuracy, For instance, our Euler method for integrating the orbits
  is first-order accurate in time, but the RK2 algorithm in your
  homework is second-order accurate in time.  In convergence testing
  you varying the space or time resolution and see if you get the
  expected convergence.

* *verification* and *validation* : verification asks the question "am
  I solving the equations correctly?", while validation asks "am I
  solving the right equations to begin with?"  For verification, one
  can compare to known analytic solutions of the set of equations you
  are solving.  For validation, you will typically want to compare to
  experiments to see if you are appropriately modeling all of the
  physics you need.

