#include <gtest/gtest.h>
#include "six.h"
#include <iostream>

bool convertAnswer(const std::string& initial, const unsigned char * const answer) {
    auto j = 0;
    while (answer[j] != '\0') {
        j++;
    }
    auto answerSize = j;

    if (initial.length() != answerSize) return false;

    for (size_t i = 0; i < answerSize; ++i) {
        if (initial[i] != answer[i]) return false;
    }

    return true;
}

TEST(test_01, string) {
    auto initial = "51232";
    auto six = new ::Six{initial};
    ASSERT_TRUE(convertAnswer(initial, six->get_value()));
}

TEST(test_02, list) {
    const auto initial = "23153";
    const auto six = new ::Six{'2', '3', '1', '5', '3'};
    ASSERT_TRUE(convertAnswer(initial, six->get_value()));
}

TEST(test_03, summary){
    const auto string1 = ::Six("21");
    const auto string2 = ::Six("33");
    // std::cout << (string2 + string1).get_value();
    ASSERT_TRUE(convertAnswer("54", (string2 + string1).get_value()));
}

TEST(test_04, summary){
    const auto string1 = ::Six("341");
    const auto string2 = ::Six("");
    ASSERT_TRUE(convertAnswer("341", (string2 + string1).get_value()));
}

TEST(test_05, subtraction){
    const auto string1 = ::Six("341");
    const auto string2 = ::Six("105");
    ASSERT_TRUE(convertAnswer("232", (string1 - string2).get_value()));
}

TEST(test_06, subtraction){
    const auto string1 = ::Six("341");
    const auto string2 = ::Six("");
    ASSERT_TRUE(convertAnswer("341", (string1 - string2).get_value()));
}

TEST(test_07, equivalence){
    const auto string1 = ::Six("1234");
    const auto string2 = ::Six("1234");
    ASSERT_TRUE(string1 == string2);
}

TEST(test_08, equivalence){
    const auto string1 = ::Six("1234");
    const auto string2 = ::Six("1233");
    ASSERT_TRUE(!(string1 == string2));
}

TEST(test_09, less){
    const auto string1 = ::Six("1234");
    const auto string2 = ::Six("1235");
    ASSERT_TRUE(string1 < string2);
}

TEST(test_10, more){
    const auto string1 = ::Six("1235");
    const auto string2 = ::Six("1233");
    ASSERT_TRUE(!(string1 < string2));
}

TEST(test_12, plus_equals){
    auto string1 = ::Six("21");
    const auto string2 = ::Six("5");
    string1 += string2;
    ASSERT_TRUE(convertAnswer("30", string1.get_value()));
}

TEST(test_13, minus_equals){
    auto string1 = ::Six("21");
    const auto string2 = ::Six("5");
    string1 -= string2;
    ASSERT_TRUE(convertAnswer("12", string1.get_value()));
}
