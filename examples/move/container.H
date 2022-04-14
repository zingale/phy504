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

    // parameteric constructor

    Container(int size)
        : _size(size)
    {
        
        // allocate a 1-d array with size elements
        // this is placed on the heap and managed by
        // a unique pointer

        _data = std::make_unique<double []> (size);

        std::cout << "in parametric constructor" << std::endl;

    }

    // destructor -- since we are using a unique ptr to
    // manage our data, there is nothing to do

    ~Container() {std::cout << "in destructor" << std::endl;}

    // copy constructor

    Container(const Container& c) {

        std::cout << "in copy constructor" << std::endl;

        _size = c._size;

        // reset the data buffer

        _data = std::make_unique<double []> (_size);

        // copy the data over from c to this
        // this has the form: destination, source, number of bytes
        std::memcpy(_data.get(), c._data.get(),
                    _size * sizeof(double));

    }

    // assignment operator

    Container& operator= (const Container& c) {

        std::cout << "in assignment operator" << std::endl;

        // make sure we are not assigning ourselves

        if (this != &c) {

            _size = c._size;

            _data = std::make_unique<double []> (_size);

            // copy the data over from c to this
            // this has the form: destination, source, number of bytes
            std::memcpy(_data.get(), c._data.get(),
                        _size * sizeof(double));

        }

        return *this;
    }

    // move constructor

    Container(Container&& c) noexcept
        : _size(0), _data(nullptr)
    {
        std::cout << "in move constructor" << std::endl;

        std::swap(_size, c._size);

        // swap the data pointers

        _data.swap(c._data);
    }

    // move assignment

    Container& operator= (Container&& c) noexcept {

        std::cout << "in move assignment" << std::endl;
        
        std::swap(_size, c._size);

        // swap the data pointers

        _data.swap(c._data);

        return *this;
    }

    // getters

    int get_size() {return _size;}

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