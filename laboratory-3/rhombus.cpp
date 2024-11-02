#include "rhombus.h"
#include <cmath>

Rhombus::Rhombus() : side(1.0), height(1.0) {}

Rhombus::Rhombus(double side, double height) : side(side), height(height) {}

Rhombus::Rhombus(const Rhombus& other)
    : side(other.side), height(other.height) {}

Rhombus::Rhombus(Rhombus&& other) noexcept
    : side(other.side), height(other.height) {
    other.side = 0;
    other.height = 0;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        side = other.side;
        height = other.height;
    }
    return *this;
}

std::vector<std::pair<double, double>> Rhombus::vertices() const {
    double section = std::sqrt(std::pow(side, 2) - std::pow(height, 2));
    return {
        {0, 0},
        {side, 0},
        {side + section, height},
        {section, height}
    };
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        side = other.side;
        height = other.height;
        other.side = 0;
        other.height = 0;
    }
    return *this;
}

Rhombus::operator double() const {
    return side * height;
}

std::pair<double, double> Rhombus::center() const {
    double section = std::sqrt(std::pow(side, 2) - std::pow(height, 2));
    return { (side + section) / 2.0, height / 2.0 };
}

Figure& Rhombus::operator=(const Figure& other) {
    const Rhombus* ptr = dynamic_cast<const Rhombus*>(&other);
    if (ptr) {
        *this = *ptr;
    }
    return *this;
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* ptr = dynamic_cast<const Rhombus*>(&other);
    if (ptr) {
        return side == ptr->side && height == ptr->height;
    }
    return false;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus side: " << side << ", height: " << height << "\nVertices: ";
    for (const auto& vertex : vertices()) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << std::endl;
}

void Rhombus::read(std::istream &is) {
    std::cout << "Enter side and height of the rhombus:\n";
    is >> side >> height;
}
