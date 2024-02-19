# Homework #2

### due: Monday Feb 19, 2024

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

> Note: using ChatGPT or similar AI tools to write your code is not allowed.

1. In this repo you'll find a C++ program called `numbers.cpp`.  As written,
   it will read in numbers from the user and add them to a vector.  This will
   continue until the user enters a negative number.  At that point, the program
   will return the sum of the input numbers.

   *Your task*: modify this program to return the average and the standard deviation
   of the numbers.

   *Aside*: In the above code, we did our sum by
   looping over the data directly,  But we
   can instead use `std::accumulate()`.  This function is described here:
   https://en.cppreference.com/w/cpp/algorithm/accumulate

2. Consider a vector initialized as:

   ```
   std::vector<double> vec{0.1, 10.0, -2.9, 5, 12.2, 0.0, -103.2};
   ```

   Let's see how to use some of the functions in the `algorithms` header.

   Write a code to create this vector and then loop over elements to find
   the maximum element in the vector.  Do the same to find the minimum
   element in the vector.  Be sure to output the result to the console.

   Now repeat this, but use `std::max_element` (https://en.cppreference.com/w/cpp/algorithm/max_element)
   and `std::min_element` (https://en.cppreference.com/w/cpp/algorithm/min_element) to get the same result.
