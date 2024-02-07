#include <iostream>
#include <map>
#include <string>

int main() {

    std::map<std::string, int> a;

    a["one"] = 1;
    a["two"] = 2;

    for (const auto& [key, value] : a) {
        std::cout << "[" << key << "] = " << value << std::endl;
    }

}