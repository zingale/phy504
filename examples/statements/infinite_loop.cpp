#include <iostream>
#include <string>

int main() {

    std::string word{};

    while (true) {

        std::cout << "Enter a word (0 to exit): ";
        std::cin >> word;

        if (word == "0") {
            break;
        }

        std::cout << word << " has " << word.size() << " characters" << std::endl;
    }

}