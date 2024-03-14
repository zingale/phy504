#include <iostream>

template <int n>
inline
constexpr double power(double x) {

    if constexpr (n < 0) {
        return 1.0 / power<-n>(x);
    } else if constexpr (n == 0) {
        return 1.0;
    } else {
        return x * power<n-1>(x);
    }

}

int main() {

    double x{3.5};

    std::cout << power<2>(x) << std::endl;

}
