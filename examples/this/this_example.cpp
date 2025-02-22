#include <iostream>

class Example {

private:

    std::string data;

    // simple constructor

public:

    Example(const std::string& input_string) : data{input_string} {};

    // getter

    std::string get_data() {return data;}

    // function that returns a reference -- just for demonstration

    Example& get_ref() {return *this;}

};

int main() {

    Example test("this is my test string");

    Example& new_class = test.get_ref();

    std::cout << new_class.get_data() << std::endl;
}
