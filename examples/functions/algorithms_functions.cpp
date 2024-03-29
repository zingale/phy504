#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool size_compare(const std::string& a, const std::string& b);

int main() {

    std::vector<std::string> titles{"a new hope",
                                    "the empire strikes back",
                                    "return of the jedi",
                                    "the phantom menace",
                                    "attack of the clones",
                                    "revenge of the sith",
                                    "the force awakens",
                                    "the last jedi",
                                    "the rise of skywalker"};

    std::sort(titles.begin(), titles.end());

    for (auto e : titles) {
        std::cout << e << std::endl;
    }
    std::cout << std::endl;

    // now sort by string length

    std::sort(titles.begin(), titles.end(), size_compare);

    for (auto e : titles) {
        std::cout << e << std::endl;
    }
    std::cout << std::endl;

}

bool size_compare(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}
