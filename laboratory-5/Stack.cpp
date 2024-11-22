#include "Stack.h"

template<typename T>
CustomStack<T>::CustomStack(Allocator alloc): stack(alloc) {}

template<typename T>
void CustomStack<T>::push(const T& value) {
    stack.push_back(value);
}

template<typename T>
void CustomStack<T>::pop() {
    stack.pop_back();
}

template<typename T>
T& CustomStack<T>::top() {
    return stack.back();
}

template<typename T>
const T& CustomStack<T>::top() const {
    return stack.back();
}

template<typename T>
bool CustomStack<T>::empty() const {
    return stack.empty();
}

template<typename T>
std::size_t CustomStack<T>::size() const {
    return stack.size();
}

template<typename T>
typename CustomStack<T>::Iterator CustomStack<T>::begin() {
    return Iterator(stack.data());
}

template<typename T>
typename CustomStack<T>::Iterator CustomStack<T>::end() {
    return Iterator(stack.data() + stack.size());
}

template<typename T>
CustomStack<T>::Iterator::Iterator(pointer ptr): m_ptr(ptr) {}

template<typename T>
typename CustomStack<T>::Iterator::reference CustomStack<T>::Iterator::operator*() const {
    return *m_ptr;
}

template<typename T>
typename CustomStack<T>::Iterator::pointer CustomStack<T>::Iterator::operator->() {
    return m_ptr;
}

template<typename T>
typename CustomStack<T>::Iterator& CustomStack<T>::Iterator::operator++() {
    ++m_ptr;
    return *this;
}

template<typename T>
typename CustomStack<T>::Iterator CustomStack<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++m_ptr;
    return temp;
}

template<typename T>
bool CustomStack<T>::Iterator::operator==(const Iterator& other) const {
    return m_ptr == other.m_ptr;
}

template<typename T>
bool CustomStack<T>::Iterator::operator!=(const Iterator& other) const {
    return m_ptr != other.m_ptr;
}

template class CustomStack<int>;
template class CustomStack<ComplexType>;
