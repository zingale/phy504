#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {

    std::vector<std::string> words;

    words.push_back("This");
    words.push_back("is");
    words.push_back("a");
    words.push_back("test");

    std::string empty{""};
    auto sentence = std::accumulate(words.cbegin(), words.cend(), empty);

    std::cout << sentence << std::endl;

}