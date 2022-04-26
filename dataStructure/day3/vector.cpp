#include <iostream>
#include <stdexcept>
#include "vector.h"

Vector::Vector() {
    _arr = new int[_capacity];
    _capacity = 32;
    _size = 0;
}
Vector::~Vector() {
    RemoveAll();
}

void Vector::IncreaseSize() {
    if (_size == _capacity) {
        _capacity = _capacity * 2;
        int *temp = _arr;
        _arr = new int[_capacity];
        for (int i = 0; i < _size; ++i) {
            _arr[i] = temp[i];
        }
        delete temp;
    }
}

void Vector::AddFront(int value) {
    AddAt(0, value);
}

void Vector:: Add(int value) {
    IncreaseSize();
    _arr[++_size] = value;
}

void Vector::AddAt(int index, int value) {
    IncreaseSize();
    int temp = 0;
    int temp1 = 0;
    if (_size < _capacity) {
        for (int i = _size; i > index; --i) {
            _arr[i] = _arr[i - 1];
        }
        _arr[index] = value;
        ++_size;
    }
}

void Vector::RemoveAt(int index) {
    for (int i = index; i < _size; ++i) {
         _arr[i] = _arr[i + 1];
    }
    --_size;
}

void Vector::RemoveAll() {
    int size = _size;
    for (int i = 0; i < size; ++i) {
        RemoveAt(_size);
    }
}

ostream &operator << (ostream& out, const Vector& vector) {
    for (int i = 0; i < vector._size; ++i) {
        out << vector._arr[i] << " ";
    }
    out << endl;
    return out;
}

int& Vector::operator[](int index) {
    if (index < 0 || index >= _size) {
        if (_size == 0) {
            throw std::invalid_argument("Error: vector is empty!(operator [])");
        }
        throw std::invalid_argument("Error: out of bounds exception!(operator [])");
    }
    return _arr[index];
}