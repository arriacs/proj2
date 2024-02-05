#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string basecase = "hello world";
    std::string expected = "hello";
    std::string actual = StringUtils::Slice(basecase, 0, 5); // slice from start 0 index to end 5 index
    // compare actual and expected
    EXPECT_EQ(actual, expected);
}

TEST(StringUtilsTest, Capitalize){
    std::string basecase = "hello world";
    std::string expected = "Hello world";
    std::string actual = StringUtils::Capitalize(basecase);
    EXPECT_EQ(actual, expected);
}

TEST(StringUtilsTest, Upper){
    std::string basecase = "hello world";
    std::string expected = "HELLO WORLD";
    std::string actual = StringUtils::Upper(basecase);
    EXPECT_EQ(actual, expected);
}

TEST(StringUtilsTest, Lower){
    std::string basecase = "HELLO WORLD";
    std::string expected = "hello world";
    std::string actual = StringUtils::Lower(basecase);
    EXPECT_EQ(actual, expected);
}

TEST(StringUtilsTest, LStrip){
    std::string basecase = "   hello world";
    std::string expected = "hello world";
    std::string actual = StringUtils::LStrip(basecase);
    EXPECT_EQ(actual, expected);
}

TEST(StringUtilsTest, RStrip){
    std::string basecase = "hello world   ";
    std::string expected = "hello world";
    std::string actual = StringUtils::RStrip(basecase);
    EXPECT_EQ(actual, expected);
}

TEST(StringUtilsTest, Strip){
    std::string basecase = "   hello world   ";
    std::string expected = "hello world";
    std::string actual = StringUtils::Strip(basecase);
    EXPECT_EQ(actual, expected);
}

// TEST(StringUtilsTest, Center){
//     std::string basecase = "hello";
//     std::string expected = "  hello  ";
//     std::string actual = StringUtils::Center(basecase, 9);
//     EXPECT_EQ(actual, expected);
// }

// TEST(StringUtilsTest, LJust){
//     std::string basecase = "hello";
//     std::string expected = "hello  ";
//     std::string actual = StringUtils::LJust(basecase, 7);
//     EXPECT_EQ(actual, expected);
// }

// TEST(StringUtilsTest, RJust){
//     std::string basecase = "hello";
//     std::string expected = "  hello";
//     std::string actual = StringUtils::RJust(basecase, 7);
//     ASSERT_EQ(actual, expected);
// }

TEST(StringUtilsTest, Replace){
    std::string basecase = "hello world";
    std::string expected = "hello universe";
    std::string actual = StringUtils::Replace(basecase, "world", "universe");
    ASSERT_EQ(actual, expected);
}

TEST(StringUtilsTest, Split){
    std::string basecase = "hello world";
    std::vector<std::string> expected = {"hello", "world"};
    std::vector<std::string> actual = StringUtils::Split(basecase, " ");
    ASSERT_EQ(actual, expected);
}

TEST(StringUtilsTest, Join){
    std::vector<std::string> basecase = {"hello", "world"};
    std::string expected = "hello world";
    std::string actual = StringUtils::Join(" ", basecase);
    ASSERT_EQ(actual, expected);
}

TEST(StringUtilsTest, ExpandTabs){
    std::string basecase = "hello\tworld";
    std::string expected = "hello    world";
    std::string actual = StringUtils::ExpandTabs(basecase);
    ASSERT_EQ(actual, expected);
}
/*
TEST(StringUtilsTest, EditDistance){
    std::string left = "hello";
    std::string right = "world";
    int expected = 5; // It takes at least 5 edits to change "hello" into "world"
    int actual = StringUtils::EditDistance(left, right);
    EXPECT_EQ(actual, expected);
}*/
 