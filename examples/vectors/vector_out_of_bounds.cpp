#include <iostream>
#include <vector>

int main() {

    std::vector<int> int_vec{0, 1, 2, 3, 4, 5};

    std::cout << "size of the vector = " << int_vec.size() << std::endl;
    std::cout << "capacity of the vector = " << int_vec.capacity() << std::endl;
    std::cout << "maximum possible size = " << int_vec.max_size() << std::endl;

    std::cout << int_vec[7];

}
