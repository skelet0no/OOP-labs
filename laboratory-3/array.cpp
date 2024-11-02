#include "array.h"
#include <stdexcept>

Array::Array() {
    _size = 5;
    _figures = new Figure*[_size];
    for (int i = 0; i < _size; i++) {
        _figures[i] = nullptr;
    }
}

Array::Array(int size) {
    if (size <= 0) {
        throw std::invalid_argument("The array size must be positive");
    }
    _size = size;
    _figures = new Figure*[_size];
    for (int i = 0; i < _size; i++) {
        _figures[i] = nullptr;
    }
}

Array::~Array() {
    for (int i = 0; i < _size; i++) {
        delete _figures[i];
    }
    delete[] _figures;
}

void Array::del_figure(int i) {
    if (i < 0 || i >= _size)
        throw std::invalid_argument("There is no such index in the array");
    delete _figures[i];
    _figures[i] = nullptr;
}

void Array::add(int i, Figure* figure) {
    if (i < 0 || i >= _size)
        throw std::invalid_argument("There is no such index in the array");
    delete _figures[i];
    _figures[i] = figure;
}

double Array::total_area() {
    double res = 0.0;
    for (int i = 0; i < _size; i++) {
        if (_figures[i] != nullptr)
            res += (double)*_figures[i];
    }
    return res;
}

Figure* Array::operator[](int i) const {
    if (i < 0 || i >= _size)
        throw std::invalid_argument("There is no such index in the array");
    return _figures[i];
}