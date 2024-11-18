#include <gtest/gtest.h>
#include "point.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"

TEST(RectangleTest, Area) {
    Rectangle<double> rectangle(Point<double>(0, 0), 7.0, 2.0);
    EXPECT_DOUBLE_EQ(rectangle.area(), 14.0);
}

TEST(RhombusTest, Area) {
    Rhombus<double> rhombus(Point<double>(0, 0), 4.0, 3.0);
    EXPECT_DOUBLE_EQ(rhombus.area(), 12.0);
}

TEST(TrapezoidTest, Area) {
    Trapezoid<double> trapezoid(Point<double>(0, 0), Point<double>(6, 0), Point<double>(4, 3), Point<double>(2, 3));
    EXPECT_DOUBLE_EQ(trapezoid.area(), 12.0);
}

TEST(RectangleTest, Coordinates) {
    Rectangle<double> rect(Point<double>(1, 1), 3.0, 2.0);

    std::vector<Point<double>> vertices = rect.vertices();
    EXPECT_EQ(vertices[0], Point<double>(1, 1));
    EXPECT_EQ(vertices[1], Point<double>(4, 1));
    EXPECT_EQ(vertices[2], Point<double>(4, 3));
    EXPECT_EQ(vertices[3], Point<double>(1, 3));
}

TEST(TrapezoidTest, Center) {
    Trapezoid<double> trapezoid(Point<double>(0, 0), Point<double>(6, 0), Point<double>(4, 3), Point<double>(2, 3));
    Point<double> center = trapezoid.center();
    EXPECT_DOUBLE_EQ(center.x, 3.0);
    EXPECT_DOUBLE_EQ(center.y, 1.5);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
