#include <iostream>

int main() {

    int x{10};
    int &x_ref = x;

    x_ref++;

    std::cout << "x is now " << x << std::endl;

}
