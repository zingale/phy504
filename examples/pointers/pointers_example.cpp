#include <iostream>

int main() {

    double x{2.0};

    double *x_ptr;

    double &x_ref = x;

    std::cout << "x = " << x << std::endl;

    // we can access x through the reference x_ref

    x_ref *= 2.0;

    std::cout << "x = " << x << std::endl;
    std::cout << "x_ref = " << x_ref << std::endl;

    // now let's associate x_ptr with x

    x_ptr = &x;

    // to access the data pointed to by x_ptr, we need to
    // dereference it

    std::cout << "x_ptr = " << x_ptr << std::endl;
    std::cout << "*x_ptr = " << *x_ptr << std::endl;

    // likewise, to modify its value

    *x_ptr *= 2;

    std::cout << "x = " << x << std::endl;
    std::cout << "x_ref = " << x_ref << std::endl;

}