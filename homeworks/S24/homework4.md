# Homework #3

### due: Wed Feb 28, 2024

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

> Note: using ChatGPT or similar AI tools to write your code is not allowed.

1. In class, we created a [simple matrix](https://zingale.github.io/phy504/cxx-matrix-example.html)
   as `std::vector<std::vector<double>>`.  A simple version of that code
   is in this repo for reference, as `simple_matrix.cpp`.

   Using the same datatypes, `real_vec_t` and `real_mat_t`, write a new code
   that does the following:

   * Read in from the user the size, $N$, for a square matrix.

   * Create an $N \times N$ [Hilbert matrix](https://en.wikipedia.org/wiki/Hilbert_matrix)
     by setting the values as:

     $$H_{ij} = \frac{1}{i + j + 1}$$

     where $i = 0, \ldots, N-1$, and similarly for $j$.

   * Read in from the user $N$ numbers and store them in a vector call $x$

   * Compute the matrix vector product $A x$ by writing the appropriate loops
     and output the result.

2. We'll write a simple code that does projectile motion.

   * Create a `struct` called `Projectile` with 3 data members: `t`, `x`, `y`

   * Ask the user for an angle (positive, from the horizontal),
     initial velocity, and a time interval $\Delta t$ at which we want
     to store the projectile's position.

   * Create a vector of `Projectile`

   * Start at $t = 0$ and loop for as long as the projectile is in the air and:

     * Compute the current $x$ and $y$ position of the projectile

     * If $y < 0$ exit the loop; otherwise, store the position in your vector

     * Increment the time by $\Delta t$

   * Finally, output the trajectory as rows with 3 columns: $t$, $x$, and $y$.
