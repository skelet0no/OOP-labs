#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include "point.h"

template<typename T>
class Figure {
public:
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    virtual std::vector<Point<T>> vertices() const = 0;
    virtual double area() const = 0;
    virtual Point<T> center() const = 0;
    virtual ~Figure() = default;

    operator double() const {
        return area();
    }

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.read(is);
        return is;
    }

    virtual Figure& operator=(const Figure& other) {
        if (this != &other) {
        }
        return *this;
    }

    virtual bool operator==(const Figure& other) const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

#endif