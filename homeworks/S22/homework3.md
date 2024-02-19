# Homework #3

### due: Friday Feb 25, 2022

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

1. In our example with `std::numeric_limits`, we saw how to find the
   range of numbers that can be stored in a type.  For floating-point
   numbers, `epsilon` is also an important quantity.

   Write a program that adds the `epsilon` from
   `std::numeric_limits<double>` to `1.0` and compares the result
   against `1.0` using `==`.  Store the result in a variable of type
   `bool` and print it out.

   What happens if you try adding twice `epsilon` or one-half of `epsilon`?
   Extend your program to consider those cases.

2. Let's create a vector holding the first N terms of the Fibonacci
   sequence (https://en.wikipedia.org/wiki/Fibonacci_number).

   * Start by creating a C++ vector containing the numbers `0` and `1`.

   * Ask the user how many values they want to be computed, and loop
     using the `for (start; end; increment)` syntax we saw in class
     adding the next number in the sequence each iteration.

     Be sure to account for the fact that you already have the first 2
     elements (`0` and `1`).

   * One the sequence is stored in the vector, use the range-based for
     loop we saw in class to output the numbers to the screen, one per
     line.
