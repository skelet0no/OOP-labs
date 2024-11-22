#ifndef STACK_H
#define STACK_H

#include "MemoryResource.h"
#include <memory_resource>
#include <vector>
#include <string>

struct ComplexType {
    int a;
    std::string b;
};

template<typename T>
class CustomStack {
public:
    using Allocator = std::pmr::polymorphic_allocator<T>;

    CustomStack(Allocator alloc = {});
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;
    std::size_t size() const;

    class Iterator;

    Iterator begin();
    Iterator end();

private:
    std::pmr::vector<T> stack;
};

template<typename T>
class CustomStack<T>::Iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Iterator(pointer ptr);

    reference operator*() const;
    pointer operator->();
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;

private:
    pointer m_ptr;
};

#endif //STACK_H
