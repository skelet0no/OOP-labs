#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <type_traits>

template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

template<Scalar T>
class Point {
public:
    T x;
    T y;

    Point(T x = T(), T y = T()) : x(x), y(y) {}
    T getX() const { return x; }
    T getY() const { return y; }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

#endif // POINT_H
