#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "point.h"
#include "figure.h"
#include <cmath>

template<typename T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T>> _a, _b, _c, _d;
public:
    Trapezoid(Point<T> a = Point<T>(), Point<T> b = Point<T>(), Point<T> c = Point<T>(), Point<T> d = Point<T>())
        : _a(std::make_unique<Point<T>>(a)), _b(std::make_unique<Point<T>>(b)), _c(std::make_unique<Point<T>>(c)), _d(std::make_unique<Point<T>>(d)) {}

    std::vector<Point<T>> vertices() const override {
        return {*_a, *_b, *_c, *_d};
    }

    double area() const override {
        T a_length = std::hypot(_b->x - _a->x, _b->y - _a->y);
        T b_length = std::hypot(_c->x - _d->x, _c->y - _d->y);
        T height = std::abs((_a->x - _d->x) * (_b->y - _a->y) - (_a->x - _b->x) * (_d->y - _a->y)) / a_length;
        return ((a_length + b_length) / 2) * height;
    }

    Point<T> center() const override {
        T x_center = (_a->x + _b->x + _c->x + _d->x) / 4;
        T y_center = (_a->y + _b->y + _c->y + _d->y) / 4;
        return Point<T>(x_center, y_center);
    }

    void print(std::ostream& os) const override {
        os << "Trapezoid: A = " << *_a << ", B = " << *_b << ", C = " << *_c << ", D = " << *_d;
    }

    void read(std::istream& is) override {
        is >> *_a >> *_b >> *_c >> *_d;
    }

    Trapezoid& operator=(const Trapezoid& other) {
        if (this != &other) {
            _a = std::make_unique<Point<T>>(*other._a);
            _b = std::make_unique<Point<T>>(*other._b);
            _c = std::make_unique<Point<T>>(*other._c);
            _d = std::make_unique<Point<T>>(*other._d);
        }
        return *this;
    }

    bool operator==(const Figure<T>& other) const override {
        const Trapezoid<T>* trapezoid = dynamic_cast<const Trapezoid<T>*>(&other);
        return trapezoid && *_a == *trapezoid->_a && *_b == *trapezoid->_b &&
               *_c == *trapezoid->_c && *_d == *trapezoid->_d;
    }
};


#endif
