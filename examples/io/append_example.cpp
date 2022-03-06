#include <fstream>

int main() {

    std::ofstream of("test.txt");
    of << "this is a first line" << std::endl;

    of.close();

    std::ofstream of2("test.txt", std::ios::app);
    of2 << "this is a second line" << std::endl;

}