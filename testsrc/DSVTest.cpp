#include <gtest/gtest.h>
#include "StringDataSink.h"
#include "StringDataSource.h"

TEST(DSVWriter, ExampleTest){
    auto Sink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(Sink, '&');
    std::vector<std::string> input = {"Hello", "World!"};

    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello&World!");
}

TEST(DSVWriter, ExampleTestNewline){
    auto Sink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(Sink, ',');
    std::vector<std::string> input = {"Hello", "World!"};

    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello,World!");
    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello,World!\nHello,World!");
}