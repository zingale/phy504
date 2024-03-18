# Homework #5

### due: Wed Mar 27, 2024

> Each student is responsible for doing their own work.  You are welcome to
> discuss this on slack or in class, but when it comes to writing the code,
> you are expected to write it yourself (and not just copy from someone).

> Note: using ChatGPT or similar AI tools to write your code is not allowed.

1. In a header file, create a simple class called




2. Create a class called `Vector3d` based on the `Vector2d` class from lecture:
   https://zingale.github.io/phy504/cxx-vector2d-class.html

   You will need to add a `z` component to the member data, add a
   `set_z` function, and update all of the member functions to work in
   3D.

   Now add the following functions:

   * The ability to multiply a `Vector3d` by a scalar (overload `*` for this).

     Note: there are two cases here:

     ```
     Vector3d v;
     double a;
     auto v1 = v * a;
     auto v2 = a * v;
     ```

     The first case can be a member function with the signature:

     ```
     Vector3d operator* (double a);
     ```

     The second case can be a friend, with the signature:

     ```
     friend Vector3d operator* (double a, const Vector3d& v);
     ```

   * The ability to do a dot product of two vectors by multiplication:

     ```
     Vector3d v1(1, 2, 3);
     Vector3d v2(4, 5, 6);

     double dot = v1 * v2;
     ```

     This will be another overload of multiplication:

     ```
     double operator* (const Vector3d& v);
     ```

   * The ability to divide a `Vector3d` by a scalar (overload `/` for this).

     Here it only makes sense to consider:

     ```
     auto v3 = v / a;
     ```

     which is controlled by the member function:

     ```
     Vector3d operator/ (double a);
     ```
