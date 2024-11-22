#include "MemoryResource.h"
#include "Stack.h"
#include <gtest/gtest.h>
#include <string>

class CustomMemoryResourceTest : public ::testing::Test {
protected:
    CustomMemoryResource memory_resource;
};

TEST_F(CustomMemoryResourceTest, AllocationAndDeallocation) {
    void* p1 = memory_resource.allocate(100);
    ASSERT_NE(p1, nullptr);
    void* p2 = memory_resource.allocate(200);
    ASSERT_NE(p2, nullptr);

    memory_resource.deallocate(p1, 100);
    memory_resource.deallocate(p2, 200);
}

TEST_F(CustomMemoryResourceTest, AllocateBeyondCapacity) {
    ASSERT_THROW(memory_resource.allocate(1024 * 1024 + 1), std::bad_alloc);
}

class CustomStackIntTest : public ::testing::Test {
protected:
    CustomMemoryResource memory_resource;
    CustomStack<int> stack;

    CustomStackIntTest()
        : stack(&memory_resource) {}
};

TEST_F(CustomStackIntTest, PushAndTop) {
    stack.push(402);
    stack.push(21);
    ASSERT_EQ(stack.top(), 21);

    stack.pop();
    ASSERT_EQ(stack.top(), 402);
}

TEST_F(CustomStackIntTest, PopAndEmpty) {
    stack.push(2346353);
    stack.pop();
    ASSERT_TRUE(stack.empty());
}

TEST_F(CustomStackIntTest, Iterator) {
    stack.push(1);
    stack.push(2);
    stack.push(3);

    auto it = stack.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(*it, 3);
}

class CustomStackComplexTypeTest : public ::testing::Test {
protected:
    CustomMemoryResource memory_resource;
    CustomStack<ComplexType> stack;

    CustomStackComplexTypeTest()
        : stack(&memory_resource) {}
};

TEST_F(CustomStackComplexTypeTest, PushAndTop) {
    ComplexType c1{1, "ahahahaha"};
    ComplexType c2{2, "iammad"};

    stack.push(c1);
    stack.push(c2);
    ASSERT_EQ(stack.top().a, 2);
    ASSERT_EQ(stack.top().b, "iammad");

    stack.pop();
    ASSERT_EQ(stack.top().a, 1);
    ASSERT_EQ(stack.top().b, "ahahahaha");
}

TEST_F(CustomStackComplexTypeTest, Iterator) {
    ComplexType c1{1, "please"};
    ComplexType c2{2, "end"};
    ComplexType c3{3, "this"};

    stack.push(c1);
    stack.push(c2);
    stack.push(c3);

    auto it = stack.begin();
    ASSERT_EQ(it->a, 1);
    ASSERT_EQ(it->b, "please");
    ++it;
    ASSERT_EQ(it->a, 2);
    ASSERT_EQ(it->b, "end");
    ++it;
    ASSERT_EQ(it->a, 3);
    ASSERT_EQ(it->b, "this");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
