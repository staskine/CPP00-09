#pragma once

# include <iostream>
# include <exception>


template <typename T>
class Array {
private:
    T* myArray;
    unsigned int length;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    unsigned int size() const;
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
};

# include "Array.tpp"