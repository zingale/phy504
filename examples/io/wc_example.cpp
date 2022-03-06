#include <iostream>
#include <fstream>

int main() {

    // open the file

    std::ifstream input_file("lorem-ipsum.txt");

    if (! input_file.is_open()) {
        std::cout << "Error: invalid file" << std::endl;
        return 1;
    }

    // loop over line by line
    std::string line{};

    unsigned int line_count{0};
    unsigned int char_count{0};
    unsigned int word_count{0};

    bool was_space = true;

    while (std::getline(input_file, line)) {

        for (auto c : line) {
            bool test = c == ' ';
            if (test and !was_space) {
                was_space = true;
            } else if (test) {
                was_space = true;
            } else if (was_space) {
                word_count += 1;
            }

            char_count += 1;
        }

        // by design, getline drops the newline, so we need to add 1 to the char
        // count if we care about the newline character
        char_count +=1;

        line_count += 1;

    }

    std::cout << "number of lines = " << line_count << std::endl;
    std::cout << "number of words = " << word_count << std::endl;
    std::cout << "number of characters = " << char_count << std::endl;

}