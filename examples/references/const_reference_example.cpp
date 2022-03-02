#include <iostream>

int main() {

    int i{2};
    const int& i_ref = i;

    std::cout << i << " " << i_ref << std::endl;

    i++;

    std::cout << i << " " << i_ref << std::endl;

    //i_ref++;

    std::cout << i << " " << i_ref << std::endl;




}