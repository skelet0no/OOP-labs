#include <iostream>
#include <memory>
#include "array.h"
#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"

void inputFigure(Array& arr, int index) {
    int figureType;
    std::cout << "Enter the shape type (1 - Rhombus, 2 - Rectangle, 3 - Trapezoid): ";
    std::cin >> figureType;

    switch (figureType) {
        case 1: {
            Rhombus* rectangle = new Rhombus();
            rectangle->read(std::cin);
            arr.add(index, rectangle);
            break;
        }
        case 2: {
            Rectangle* rectangle = new Rectangle();
            rectangle->read(std::cin);
            arr.add(index, rectangle);
            break;
        }
        case 3: {
            Trapeze* trapeze = new Trapeze();
            trapeze->read(std::cin);
            arr.add(index, trapeze);
            break;
        }
        default:
            std::cout << "Wrong shape type" << std::endl;
            break;
    }
}

int main() {
    Array figures(10);
    int figureCount;

    std::cout << "How many shapes do you want to enter (maximum 10)?";
    std::cin >> figureCount;

    if (figureCount > 10 || figureCount < 1) {
        std::cout << "Incorrect number of shapes" << std::endl;
        return 1;
    }

    for (int i = 0; i < figureCount; i++) {
        inputFigure(figures, i);
    }

    std::cout << "\nShape Information:" << std::endl;
    for (int i = 0; i < figureCount; i++) {
        Figure* fig = figures[i];
        if (fig) {
            std::cout << "Shape " << (i + 1) << ":" << std::endl;
            auto center = fig->center();
            std::cout << "Geometric center: (" << center.first << ", " << center.second << ")" << std::endl;
            std::cout << "Square: " << static_cast<double>(*fig) << std::endl;

            std::cout << "Vertex: ";
            for (const auto& vertex : fig->vertices()) {
                std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            std::cout << std::endl;

            fig->print(std::cout);
            std::cout << std::endl;
        }
    }

    std::cout << "\nTotal area of all figures: " << figures.total_area() << std::endl;

    int indexToDelete;
    std::cout << "Enter the index of the figure to delete (0-" << (figureCount - 1) << "): ";
    std::cin >> indexToDelete;

    if (indexToDelete >= 0 && indexToDelete < figureCount) {
        figures.del_figure(indexToDelete);
    } else {
        std::cout << "Invalid index" << std::endl;
    }

    std::cout << "\nArray after removing the figure:\n";
    for (int i = 0; i < figureCount; i++) {
        Figure* fig = figures[i];
        if (fig) {
            std::cout << "Shape " << (i + 1) << ":" << std::endl;
            auto center = fig->center();
            std::cout << "Geometric center: (" << center.first << ", " << center.second << ")" << std::endl;
            std::cout << "Square: " << static_cast<double>(*fig) << std::endl;

            std::cout << "Vertex: ";
            for (const auto& vertex : fig->vertices()) {
                std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            std::cout << std::endl;

            fig->print(std::cout);
            std::cout << std::endl;
        }
    }

    return 0;
}
