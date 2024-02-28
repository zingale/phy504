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

    bool was_space = false;

    while (std::getline(input_file, line)) {

        // by design, getline drops the newline, so add it back here
	// so we can accurate capture line breaks and get the words right
	line += "\n";

        for (auto c : line) {
            bool test = (c == ' ' || c == '\n');
            if (test) {
		// if the previous character was a space too, then
		// just skip, otherwise, increment the word counter
		// and set it as a space
		if (!was_space) {
		    word_count += 1;
		    was_space = true;
		}
            } else {
		was_space = false;
	    }

            char_count += 1;
        }

        line_count += 1;

    }

    std::cout << "number of lines = " << line_count << std::endl;
    std::cout << "number of words = " << word_count << std::endl;
    std::cout << "number of characters = " << char_count << std::endl;

}
