#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <fstream>
#include <memory>
#include <cstring>

class Container {

private:

    // this is a simple container class that
    // just stores a 1-d array buffer

    int _size;
    std::unique_ptr<double []> _data;

public:

    // default constructor

    Container()
        : _size(0), _data(nullptr)
    {std::cout << "in default constructor" << std::endl;}

    // parametric constructor

    Container(int size)
        : _size(size)
    {

        // allocate a 1-d array with size elements
        // this is placed on the heap and managed by
        // a unique pointer

        _data = std::make_unique<double []> (size);

        std::cout << "in parametric constructor" << std::endl;

    }


    // getters

    int get_size() {return _size;}

    // we use the get() function on the unique_ptr to get the pointer to
    // the data that it is managing.

    double* get_data() {return _data.get();}

    // operators

    friend std::ostream& operator<< (std::ostream& os, const Container& c);

};

std::ostream& operator<< (std::ostream& os, const Container& c) {
    for (int i = 0; i < c._size; ++i) {
        os << c._data.get()[i] << " ";
    }
    os << std::endl;
    return os;
}

#endif
