#include <iostream>
#include <vector>

#include "container.H"

Container fill_new() {

    std::cout << "in fill_new()" << std::endl;
    Container c_new(20);

    for (int i = 0; i < c_new.get_size(); ++i) {
        c_new.get_data()[i] = 1.0;
    }

    std::cout << "leaving fill_new()" << std::endl;
    return c_new;
}

int main() {

    std::cout << "1. doing Container c(10)" << std::endl;

    Container c(10);

    std::cout << std::endl;

    auto c_data = c.get_data();
    auto c_size = c.get_size();

    for (int i = 0; i < c_size; ++i) {
        c_data[i] = static_cast<double>(i);
    }

    std::cout << c << std::endl;

    std::cout << "2. doing c1 = c" << std::endl;

    auto c1 = c;

    std::cout << c1 << std::endl;

    std::cout << "3. doing c1 = fill_new()" << std::endl;

    c1 = fill_new();

    std::cout << c1 << std::endl;

    std::cout << "4. doing auto c2 = fill_new()" << std::endl;

    auto c2 = fill_new();

    std::cout << std::endl;

    std::cout << "5. doing cvec.push_back(fill_new())" << std::endl;

    std::vector<Container> cvec;
    cvec.push_back(fill_new());

    std::cout << std::endl;

    std::cout << "done with main" << std::endl;

}
