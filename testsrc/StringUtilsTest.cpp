#include <gtest/gtest.h>
#include "StringUtils.h"


//returns substring of a string, include end of string
TEST(StringUtilsTest, SliceTest){
    std::string Base = "Hello, World!";

    // Test positive indices
    EXPECT_EQ(StringUtils::Slice(Base, 0, 5), "Hello");
    EXPECT_EQ(StringUtils::Slice(Base, 7, 12), "World");

    //Test negative indices
    EXPECT_EQ(StringUtils::Slice(Base, -6, -1), "World!");

    //Test with end = 0 (include end of string)
    EXPECT_EQ(StringUtils::Slice(Base, 7), "World!");   

    // Test with end beyond the length of the string
    EXPECT_EQ(StringUtils::Slice(Base, 7, 20), "World!");

}
 

/* TEST(StringUtilsTest, Capitalize){
    std::string Base = "hello";
    EXPECT_EQ(StringUtils::Capitalize(Base), "Hello");
    EXPECT_EQ(StingUtils::Capitalize("HELLO", "Hello"));
}

TEST(StringUtilsTest, Upper){
    std::string Base = "hello";
    EXPECT_EQ(StringUtils::Upper(Base, "HELLO"));
    EXPECT_EQ(StringUtils::Upper("eriam", "ERIAM"));
    
}

TEST(StringUtilsTest, Lower){
    std::string Base = "HELLO";
    EXPECT_EQ(StringUtils::Upper(Base, "hello"));
    EXPECT_EQ(StringUtils::Upper("eRIaM", "eriam"));
    EXPECT_EQ(StringUtils::Upper("HI THERE!", "hi there!"));
}

TEST(StringUtilsTest, LStrip){
    std::string Base =" hello";
    EXPECT_EQ(StringUtils:: LStrip(Base, "hello"));
    EXPECT_EQ(StringUtils:: LStrip(" hi there ", "hi there "));

}

TEST(StringUtilsTest, RStrip){
    std::string Base ="hello ";
    EXPECT_EQ(StringUtils:: RStrip(Base, "hello"));
    EXPECT_EQ(StringUtils:: RStrip(" hi there ", " hi there"));
}

TEST(StringUtilsTest, Strip){
    std::string Base =" hello ";
    EXPECT_EQ(StringUtils:: Strip(Base, "hello"));
    EXPECT_EQ(StringUtils:: Strip(" hi there ", "hi there"));
    EXPECT_EQ(StringUtils:: Strip(" hi there pardner   ", "hi there pardner"));
} */

/* TEST(StringUtilsTest, Center){
    std::str Base = "hello";
    EXPECT_EQ(StringUtils:: Center(Base, " hello "));
    EXPECT_EQ(StringUtils:: Center(Base, " @hello@ "));
}

TEST(StringUtilsTest, LJust){
    std::str Base = "   hello";
    EXPECT_EQ(StringUtils:: Center(Base, "hello   "));
    EXPECT_EQ(StringUtils:: Center("    hello ", "hello   "));
}

TEST(StringUtilsTest, RJust){
    std::str Base = "hello   ";
    EXPECT_EQ(StringUtils:: Center(Base, "   hello"));
    EXPECT_EQ(StringUtils:: Center(" hello   ", "   hello"));
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
 */