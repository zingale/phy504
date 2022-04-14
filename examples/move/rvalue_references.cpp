#include <iostream>
#include <string>

int main() {

    // this is an rvalue reference -- it can appear on the right

    std::string&& rr("test");

    // this calls the copy constructor of string

    std::string snew(rr);

    std::cout << snew << " " << rr << std::endl;

    // this calls the move constructor of string

    std::string s_steal(std::move(rr));

    std::cout << s_steal << " " << rr << std::endl;

}