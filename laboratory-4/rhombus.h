#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "point.h"
#include "figure.h"
#include <cmath>

template<typename T>
class Rhombus : public Figure<T> {
private:
    std::unique_ptr<Point<T>> _bottom_left;
    T _side;
    T _height;
public:
    Rhombus(Point<T> bottom_left = Point<T>(), T side = T(), T height = T())
        : _bottom_left(std::make_unique<Point<T>>(bottom_left)), _side(side), _height(height) {}

    std::vector<Point<T>> vertices() const override {
        T section = std::sqrt(_side * _side - _height * _height);
        return {
            *_bottom_left,
            Point<T>(_bottom_left->x + _side, _bottom_left->y),
            Point<T>(_bottom_left->x + _side + section, _bottom_left->y + _height),
            Point<T>(_bottom_left->x + section, _bottom_left->y + _height)
        };
    }

    double area() const override {
        return _side * _height;
    }

    Point<T> center() const override {
        T section = std::sqrt(_side * _side - _height * _height);
        return Point<T>(_bottom_left->x + (_side + section) / 2, _bottom_left->y + _height / 2);
    }

    void print(std::ostream& os) const override {
        os << "Rhombus: Bottom Left = " << *_bottom_left << ", Side = " << _side << ", Height = " << _height;
    }

    void read(std::istream& is) override {
        is >> *_bottom_left >> _side >> _height;
    }

    Rhombus& operator=(const Rhombus& other) {
        if (this != &other) {
            _bottom_left = std::make_unique<Point<T>>(*other._bottom_left);
            _side = other._side;
            _height = other._height;
        }
        return *this;
    }

    bool operator==(const Figure<T>& other) const override {
        const Rhombus<T>* rhombus = dynamic_cast<const Rhombus<T>*>(&other);
        return rhombus && *_bottom_left == *rhombus->_bottom_left &&
               _side == rhombus->_side && _height == rhombus->_height;
    }
};

#endif
