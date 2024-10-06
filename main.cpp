#include <iostream>

#include "six.h"

int main(int argc, char **argv){
    std::string num1, num2;

    std::cout << "Enter the first number" << std::endl;
    std::cin >> num1;
    std::cout << "Enter the second number" << std::endl;
    std::cin >> num2;

    auto count1 = ::Six(num1);
    auto count2 = ::Six(num2);
    std::cout<< (count1 + count2).get_value();
}
