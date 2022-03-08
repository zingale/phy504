#include <iostream>

void f1(double x);
void f2(double& x);
void f3(const double& x);

void f1(double x) {
    x *= 2;
}

void f2(double& x) {
    x *= 2;
}

void f3(const double& x) {
    //x *= 2;
}

int main() {

    double a{1};

    std::cout << "initial a = " << a << std::endl;

    f1(a);
    std::cout << "after f1(a) = " << a << std::endl;

    f2(a);
    std::cout << "after f2(a) = " << a << std::endl;

}
