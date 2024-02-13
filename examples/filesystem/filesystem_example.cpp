#include <iostream>
#include <filesystem>

int main() {

    std::filesystem::path source{"./filesystem_example.cpp"};

    std::cout << source << std::endl;

    std::cout << std::filesystem::exists(source) << std::endl;

    std::cout << source.filename() << std::endl;
    std::cout << source.stem() << std::endl;
    std::cout << source.extension() << std::endl;

    std::cout << std::filesystem::current_path() << std::endl;
    std::cout << std::filesystem::absolute(source) << std::endl;
    std::cout << std::filesystem::canonical(source) << std::endl;
    std::cout << source.root_path() << std::endl;
}