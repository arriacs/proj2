#include <gtest/gtest.h>
#include "StringDataSource.h"

// Create instances of CStringDataSource with different strings (different objects of CStringDataSource)
TEST(StringDataSource, EndTest){
    CStringDataSource EmptySource("");
    CStringDataSource BaseSource("Hello");

// Test whether End() correctly identifies the end of the data source
    EXPECT_TRUE(EmptySource.End()); // Empty source should be at the end
    EXPECT_FALSE(BaseSource.End()); // Non-empty source should not be at the end
}

TEST(StringDataSource, PeekTest){
    CStringDataSource EmptySource(""); //Object of CSDS with parameter " " as input
    CStringDataSource Source1("Hello"); //Another object of CDSDS w diff parameter
    CStringDataSource Source2("Bye");
    char TempCh = 'x'; //this TEST func has a char var

    EXPECT_FALSE(EmptySource.Peek(TempCh)); // Peek on empty source should return false
    EXPECT_EQ(TempCh,'x'); // TempCh should remain unchanged
    EXPECT_TRUE(Source1.Peek(TempCh)); //Peek on non-empty string should return true
    EXPECT_EQ(TempCh,'H'); //Temp should be set to next char, which is 'H'
    TempCh = 'x'; //temp is reset to x
    EXPECT_TRUE(Source1.Peek(TempCh));
    EXPECT_EQ(TempCh,'H');
    EXPECT_TRUE(Source2.Peek(TempCh));
    EXPECT_EQ(TempCh,'B');
    TempCh = 'x';
    EXPECT_TRUE(Source2.Peek(TempCh));
    EXPECT_EQ(TempCh,'B');
}

TEST(StringDataSource, GetTest){
    CStringDataSource EmptySource("");
    CStringDataSource Source1("Hello");
    CStringDataSource Source2("Bye");
    char TempCh = 'x';

//Peek() DOES NOT move onto the next char until it is consumed w/ Get().
//So, if you keep calling Peek() on a given string, it will keep returning the same char
//in this instance
    EXPECT_FALSE(EmptySource.Get(TempCh));
    EXPECT_EQ(TempCh,'x');
    EXPECT_TRUE(Source1.Get(TempCh));
    EXPECT_EQ(TempCh,'H');
    TempCh = 'x';
    EXPECT_TRUE(Source1.Peek(TempCh));
    EXPECT_EQ(TempCh,'e');
    TempCh = 'x';
    EXPECT_TRUE(Source1.Peek(TempCh));
    EXPECT_EQ(TempCh,'e');
    EXPECT_TRUE(Source2.Get(TempCh));
    EXPECT_EQ(TempCh,'B');
    TempCh = 'x';
    EXPECT_TRUE(Source2.Peek(TempCh));
    EXPECT_EQ(TempCh,'y');
    TempCh = 'x';
    EXPECT_TRUE(Source2.Peek(TempCh));
    EXPECT_EQ(TempCh,'y');
}

TEST(StringDataSource, ReadTest){
    CStringDataSource EmptySource("");
    CStringDataSource Source1("Hello");
    CStringDataSource Source2("Bye");
    std::vector< char > TempVector;
    char TempCh = 'x';

    EXPECT_FALSE(EmptySource.Read(TempVector,3));
    EXPECT_EQ(TempVector.size(),0);
    EXPECT_TRUE(Source1.Read(TempVector,4));
    ASSERT_TRUE(TempVector.size() >= 4);
    EXPECT_EQ(TempVector[0],'H');
    EXPECT_EQ(TempVector[1],'e');
    EXPECT_EQ(TempVector[2],'l');
    EXPECT_EQ(TempVector[3],'l');
    EXPECT_TRUE(Source1.Peek(TempCh));
    EXPECT_EQ(TempCh,'o');
    EXPECT_TRUE(Source2.Read(TempVector,4));
    ASSERT_TRUE(TempVector.size() >= 3);
    EXPECT_EQ(TempVector[0],'B');
    EXPECT_EQ(TempVector[1],'y');
    EXPECT_EQ(TempVector[2],'e');
    TempCh = 'x';
    EXPECT_FALSE(Source2.Peek(TempCh));
    EXPECT_EQ(TempCh,'x');
}
