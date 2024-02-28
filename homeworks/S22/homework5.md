# Homework #5

### due: Friday March 11, 2022

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

1. We want to compute the position of a projectile at several intervals in time.

   Create a ``struct`` that holds the state of the projectile at one
   instance in time: t, x, y

   Now ask the user for the initial velocity magnitude, angle above the
   horizontal, and time interval (dt) to output (choosing 10 m/s, 45
   degrees, and 0.1 s is reasonable, for instance).

   We want to fill a ``vector`` with the position of the projectile at
   each instance of time (so the ``vector`` will be of our ``struct``
   type).  Use a while loop and loop so long as y >= 0.  Increment the
   time by dt and compute the current position of the projectile and
   store it in the vector.  Assume that the projectile starts at (0,
   0).

   Finally, loop over the vector of structs and output the time, x,
   and y as a table (3 columns, with each row a single instance in
   time).


2. a. Initialize a string with `"may the force be with you"` (note: all lowercase).

      Now loop over the characters in the string using an **iterator**
      (e.g. `.begin()` and `.end()`).  Your goal is to capitalize the
      first letter of each word.  The first character clearly needs to
      be capitalized.  Then in each iteration, check if the current
      character is a space, and if so, set a flag such that in the
      next iteration you capitalize that character.

      You can use the method ``std::toupper()`` to convert a single
      character to be uppercase.

      When you are done, output the transformed string.

   b. Now redo part a (making a separate program), but this time using
      a reference in a ranged-for loop instead of a for loop with
      iterators.
