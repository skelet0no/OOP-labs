#include <gtest/gtest.h>
#include "solve.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(divider(1, 1)==0);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(divider(0, 10)==0);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(divider(7, 3)==20);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
