# Homework #4

### due: Friday March 4, 2022

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

1. Let's expand on our example of a matrix.  Starting with our Matrix example:

   * Read in an integer from the user, `N`

   * Create an empty matrix, `RealMatrix I`

   * Using loops, append `N` rows each with `N` columns with the value
     ``1`` on the diagonal and `0` everywhere else.

     That is, you are constructing an NxN identity matrix.

     There are likely a few ways to do this.  One way you can do this
     is that inside the loop over rows you create a `RealVec` and then
     loop over columns `push_back()` -ing the appropriate values, and
     then finally push the filled row onto `I`.

   * Print the matrix out to the screen.

2. Let's play with a vector of strings.

   * Create an empty vector of strings.

   * Let's ask the user for 10 words.  In a loop, prompt the user for
     a word and push it back onto our vector.  Do this until you have
     10 words.

   * Now, by looping over the words in the vector, find the longest
     word.  Remember that for a string, `.size()` can tell you its
     length.

   * Print out the longest word.

     If there are multiple words of the same longest length, just
     print the first.

   Later, we'll see how to do this in a simpler fashion using the
   algorithm `std::max_element` and a function.
