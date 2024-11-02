#include <gtest/gtest.h>
#include "array.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"

TEST(ArrayTest, DefaultConstructor) {
    Array arr;
    EXPECT_EQ(arr.total_area(), 0.0);
}

TEST(ArrayTest, DeleteFigure) {
    Array arr;
    Rectangle* rect = new Rectangle(5.0, 3.0);
    arr.add(0, rect);
    arr.del_figure(0);
    EXPECT_EQ(arr.total_area(), 0.0);
}

TEST(RectangleTest, ParameterizedConstructor) {
    Rectangle rect(5.0, 3.0);
    EXPECT_EQ(rect.operator double(), 15.0);
}

TEST(TrapezeTest, DefaultConstructor) {
    Trapeze trap;
    EXPECT_EQ(trap.operator double(), 1.0);
}

TEST(RectangleTest, Vertices) {
    Rectangle rect(4.0, 2.0);
    auto vertices = rect.vertices();
    EXPECT_EQ(vertices.size(), 4);

    EXPECT_DOUBLE_EQ(vertices[0].first, 0.0);
    EXPECT_DOUBLE_EQ(vertices[0].second, 0.0);

    EXPECT_DOUBLE_EQ(vertices[1].first, 4.0);
    EXPECT_DOUBLE_EQ(vertices[1].second, 0.0);

    EXPECT_DOUBLE_EQ(vertices[2].first, 4.0);
    EXPECT_DOUBLE_EQ(vertices[2].second, 2.0);

    EXPECT_DOUBLE_EQ(vertices[3].first, 0.0);
    EXPECT_DOUBLE_EQ(vertices[3].second, 2.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}