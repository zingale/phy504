#include <iostream>
#include <optional>

std::optional<std::string> valid(const std::string& a_in) {

    if (a_in.size() < 2) {
        return std::nullopt;
    } else {
        return a_in;
    }
}

int main() {

    auto a = valid("test");
    std::cout << a.value_or("") << std::endl;

    auto b = valid("a");
    std::cout << b.value_or("") << std::endl;

}
