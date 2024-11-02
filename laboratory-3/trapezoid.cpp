#include "trapezoid.h"

Trapeze::Trapeze() : base1(1.0), base2(1.0), height(1.0) {}

Trapeze::Trapeze(double base1, double base2, double height) 
    : base1(base1), base2(base2), height(height) {}

Trapeze::Trapeze(const Trapeze& other) 
    : base1(other.base1), base2(other.base2), height(other.height) {}

Trapeze::Trapeze(Trapeze&& other) noexcept 
    : base1(other.base1), base2(other.base2), height(other.height) {
    other.base1 = 0;
    other.base2 = 0;
    other.height = 0;
}
std::vector<std::pair<double, double>> Trapeze::vertices() const {
    std::vector<std::pair<double, double>> verts;
    verts.emplace_back(0.0, 0.0);
    verts.emplace_back(base1, 0.0);
    verts.emplace_back((base1 - base2) / 2.0, height);
    verts.emplace_back((base1 + base2) / 2.0, height);
    return verts;
}

Trapeze& Trapeze::operator=(const Trapeze& other) {
    if (this != &other) {
        base1 = other.base1;
        base2 = other.base2;
        height = other.height;
    }
    return *this;
}

Trapeze& Trapeze::operator=(Trapeze&& other) noexcept {
    if (this != &other) {
        base1 = other.base1;
        base2 = other.base2;
        height = other.height;
        other.base1 = 0;
        other.base2 = 0;
        other.height = 0;
    }
    return *this;
}

Trapeze::operator double() const {
    return ((base1 + base2) / 2) * height;
}

std::pair<double, double> Trapeze::center() const {
    return { (base1 + base2) / 2.0, height / 2.0 };
}


Figure& Trapeze::operator=(const Figure& other) {
    const Trapeze* ptr = dynamic_cast<const Trapeze*>(&other);
    if (ptr) {
        *this = *ptr;
    }
    return *this;
}

bool Trapeze::operator==(const Figure& other) const {
    const Trapeze* ptr = dynamic_cast<const Trapeze*>(&other);
    if (ptr) {
        return base1 == ptr->base1 && base2 == ptr->base2 && height == ptr->height;
    }
    return false;
}

void Trapeze::print(std::ostream &os) const {
    os << "Trapeze bases: " << base1 << ", " << base2 << ", height: " << height << "\nVertices: ";
    for (const auto& vertex : vertices()) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << std::endl;
}

void Trapeze::read(std::istream &is) {
    std::cout << "Enter base1, base2, and height of the trapeze:\n";
    is >> base1 >> base2 >> height;
}