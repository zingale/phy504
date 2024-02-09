#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> container{100, 200, 300, 400, 500, 600};

    auto pos = std::find(container.cbegin(), container.cend(), 400);

    // here we seek the distance from the beginning of the vector
    auto idx = std::distance(container.cbegin(), pos);

    std::cout << "index = " << idx << std::endl;

    // note: we need to be careful here and ensure that idx is >= 0.
    // and < the size of the vector.  We could be accessing out
    // of bounds if the value we searched for was not in the vector
    std::cout << "value = " << container[idx] << std::endl;
}
