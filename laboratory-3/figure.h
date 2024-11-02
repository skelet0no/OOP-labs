#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>
#include <vector>

class Figure {
public:
    virtual operator double() const = 0;
    virtual std::pair<double, double> center() const = 0;
    virtual ~Figure() = default;
    virtual std::vector<std::pair<double, double>> vertices() const = 0;
    virtual Figure& operator=(const Figure& other){
        return *this;
    };
    virtual bool operator==(const Figure& other) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.read(is);
        return is;
    }
    virtual void print(std::ostream &os) const = 0;
    virtual void read(std::istream &is) = 0;
};

#endif
