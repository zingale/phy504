#include <iostream>
#include <filesystem>

int main() {

    std::filesystem::path home("/home/zingale");

    auto full_path = home / "hello.cpp";

    std::cout << full_path << std::endl;

}