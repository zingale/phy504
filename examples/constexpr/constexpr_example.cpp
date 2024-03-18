#include <iostream>
#include <cmath>

template <int do_deriv>
inline
void func(const double x, double& f, double& dfdx) {

    f = std::sin(x);

    if constexpr(do_deriv == 0) {
        dfdx = 0.0;
    } else {
        dfdx = std::cos(x);
    }
}


int main() {

    double x = 1.0;

    double f;
    double dfdx;

    func<0>(x, f, dfdx);

    std::cout << "with template parameter = 0: " << f << " " << dfdx << std::endl;

    func<1>(x, f, dfdx);

    std::cout << "with template parameter = 0: " << f << " " << dfdx << std::endl;

}
