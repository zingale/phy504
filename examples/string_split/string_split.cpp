#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <string_view>

int main() {

    using std::operator""sv;

    std::string s{"May the force be with you"};

    // note that the deliminator needs to be a string_view
    // so it doesn't contain the null ("\0")

    // also note that split returns a range of ranges

    for (auto w : std::views::split(s, " "sv)) {
        std::cout << std::string_view(w) << std::endl;
    }

    for (auto w : std::views::split(s, " "sv) |
                  std::views::transform([] (auto rng) {return std::string_view(rng);})) {
        std::cout << w << std::endl;
    }
}
