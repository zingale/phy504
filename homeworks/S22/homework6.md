# Homework #6

### due: Monday March 28, 2022

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

1. Let's revisit our problem of integrating the orbit of Earth around the Sun.

   https://zingale.github.io/phy504/cxx-orbit-example.html

   Your task is to make the following modifications:

   a. Have the program write the solution out to a file instead of the screen.

      For this, you should modify the `write_history()` function.  You can hardcode
      the output filename into the code.

   b. Add a function to compute the error in the solution.  You should
      call it `error()` and it should return a `double`, I'll leave it
      to you to determine what arguments are needed for the function.

      There are many different ways we can define the error, but let's
      do a simple definition.  Our orbit is circular, so the radius
      should not change from the starting point to the end.  Define
      the error as the magnitude of the difference between the initial
      and final orbital radius after integrating for one period.

      Now in the `main()` function, integrate the planet with 3
      different values of `dt`, each changing by a factor of 2 with
      the previous.  Have your program print out `dt` and the error
      for that integration.

   c. Let's change the integration method.  We implemented first-order
      Euler method.  Now we will instead implement a 2nd order
      accurate method (sometimes called Runge-Kutta 2nd order, RK2).

      Create a new function, `integrate_rk2()` to do this method.
      RK2 requires 2 righthand side evaluations.  The steps are:

      * evaluate the righthand side at the initial time, t0, using the
        initial state Y0.  Call the result k0 = rhs(t0, Y0).

      * compute the solution at the midpoint in time, tmid = t0 + dt/2
        as

        Ymid = Y0 + 0.5 * dt * k0

      * evaluate the righthand side at the midpoint in time, k1 =
        rhs(tmid, Ymid)

      * compute the final solution as:

        Ynew = Y0 + dt * k1

      Here, Y is the vector of solution variables (`x`, `y`, `vx`, `vy` for us)

      You can read more about this in my notes here:
      https://zingale.github.io/comp_astro_tutorial/basics/ODEs/ODEs-partII.html

      Now in your `main()`, for a single choice of `dt`, integrate an
      orbit for a period with the original method and the new RK2 and
      print out the errors.  This new method should do better.
