#include "rectangle.h"

Rectangle::Rectangle() : width(1.0), height(1.0) {}

Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

Rectangle::Rectangle(const Rectangle& other) 
    : width(other.width), height(other.height) {}

Rectangle::Rectangle(Rectangle&& other) noexcept 
    : width(other.width), height(other.height) {
    other.width = 0;
    other.height = 0;
}


Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
    }
    return *this;
}

std::vector<std::pair<double, double>> Rectangle::vertices() const {
    return {
        {0, 0},
        {width, 0},
        {width, height},
        {0, height}
    };
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        width = other.width;
        height = other.height;
        other.width = 0;
        other.height = 0;
    }
    return *this;
}

Rectangle::operator double() const {
    return width * height;
}

std::pair<double, double> Rectangle::center() const {
    return { width / 2.0, height / 2.0 };
}


Figure& Rectangle::operator=(const Figure& other) {
    const Rectangle* ptr = dynamic_cast<const Rectangle*>(&other);
    if (ptr) {
        *this = *ptr;
    }
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* ptr = dynamic_cast<const Rectangle*>(&other);
    if (ptr) {
        return width == ptr->width && height == ptr->height;
    }
    return false;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle width: " << width << ", height: " << height << "\nVertices: ";
    for (const auto& vertex : vertices()) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << std::endl;
}

void Rectangle::read(std::istream &is) {
    std::cout << "Enter width and height of the rectangle:\n";
    is >> width >> height;
}