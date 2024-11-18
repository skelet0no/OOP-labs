#include <iostream>
#include <memory>
#include "array.h"
#include "figure.h"
#include "point.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"

std::shared_ptr<Figure<double>> createFigure() {
    std::string type;
    std::cout << "Enter the shape type (rectangle, rhombus, trapezoid): ";
    std::cin >> type;

    if (type == "rectangle") {
        double width, height;
        std::cout << "Enter the width and height of the rectangle: ";
        std::cin >> width >> height;
        return std::make_shared<Rectangle<double>>(width, height);
    } else if (type == "rhombus") {
        double side, height;
        std::cout << "Enter the side and height of the rhombus: ";
        std::cin >> side >> height;
        return std::make_shared<Rhombus<double>>(side);
    } else if (type == "trapezoid") {
        double a, b, height;
        std::cout << "Enter base A, base B and the height of the trapezoid: ";
        std::cin >> a >> b >> height;
        return std::make_shared<Trapezoid<double>>(a, b, height);
    } else {
        std::cerr << "Unknown shape type" << std::endl;
        return nullptr;
    }
}

int main() {
    Array<Figure<double>> figures;

    char more;
    do {
        auto figure = createFigure();
        if (figure) {
            figures.push_back(figure);
            std::cout << "A shape has been added. The current size of the array: " << figures.size() << std::endl;
        }
        std::cout << "Add another shape? (y/n): ";
        std::cin >> more;
    } while (more == 'y');

    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":" << std::endl;
        std::cout << "Square: " << figures[i]->area() << std::endl;

        Point<double> center = figures[i]->center();
        std::cout << "Geometric center: (" << center.getX() << ", " << center.getY() << ")" << std::endl;
        figures[i]->print(std::cout);
    }

    double totalArea = figures.totalArea();
    std::cout << "The total area of the figures: " << totalArea << std::endl;

    size_t indexToRemove;
    std::cout << "Enter the index of the shape to delete (0-" << figures.size() - 1 << "): ";
    std::cin >> indexToRemove;

    if (indexToRemove < figures.size()) {
        figures.remove(indexToRemove);
        std::cout << "Figure " << indexToRemove + 1 << " removed." << std::endl;
    } else {
        std::cerr << "Invalid index" << std::endl;
    }

    return 0;
}
