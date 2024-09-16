#include <iostream>
#include "solve.h"

int main(int, char**){
    int n, m;
    std::cout << "Enter the length and width of the chocolate: ";
    std::cin >> n >> m;
    std::cout << "\nNumber of partitions = " << divider(n, m) << std::endl;

    return 0;
}