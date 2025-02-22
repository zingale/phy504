# Homework #4

### due: Friday Mar 8, 2024

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).
https://zingale.github.io/phy504/inclass-rk2-orbit.html
> Note: using ChatGPT or similar AI tools to write your code is not allowed.

1. Let's learn a bit more about the functions in the `algorithm` and `numeric` headers.

   Write a program that creates a vector of doubles containing the
   whole numbers `1.0` through 10.0`.  Now do the following:

   a. Use `std::transform()` (see
      https://en.cppreference.com/w/cpp/algorithm/transform) to
      convert the elements in the vector to the square root of the
      element.  Use a *lambda function* with `std::transform()`.

      The result should be a vector with elements `{1, 1.41421, 1.73205, 2, ...}`

   b. Now use `std::accumulate()` (see https://en.cppreference.com/w/cpp/algorithm/accumulate)
      to get the sum of the elements in the transformed vector and print it to the screen.



2. Let's revisit our problem of integrating the orbit of Earth around the Sun.

   https://zingale.github.io/phy504/cxx-orbit-example.html

   Your task is to make the following modifications:

   a. Have the program write the solution out to a file instead of the screen.

      For this, you should modify the `write_history()` function.

   b. Add a function to compute the error in the solution.  You should
      call it `error()` and it should return a `double`, I'll leave it
      to you to determine what arguments are needed for the function.

      There are many different ways we can define the error, but let's
      do a simple definition.  Our orbit is circular, so the radius
      should not change from the starting point to the end.  Define
      the error as the magnitude of the difference between the initial
      and final orbital radius after integrating for one period.

      Now in the `main()` function, integrate the planet with 4
      different values of `dt`, each changing by a factor of 2 with
      the previous.  Have your program print out `dt` and the error
      for that integration.

      It would be helpful to have your `write_history()` routine
      use different filenames for each timestep so you can compare.

   c. In class, we implemented Runge-Kutta 2nd order (RK2).  This
      is here:

      https://zingale.github.io/phy504/inclass-rk2-orbit.html

      Create a new function, `integrate_rk2()` in your code to do this method instead.

      Now in your `main()`, for a single choice of `dt`, integrate an
      orbit for a period with the original method and the new RK2 and
      print out the errors.  This new method should do better.
