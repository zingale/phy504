#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> container{100, 200, 300, 400, 500, 600};

    // search through the entire vector to find the first instance of the
    // element "400"

    auto pos = std::find(container.cbegin(), container.cend(), 400);

    std::cout << "element found: " << *pos << std::endl;

    // output the remaining elements after the one we searched for

    for (auto it = pos+1; it < container.cend(); ++it) {
        std::cout << *it << std::endl;
    }
}
