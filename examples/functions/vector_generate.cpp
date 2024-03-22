#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> int_vec{};

    int_vec.resize(10);
    //std::generate(int_vec.begin(), int_vec.end(), [n=0] () mutable { return n++;});

    int m{0};
    std::generate(int_vec.begin(), int_vec.end(), [&] () { return m++;});

    for (auto e : int_vec) {
        std::cout << e << " ";
    }

    std::cout << std::endl;

}
