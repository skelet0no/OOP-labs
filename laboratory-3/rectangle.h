#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <utility>
#include <iostream>
#include <vector>

class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle();
    Rectangle(double width, double height);
    std::vector<std::pair<double, double>> vertices() const override;
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;

    explicit operator double() const override;

    std::pair<double, double> center() const override;
    Figure& operator=(const Figure& other) override;
    bool operator==(const Figure& other) const override;

    void print(std::ostream &os) const override;
    void read(std::istream &is) override;
};

#endif
