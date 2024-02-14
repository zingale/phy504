#include <iostream>
#include <string>

int main() {

    std::string filename{"~/classes/test.cpp"};
    std::cout << "filename: " << filename << std::endl;

    // let's find just the base file name -- reverse find for '/'

    auto ipos = filename.rfind('/');

    // create a substring containing just the base name
    // if we don't provide a length, substr goes to the end

    std::string basename = filename.substr(ipos+1);

    std::cout << "basename = " << basename << std::endl;

    // now let's change the extension from .cpp to .txt

    auto ipos_ext = basename.rfind('.');

    // there are many forms of replace -- here's well use iterators
    // that mark the start and end of the original string and those of
    // the string we want to substitute

    std::string new_ext = ".txt";

    basename.replace(basename.begin()+ipos_ext, basename.end(),
                     new_ext.begin(), new_ext.end());

    std::cout << "basename = " << basename << std::endl;

}
