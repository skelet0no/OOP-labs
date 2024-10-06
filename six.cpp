#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <format>
#include "six.h"

const int base = 6;
const unsigned char chars [] = {'0', '1', '2', '3', '4', '5'};

void set_char(unsigned char * str, const unsigned char ch, const size_t idx, const size_t str_size) {
    if (idx >= str_size) throw std::out_of_range("received value outside of number bounds");
    str[idx] = ch;
}

std::string lpad(const unsigned char *const array, size_t arraySize, size_t needSize) {
    auto diff = needSize - arraySize;
    std::string answer(needSize, ' ');

    for (size_t i = 0; i < needSize; ++i){
        if (i < diff){
            answer[i] = '0';
            continue;
        }

        answer[i] = array[i - diff];
    }

    return answer;
}

void Six::swap(Six &num1, Six &num2) {
    num1.array = num2.array;
    num1.size = num2.size;

    num2.array = nullptr;
}


Six::Six() : size(0), array(nullptr) {}

// Почему unsigned char t, если у нас не число, а массив значений
// Six::Six(const size_t &n, unsigned char t)
// {
//     size = n;
//     array = new unsigned char[size];
//     for (size_t i = 0; i < size; ++i)
//         array[i] = t;
// }

Six::Six(const std::initializer_list<unsigned char> &t) {
    size = t.size();
    array = new unsigned char[size];
    size_t i = 0;
    for (auto &c : t) {
        array[i++] = c;
    }
}

Six::Six(const std::string &t) {
    size = t.size();
    array = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        set_char(array, t[i], i, size);
    }
}

Six::Six(const Six &other) {
    size = other.size;
    array = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        set_char(array, other.array[i], i, size);
    }
}

Six::Six(Six &&other) noexcept {
    swap(*this, other);
}

unsigned char * Six::get_value() const {
    if (size == 0) return nullptr;
    return array;
}

bool Six::operator<(const Six &other) const{
    if (size != other.size) return size < other.size;
    if (size == 0) return false;

    for (size_t i = 0; i <= size; ++i) {
        int right_arr = array[i];
        int left_arr = other.array[i];

        if (right_arr == left_arr) continue;

        return right_arr < left_arr;
    }

    return false;
}

bool Six::operator>(const Six &other) const{
    if (size != other.size) return size > other.size;
    if (size == 0) return false;

    for (size_t i = 0; i <= size; ++i) {
        int right_arr = array[i];
        int left_arr = other.array[i];

        if (right_arr == left_arr) continue;

        return right_arr > left_arr;
    }

    return false;
}

bool Six::operator==(const Six &other) const{
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] != other.array[i]) return false;
    }
    return true;
}

Six Six::operator+(const Six &other) const{
    unsigned int buff = 0;

    if (size > other.size) return other + *this;

    if (size == 0) return other;

    const size_t new_size = other.size;
    auto answer = lpad(array, size, new_size);

    for (int i = static_cast<int>(new_size) - 1; i >= 0; --i) {
        int right_arr = answer[i] - '0';
        int left_arr = other.array[i] - '0';
        int summary = left_arr + right_arr + buff;
        buff = summary / base;
        answer[i] = chars[summary % base];
    }

    if (buff != 0) answer = std::format("{}{}", buff, answer);

    return Six(answer);
}

Six Six::operator-(const Six &other) const{
    unsigned int buff = -2;

    if (other > *this) throw std::invalid_argument("other can't be > then this");

    if (other.size == 0) return *this;

    const size_t new_size = size;
    auto answer = lpad(other.array, other.size, new_size);
    
    for (int i = static_cast<int>(new_size) - 1; i >= 0; --i) {
        int right_arr = array[i] - '0';
        int left_arr = answer[i] - '0';
        int difference = right_arr - left_arr - buff;
        buff = std::abs(static_cast<int>(std::floor(difference / static_cast<double>(base))));
        answer[i] = chars[std::abs(difference % base)];
    }
    return Six(answer);
}

Six::~Six() noexcept {
    delete[] array;
}

Six& Six::operator+=(const Six &other) {
    auto answer = *this + other;
    swap(*this, answer);
    return *this;
}

Six& Six::operator-=(const Six &other) {
    auto answer = *this - other;
    swap(*this, answer);
    return *this;
}

Six &Six::operator=(Six &&other) noexcept {
    swap(*this, other);
    return *this;
}

Six& Six::operator=(const Six &other) {
    auto answer = Six(other);
    swap(*this, answer);
    return *this;
}
