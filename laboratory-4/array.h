#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <memory>

template<typename T>
class Array {
private:
    size_t _size;
    size_t _capacity;
    std::shared_ptr<T>* _data;
public:
    Array(size_t size = 0) : _size(size), _capacity(size), _data(new std::shared_ptr<T>[size]) {}

    Array(const Array& other) : _size(other._size), _capacity(other._capacity), _data(new std::shared_ptr<T>[other._capacity]) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    Array(Array&& other) noexcept : _size(other._size), _capacity(other._capacity), _data(other._data) {
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = new std::shared_ptr<T>[other._capacity];
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = other._data;
            other._size = 0;
            other._capacity = 0;
            other._data = nullptr;
        }
        return *this;
    }

    ~Array() {
        delete[] _data;
    }

    void push_back(const std::shared_ptr<T>& value) {
        if (_size >= _capacity) {
            resize(_capacity == 0 ? 1 : _capacity * 2);
        }
        _data[_size++] = value;
    }

    const std::shared_ptr<T>& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    std::shared_ptr<T>& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    size_t size() const {
        return _size;
    }

    void resize(size_t new_capacity) {
        if (new_capacity > _capacity) {
            std::shared_ptr<T>* new_data = new std::shared_ptr<T>[new_capacity];
            for (size_t i = 0; i < _size; ++i) {
                new_data[i] = std::move(_data[i]);
            }
            delete[] _data;
            _data = new_data;
            _capacity = new_capacity;
        }
    }

    void remove(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < _size - 1; ++i) {
            _data[i] = std::move(_data[i + 1]);
        }
        --_size;
    }

    double totalArea() const {
        double total = 0;
        for (size_t i = 0; i < _size; ++i) {
            total += _data[i]->area();
        }
        return total;
    }
};

#endif
