#include <iostream>
#include <functional>
#include <vector>
#include <limits>
#include <cmath>

template <typename T>
T add(T x, T y) {
    return x + y;
}

template <typename T>
T max(T x, T y) {
    return std::max(x, y);
}

template <typename T>
T reduce(std::vector<T>&  v, T init, std::function<T(T, T)> f) {
    T val{init};
    for (auto e : v) {
        val = f(val, e);
    }
    return val;
}

int main() {
    std::vector<double> b{-1.32, M_PI, 20.0, 1.e3, std::sqrt(2.0)};

    std::cout << "sum b: " <<
        reduce(b, 0.0, add<double>) << std::endl;

}
