#include <iostream>
#include <memory>

int main() {

    const int size(10);

    // new way to allocate

    auto data = std::make_unique<double []>(size);

    for (int i = 0; i < size; ++i) {
        data[i] = 1.0;
    }

    // old C++ way

    double* data_old = new double [size];

    for (int i = 0; i < size; ++i) {
        data_old[i] = 1.0;
    }

    delete[] data_old;
}
