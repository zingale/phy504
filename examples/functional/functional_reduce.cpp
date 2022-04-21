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
    std::vector<int> a{0, 1, 2, 3, 4, 5};

    std::cout << "sum a: " <<
        reduce<int>(a, 0, add<int>) << std::endl;
    
    std::cout << "max a: " <<
        reduce<int>(a, std::numeric_limits<int>::min(), max<int>) << std::endl;

    std::vector<double> b{-1.32, M_PI, 20.0, 1.e3, std::sqrt(2.0)};

    std::cout << "sum b: " <<
        reduce<double>(b, 0, add<double>) << std::endl;
    
    std::cout << "max b: " <<
        reduce<double>(b, std::numeric_limits<double>::lowest(), max<double>) << std::endl;

    std::cout << "min b: " <<
        reduce<double>(b, std::numeric_limits<double>::max(),
        [] (double x, double y) {return std::min(x, y);}) << std::endl;


}