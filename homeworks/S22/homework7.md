# Homework #7

### due: Monday, April 4, 2022

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

1. Write a `class` called `Rectangle` (not a `struct`!).  Have the constructor take the
   length and height and write *member functions* to compute and
   return the area and perimeter, and another member function
   `is_square()` that returns `true` if the rectangle is also a
   square.

   You should be able to do something like this:

   ```
   Rectangle rect(1.0, 2.0);
   double area = rect.area();
   ```

2. Expand on our `Vector2d` class by adding the following capabilities:

   * The ability to multiply a `Vector2d` by a scalar (overload `*` for this).

     Note: there are two cases here:

     ```
     Vector2d v;
     double a;
     auto v1 = v * a;
     auto v2 = a * v;
     ```

     The first case can be a member function with the signature:

     ```
     Vector2d operator* (double a);
     ```

     The second case can be a friend, with the signature:

     ```
     friend Vector2d operator* (double a, const Vector2d& v);
     ```

   * The ability to divide a `Vector2d` by a scalar (overload `/` for this).

     Here it only makes sense to consider:

     ```
     auto v3 = v / a;
     ```

     which is controlled by the member function:

     ```
     Vector2d operator/ (double a);
     ```

   * An `abs()` member function that returns the vector magnitude.

   * A `dot()` member function that takes another vector and computes the dot
     product, returning a scalar.

  Write a `main()` that exercises all of these functions.
  
