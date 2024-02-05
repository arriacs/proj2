#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "StringDataSink.h"
#include "DSVReader.h"
#include "DSVWriter.h"


// TEST(DSVWriter, ExampleTest){
//     auto Sink = std::make_shared<CStringDataSink>();
//     CDSVWriter Writer(Sink, '&');
//     std::vector<std::string> input = {"Hello", "World!"};

//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello&World!");
// }

// TEST(DSVWriter, ExampleTestNewline){
//     auto Sink = std::make_shared<CStringDataSink>();
//     CDSVWriter Writer(Sink, ',');
//     std::vector<std::string> input = {"Hello", "World!"};

//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello,World!");
//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello,World!\nHello,World!");
// }

// TEST(DSVTest, WriteDoubleQuotationsWithDelimiter){
//     auto Sink = std::make_shared<CStringDataSink>();
//     CDSVWriter Writer(Sink, '&');
//     std::vector<std::string> input = {"&", "mystring"};

//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(),"\"&\"&mystring");  
//     // OR: 
//     EXPECT_EQ(Sink->String(),"\"&&mystring\"");

// }

//& delimiter
TEST(DSVWriter, ExampleTest) {
    auto Sink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(Sink, '&');
    std::vector<std::string> input = {"Hello", "World!"};

    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello&World!"); 
}
//, delimiter
TEST(DSVWriter, ExampleTestNewline) {
    auto Sink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(Sink, ',');
    std::vector<std::string> input = {"Hello", "World!"}; 

    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello,World!"); 
    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello,World!\nHello,World!");
}

// TEST(DSVWriter, WriteDoubleQuotationsWithDelimiter) {
//     auto Sink = std::make_shared<CStringDataSink>();
//     CDSVWriter Writer(Sink, '&');
//     std::vector<std::string> input = {"\"&\"&mystring\n"};

//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "\"&\"&mystring");
//     // OR:
//     // EXPECT_EQ(Sink->String(), "\"&&mystring\"");
// }

// TEST(DSVReader, ReadRow) {
//     // Assuming you have a valid StringDataSource implementation
//     auto Source = std::make_shared<CStringDataSource>("Hello&World!\nHello,World!");

//     CDSVReader Reader(Source, ',');
//     std::vector<std::string> row;

//     EXPECT_FALSE(Reader.End());
//     EXPECT_TRUE(Reader.ReadRow(row));
//     EXPECT_EQ(row.size(), 2);
//     EXPECT_EQ(row[0], "Hello");
//     EXPECT_EQ(row[1], "World!");

//     EXPECT_FALSE(Reader.End());
//     EXPECT_TRUE(Reader.ReadRow(row));
//     EXPECT_EQ(row.size(), 2);
//     EXPECT_EQ(row[0], "Hello");
//     EXPECT_EQ(row[1], "World!");

//     EXPECT_TRUE(Reader.End());
//     EXPECT_FALSE(Reader.ReadRow(row)); // Reading beyond end
// }
