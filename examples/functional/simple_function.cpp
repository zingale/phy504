#include <iostream>
#include <functional>

void doit(double x, std::function<double(double)> f) {
    std::cout << "calling our function" << std::endl;
    double r = f(x);
    std::cout << "result = " << r << std::endl;
}

double f(double x) {
    return x*x*x;
}

int main() {

    double x{2};
    doit(x, f);

}