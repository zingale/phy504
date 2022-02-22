#include <iostream>
#include <string>

int main() {

    std::string example{"This is PHY 504"};

    example += ":\n Computational Methods in Physics and Astrophysics I\n";
    example += "Spring 2022";

    std::cout << example << std::endl;
}