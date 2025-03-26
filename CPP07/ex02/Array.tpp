#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

//When making functions in a class they can be done in a .tpp file but you need to 
//have a template before each function

template <typename T>
Array<T>::Array() : myArray(nullptr), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : length(n) {
    try { 
        myArray = new T[n]();
    } catch (const std::bad_alloc& e) {
        throw std::runtime_error(std::string("New Failed: ") + e.what());
    }
}

template <typename T>
Array<T>::Array(const Array& other) : length(other.length) {
    myArray = new T[length];
    for (unsigned int i = 0; i < length; i++)
        myArray[i] = other.myArray[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
		if (myArray != NULL)
        	delete[] myArray;
        length = other.length;
        try { 
            myArray = new T[length];
        } catch (const std::bad_alloc& e) {
            throw std::runtime_error(std::string("New Failed: ") + e.what());
        }
        for (unsigned int i = 0; i < length; i++)
            myArray[i] = other.myArray[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
	if (myArray != NULL)
    	delete[] myArray;
}

template <typename T>
unsigned int Array<T>::size() const {
    return length;
}

template <typename T>
T& Array<T>::operator[](const unsigned int index) {
    if (index >= length)
        throw std::out_of_range("Index out of bounds");
	else if (myArray == nullptr)
        throw std::runtime_error("myArray is NULL");
    return myArray[index];
}

template <typename T>
const T& Array<T>::operator[](const unsigned int index) const {
    if (index >= length)
        throw std::out_of_range("Index out of bounds");
	else if (myArray == nullptr)
        throw std::runtime_error("myArray is NULL");
    return myArray[index];
}

#endif