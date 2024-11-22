#include "Stack.h"
#include <iostream>

int main() {
    CustomMemoryResource memory_resource;
    CustomStack<int> int_stack(&memory_resource);

    int_stack.push(10);
    int_stack.push(20);
    std::cout << "Top element: " << int_stack.top() << "\n";

    for (auto it = int_stack.begin(); it != int_stack.end(); ++it) {
        std::cout << "Element: " << *it << "\n";
    }

    CustomStack<ComplexType> complex_stack(&memory_resource);
    complex_stack.push({1, "test"});
    complex_stack.push({2, "example"});
    std::cout << "Top element: " << complex_stack.top().a << ", " << complex_stack.top().b << "\n";

    for (auto it = complex_stack.begin(); it != complex_stack.end(); ++it) {
        std::cout << "Element: " << it->a << ", " << it->b << "\n";
    }

    return 0;
}
