#include <iostream>
#include <map>
#include <string>

int main() {

    std::map<std::string, int> a;

    a["A"] = 1;
    a["B"] = 2;
    a["C"] = 3;

    if (a.contains("D")) {
        std::cout << "element D is a member of the map" << std::endl;
    } else {
        std::cout << "element D is not defined" << std::endl;
    }

}
