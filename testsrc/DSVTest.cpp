#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "StringDataSink.h"
#include "StringDataSource.h"
#include "DSVReader.h"
#include "DSVWriter.h"

//READER TEST CASES---------------------------------------------------------

//Simplest test case: & delimiter
TEST(DSVReader, Readrow) {
    auto Source = std::make_shared<CStringDataSource>("Hello&World!");
    CDSVReader Reader(Source, '&');
    std::vector<std::string> output;

    EXPECT_TRUE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 2);
    EXPECT_EQ(output[0], "Hello");
    EXPECT_EQ(output[1], "World!");
}
//Test Case 2: Quotations inside given string
TEST(DSVReader, Readrow_DoubleQuote) {
    auto Source = std::make_shared<CStringDataSource>("Hello\"o\", World!");
    CDSVReader Reader(Source, ',');
    std::vector<std::string> output;

    EXPECT_TRUE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 2);
    EXPECT_EQ(output[0], "Hello\"o\"");
    EXPECT_EQ(output[1], " World!");
}
//Test Case 3: Readrow returns false (EOF/empty file)
TEST(DSVReader, Readrow_Failure) {
    auto Source = std::make_shared<CStringDataSource>("");
    CDSVReader Reader(Source, ',');
    std::vector<std::string> output;

    EXPECT_FALSE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 0);  // No successful columns should be read
}
//Test Case 4: Newline with comma delim
TEST(DSVReader, ReadRowNewlineTest){
    auto Source = std::make_shared<CStringDataSource>("abc\nhi,10");
    CDSVReader Reader(Source, ',');
    std::vector<std::string> output;

    EXPECT_TRUE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 1);
    EXPECT_EQ(output[0], "abc");

    EXPECT_TRUE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 2);
    EXPECT_EQ(output[0], "hi");
    EXPECT_EQ(output[1], "10");

}

//Test Case 5: More Newlines + Delimiter input
TEST(DSVReader, Readrow_Newline2) {
    auto Source = std::make_shared<CStringDataSource>("Name&ID\nPEGGY&100");
    CDSVReader Reader(Source, '&');
    std::vector<std::string> output;

//Second row/vector is the only one getting output
    EXPECT_TRUE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 2);
    EXPECT_EQ(output[0], "Name");
    EXPECT_EQ(output[1], "ID");

    EXPECT_TRUE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 2);
    EXPECT_EQ(output[0], "PEGGY");
    EXPECT_EQ(output[1], "100");
}



//WRITER TEST CASES -----------------------------------------------------------

//Simplest case #1: & delimiter
TEST(DSVWriter, Writerow){
    auto Sink = std::make_shared<CStringDataSink>(); //Sink = shared pointer to CStringDataSink object
    CDSVWriter Writer(Sink, '&'); //Writer = object of CDSVWriter class, taking in shared ptr and delim
    std::vector<std::string> input = {"Hello", "World!"};

    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello&World!");
}


//case #2: NO
// TEST(DSVWriter, WritefieldNewline){
//     auto Sink = std::make_shared<CStringDataSink>();
//     CDSVWriter Writer(Sink, ',');
//     std::vector<std::string> input = {"Hello", "World!"};

//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello,World!");
//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello,World!\nHello,World!");
// }

// TEST(DSVWriter, DoubleQuoteIsDelimiter){
//     auto Sink = std::make_shared<CStringDataSink>();
//     CDSVWriter Writer(Sink, '"');
//     std::vector<std::string> input = {"Hello", "World!"};

//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello,World!");
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


//WRITER TEST CASES

//, delimiter
// TEST(DSVWriter, ExampleTestNewline) {
//     auto Sink = std::make_shared<CStringDataSink>();
//     CDSVWriter Writer(Sink, ',');
//     std::vector<std::string> input = {"Hello", "World!"}; 

//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello,World!"); 
//     EXPECT_TRUE(Writer.WriteRow(input));
//     EXPECT_EQ(Sink->String(), "Hello,World!\nHello,World!");
// } 


