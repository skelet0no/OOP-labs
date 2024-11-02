#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <utility>
#include <vector>
class Trapeze : public Figure {
private:
    double base1;
    double base2;
    double height;
public:
    Trapeze();
    Trapeze(double base1, double base2, double height);
    std::vector<std::pair<double, double>> vertices() const override;
    Trapeze(const Trapeze& other);
    Trapeze(Trapeze&& other) noexcept;

    Trapeze& operator=(const Trapeze& other);
    Trapeze& operator=(Trapeze&& other) noexcept;

    explicit operator double() const override;

    std::pair<double, double> center() const override;
    Figure& operator=(const Figure& other) override;
    bool operator==(const Figure& other) const override;

    void print(std::ostream &os) const override;
    void read(std::istream &is) override;
};

#endif
