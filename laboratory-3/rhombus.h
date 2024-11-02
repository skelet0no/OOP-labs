#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <utility>
#include <vector>

class Rhombus : public Figure {
private:
    double side;
    double height;
public:
    Rhombus();
    Rhombus(double side, double height);
    std::vector<std::pair<double, double>> vertices() const override;
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;

    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;

    explicit operator double() const override;

    std::pair<double, double> center() const override;
    Figure& operator=(const Figure& other) override;
    bool operator==(const Figure& other) const override;

    void print(std::ostream &os) const override;
    void read(std::istream &is) override;
};

#endif
