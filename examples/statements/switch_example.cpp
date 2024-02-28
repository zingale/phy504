#include <iostream>
#include <string>

int main() {

    int i{2};
    std::string text{};

    switch (i) {

        case 0:
            text = "zero";
            break;

        case 1:
            text = "one";
            break;

        case 2:
        case 3:
        case 4:
            text = "2 <= i <= 4";
            break;

        default:
            text = "i > 4";

    }

    std::cout << text << std::endl;

}
