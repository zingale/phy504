#include <iostream>
#include <cmath>
#include <csignal>
#include <cfenv>
#include <stacktrace>

void fpe_handler(int s) {
    std::cout << "floating point exception, signal " << s << std::endl;

    std::cout << std::stacktrace::current() << std::endl;

    abort();
}

double trouble(double x) {
    return std::sqrt(x);
}


int main() {

    feenableexcept(FE_INVALID|FE_DIVBYZERO|FE_OVERFLOW);

    signal(SIGFPE, fpe_handler);

    double x{-1};

    double y = trouble(x);

    for (int i = 0; i < 10; ++i) {
        y += std::pow(x, i);
    }

    std::cout << y << std::endl;

}
