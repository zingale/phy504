# PHY 504 final project

For your final project, you need to write a C++ program that does
something interesting / fun, and demonstrates that you understand the
language concepts we discussed in class.

You are free to choose the application as you wish.  Here are some
suggestions:


* A Tower of Hanoi game solver (see
  https://en.wikipedia.org/wiki/Tower_of_Hanoi for the game
  description / rules and some algorithms for solving it)

* A "wordle game" (see https://en.wikipedia.org/wiki/Wordle) You
  should provide a `dictionary.txt` file with a list of words that can
  randomly be picked as the answer that needs to be guessed.  Then
  give feedback to the user as they guess words (don't worry about
  checking whether the word entered by the user is a real word) follow
  the description of the game linked above.

  You can look up ANSI color codes if you want to have your program
  output color.

* A sudoku solver (see https://en.wikipedia.org/wiki/Sudoku).  You
  might need to read up on some of the algorithms that people try for
  solving Sudoku problems, and it is okay if your code only solves
  "easy"-level problems.

* A few-body integrator using RK2 or RK4 and the leapfrog integration
  method (https://en.wikipedia.org/wiki/Leapfrog_integration).  Here
  the gravity of each particle affects the others, so you need to
  consider all gravitational interactions between the masses.

  Have your code store the total energy of the system as a function of
  time and make plots demonstrating how well your two integration
  methods conserve energy (one should be substantially better than the
  other).

* Explore chaos in the Lorenz system (see
  https://en.wikipedia.org/wiki/Lorenz_system)

  This is a non-linear ODE system that exhibits chaos.  You need to
  write an integrator and then explore parameter space by varying the
  parameters in the problem and also looking how two initially-close
  solutions compare at long time.  You will want to read up on some of
  the dynamics of the Lorenz system.

* Implement a linear system solver (Ax = b) for a matrix A using
  Gaussian elimination with pivoting (see
  https://en.wikipedia.org/wiki/Gaussian_elimination)

  In addition to writing the Ax = b solver, would should write a
  function that multiplies a matrix by a vector, so you can check your
  result, e.g., A x_sol - b should be 0 for your solution x_sol.

* Expand our array class to complex numbers and write a Mandlebrot set
  generator.  You can have the code output a very simple bitmap image
  using the PPM image format (see, e.g.,
  https://stackoverflow.com/questions/36288421/c-create-png-bitmap-from-array-of-numbers)




For each project you need to do:

- [ ] a github repo

- [ ] make sure that the code compiles on the mathlab machines

- [ ] documentation (in the README is fine) describing what the program
      does, what assumptions are made, how the program is organized.

- [ ] every function has doxygen-style documentation that explains
      what it does, what are the inputs and what are the outputs.
      
- [ ] your code spread out logically into multiple functions / headers,
      demonstrating that you understand how to reuse code

- [ ] a makefile that builds in both optimized and debug mode (this
      should disable / enable asserts)

- [ ] at least one unit test (with the docs telling me how to run it and how
      to verify that it is correct)


Note:

 * If you use C++ features that we did not discuss in class, please
   reference where you learned them from.

 * If you used code samples found online, please reference them.  Your
   code must be considerably different than anything you might have
   worked from online.

 * If you are using some libraries that are not part of standard C++,
   include directions on how to install them and make sure that they
   work on the MathLab machines.
   
