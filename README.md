# proj2 X README

Ariana Smith (920707315)

Jessie Lin (919347812)

## Project Status

Incomplete... working on DSVWriter test cases and implementation, 
have attempted DSVReader but isn't working

## Known Issues

Implementing DSVReader... unsure of where to start

## Code References 


## Generative AI Use

## Prompt 1

does this error mean my makefile is working?

root@4ec7042e2b6e:/workspace/proj2# make
mkdir -p ./obj
mkdir -p ./bin
g++ -o ./obj/StringUtils.o -c -std=c++17 -I ./include -Wall ./src/StringUtils.cpp
g++ -o ./obj/StringUtilsTest.o -c -std=c++17 -I ./include -Wall ./testsrc/StringUtilsTest.cpp
g++ -o ./bin/teststrutils -std=c++17 -I ./include -Wall ./obj/StringUtils.o ./obj/StringUtilsTest.o -lgtest -lgtest_main -lpthread -lexpat
g++ -o ./obj/StringDataSource.o -c -std=c++17 -I ./include -Wall ./src/StringDataSource.cpp
g++ -o ./obj/StringDataSourceTest.o -c -std=c++17 -I ./include -Wall ./testsrc/StringDataSourceTest.cpp
g++ -o ./bin/testsrdatasource -std=c++17 -I ./include -Wall ./obj/StringDataSource.o ./obj/StringDataSourceTest.o -lgtest -lgtest_main -lpthread -lexpat
g++ -o ./obj/DSVReader.o -c -std=c++17 -I ./include -Wall ./src/DSVReader.cpp
g++ -o ./obj/DSVWriter.o -c -std=c++17 -I ./include -Wall ./src/DSVWriter.cpp
g++ -o ./obj/DSVTest.o -c -std=c++17 -I ./include -Wall ./testsrc/DSVTest.cpp
g++ -o ./obj/StringDataSinkTest.o -c -std=c++17 -I ./include -Wall ./testsrc/StringDataSinkTest.cpp
g++ -o ./bin/testdsv -std=c++17 -I ./include -Wall ./obj/DSVReader.o ./obj/DSVWriter.o ./obj/DSVTest.o -lgtest -lgtest_main -lpthread -lexpat
/usr/bin/ld: ./obj/DSVTest.o: warning: relocation against `_ZTV15CStringDataSink' in read-only section `.text._ZN15CStringDataSinkC2Ev[_ZN15CStringDataSinkC5Ev]'
/usr/bin/ld: ./obj/DSVTest.o: in function `DSVWriter_ExampleTest_Test::TestBody()':
DSVTest.cpp:(.text+0x5f): undefined reference to `CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink>, char, bool)'
/usr/bin/ld: DSVTest.cpp:(.text+0x17c): undefined reference to `CDSVWriter::WriteRow(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&)'
/usr/bin/ld: DSVTest.cpp:(.text+0x274): undefined reference to `CStringDataSink::String[abi:cxx11]() const'
/usr/bin/ld: DSVTest.cpp:(.text+0x347): undefined reference to `CDSVWriter::~CDSVWriter()'
/usr/bin/ld: DSVTest.cpp:(.text+0x49f): undefined reference to `CDSVWriter::~CDSVWriter()'
/usr/bin/ld: ./obj/DSVTest.o: in function `DSVWriter_ExampleTestNewline_Test::TestBody()':
DSVTest.cpp:(.text+0x52f): undefined reference to `CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink>, char, bool)'
/usr/bin/ld: DSVTest.cpp:(.text+0x667): undefined reference to `CDSVWriter::WriteRow(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&)'
/usr/bin/ld: DSVTest.cpp:(.text+0x780): undefined reference to `CStringDataSink::String[abi:cxx11]() const'
/usr/bin/ld: DSVTest.cpp:(.text+0x857): undefined reference to `CDSVWriter::WriteRow(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&)'
/usr/bin/ld: DSVTest.cpp:(.text+0x94f): undefined reference to `CStringDataSink::String[abi:cxx11]() const'
/usr/bin/ld: DSVTest.cpp:(.text+0xa22): undefined reference to `CDSVWriter::~CDSVWriter()'
/usr/bin/ld: DSVTest.cpp:(.text+0xc12): undefined reference to `CDSVWriter::~CDSVWriter()'
/usr/bin/ld: ./obj/DSVTest.o: in function `DSVTest_WriteDoubleQuotationsWithDelimiter_Test::TestBody()':
DSVTest.cpp:(.text+0xca1): undefined reference to `CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink>, char, bool)'
/usr/bin/ld: DSVTest.cpp:(.text+0xdd9): undefined reference to `CDSVWriter::WriteRow(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&)'
/usr/bin/ld: DSVTest.cpp:(.text+0xed7): undefined reference to `CStringDataSink::String[abi:cxx11]() const'
/usr/bin/ld: DSVTest.cpp:(.text+0xfa3): undefined reference to `CStringDataSink::String[abi:cxx11]() const'
/usr/bin/ld: DSVTest.cpp:(.text+0x1076): undefined reference to `CDSVWriter::~CDSVWriter()'
/usr/bin/ld: DSVTest.cpp:(.text+0x120d): undefined reference to `CDSVWriter::~CDSVWriter()'
/usr/bin/ld: ./obj/DSVTest.o: in function `CStringDataSink::CStringDataSink()':
DSVTest.cpp:(.text._ZN15CStringDataSinkC2Ev[_ZN15CStringDataSinkC5Ev]+0x1b): undefined reference to `vtable for CStringDataSink'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
make: *** [Makefile:52: bin/testdsv] Error 1

## Response 1 

The error you're encountering seems to be related to unresolved references during the linking phase. Specifically, it mentions undefined references to various methods and constructors from classes like CDSVWriter and CStringDataSink. This indicates that the implementation for these methods or constructors is missing or not properly linked.

Here are some things you can check:

Ensure Implementation Files Are Included in Compilation:
Make sure that the source files containing the implementations of CDSVWriter and CStringDataSink (like DSVWriter.cpp and CStringDataSink.cpp) are included in the compilation process. It seems like the linker cannot find the definitions for these methods, which might be in separate source files.

Check Object Files:
Verify that object files (.o files) generated from the source files containing the implementations are present in the ./obj directory. In your makefile, you have compilation commands for DSVWriter.cpp and CStringDataSink.cpp, but you should check that the corresponding object files are generated and exist.

Check Dependencies:
Ensure that there are no missing dependencies or incorrect order of object files during linking. The order of object files in the linking command can matter, and dependencies should be resolved in the correct order.

Check Constructor Definitions:
Ensure that the constructors mentioned in the error, like CDSVWriter::CDSVWriter and CStringDataSink::CStringDataSink, are defined in the corresponding source files.

Check for Typos or Case Sensitivity:
Ensure that there are no typos in the class and method names. C++ is case-sensitive, so CDSVWriter and CDSvWriter would be considered different.

Library Linking:
Ensure that the necessary libraries, such as -lgtest and -lpthread, are correctly linked.

It seems like the issue is with the implementation or linking of CDSVWriter and CStringDataSink. Reviewing the relevant source files and their compilation/linking in your makefile should help identify and resolve the problem.

## Changes 1

I eventually added necessary libraries to help with linking, though there were other issues

## Prompt 2

root@4ec7042e2b6e:/workspace/proj2# make
mkdir -p ./obj
mkdir -p ./bin
g++ -o ./obj/StringUtils.o -c -std=c++17 -I ./include -Wall ./src/StringUtils.cpp
g++ -o ./obj/StringUtilsTest.o -c -std=c++17 -I ./include -Wall ./testsrc/StringUtilsTest.cpp
g++ -o ./bin/teststrutils -std=c++17 -I ./include -Wall ./obj/StringUtils.o ./obj/StringUtilsTest.o -lgtest -lgtest_main -lpthread -lexpat -lgtest -lgtest_main
g++ -o ./obj/StringDataSource.o -c -std=c++17 -I ./include -Wall ./src/StringDataSource.cpp
g++ -o ./obj/StringDataSourceTest.o -c -std=c++17 -I ./include -Wall ./testsrc/StringDataSourceTest.cpp
g++ -o ./bin/testsrdatasource -std=c++17 -I ./include -Wall ./obj/StringDataSource.o ./obj/StringDataSourceTest.o -lgtest -lgtest_main -lpthread -lexpat -lgtest -lgtest_main   
g++ -o ./obj/StringDataSink.o -c -std=c++17 -I ./include -Wall ./src/StringDataSink.cpp
g++ -o ./obj/StringDataSinkTest.o -c -std=c++17 -I ./include -Wall ./testsrc/StringDataSinkTest.cpp
g++ -o ./bin/testsrdatasink -std=c++17 -I ./include -Wall ./obj/StringDataSink.o ./obj/StringDataSinkTest.o -lgtest -lgtest_main -lpthread -lexpat -lgtest -lgtest_main
g++ -o ./obj/DSVReader.o -c -std=c++17 -I ./include -Wall ./src/DSVReader.cpp
g++ -o ./obj/DSVWriter.o -c -std=c++17 -I ./include -Wall ./src/DSVWriter.cpp
./src/DSVWriter.cpp: In member function ‘bool CDSVWriter::SImplementation::WriteRow(const std::vector<std::__cxx11::basic_string<char> >&)’:
./src/DSVWriter.cpp:55:29: error: no matching function for call to ‘CDataSink::Write(char*, int)’
   55 |                 DSink->Write(&DDelimiter, 1);
      |                 ~~~~~~~~~~~~^~~~~~~~~~~~~~~~
In file included from ./include/DSVWriter.h:8,
                 from ./src/DSVWriter.cpp:1:
./include/DataSink.h:10:22: note: candidate: ‘virtual bool CDataSink::Write(const std::vector<char>&)’
   10 |         virtual bool Write(const std::vector<char> &buf) noexcept = 0;
      |                      ^~~~~
./include/DataSink.h:10:22: note:   candidate expects 1 argument, 2 provided
./src/DSVWriter.cpp:59:29: error: no matching function for call to ‘CDataSink::Write(const char [2], int)’
   59 |                 DSink->Write("\"", 1);
      |                 ~~~~~~~~~~~~^~~~~~~~~
./include/DataSink.h:10:22: note: candidate: ‘virtual bool CDataSink::Write(const std::vector<char>&)’
   10 |         virtual bool Write(const std::vector<char> &buf) noexcept = 0;
      |                      ^~~~~
./include/DataSink.h:10:22: note:   candidate expects 1 argument, 2 provided
./src/DSVWriter.cpp:60:29: error: no matching function for call to ‘CDataSink::Write(const char*, std::__cxx11::basic_string<char>::size_type)’
   60 |                 DSink->Write(row[i].c_str(), row[i].length());
      |                 ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
./include/DataSink.h:10:22: note: candidate: ‘virtual bool CDataSink::Write(const std::vector<char>&)’
   10 |         virtual bool Write(const std::vector<char> &buf) noexcept = 0;
      |                      ^~~~~
./include/DataSink.h:10:22: note:   candidate expects 1 argument, 2 provided
./src/DSVWriter.cpp:61:29: error: no matching function for call to ‘CDataSink::Write(const char [2], int)’
   61 |                 DSink->Write("\"", 1);
      |                 ~~~~~~~~~~~~^~~~~~~~~
./include/DataSink.h:10:22: note: candidate: ‘virtual bool CDataSink::Write(const std::vector<char>&)’
   10 |         virtual bool Write(const std::vector<char> &buf) noexcept = 0;
      |                      ^~~~~
./include/DataSink.h:10:22: note:   candidate expects 1 argument, 2 provided
./src/DSVWriter.cpp:63:29: error: no matching function for call to ‘CDataSink::Write(const char*, std::__cxx11::basic_string<char>::size_type)’
   63 |                 DSink->Write(row[i].c_str(), row[i].length());
      |                 ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
./include/DataSink.h:10:22: note: candidate: ‘virtual bool CDataSink::Write(const std::vector<char>&)’
   10 |         virtual bool Write(const std::vector<char> &buf) noexcept = 0;
      |                      ^~~~~
./include/DataSink.h:10:22: note:   candidate expects 1 argument, 2 provided
./src/DSVWriter.cpp:67:21: error: no matching function for call to ‘CDataSink::Write(const char [2], int)’
   67 |         DSink->Write("\n", 1);
      |         ~~~~~~~~~~~~^~~~~~~~~
./include/DataSink.h:10:22: note: candidate: ‘virtual bool CDataSink::Write(const std::vector<char>&)’
   10 |         virtual bool Write(const std::vector<char> &buf) noexcept = 0;
      |                      ^~~~~
./include/DataSink.h:10:22: note:   candidate expects 1 argument, 2 provided
make: *** [Makefile:62: obj/DSVWriter.o] Error 1

## Response 2

The error is due to the fact that your `CDataSink` class does not have a suitable `Write` function that takes a `char*` and a size. The `DSink->Write(&DDelimiter, 1);` line is attempting to call such a function.

To fix this, you need to update your `CDataSink` interface to include a method that can accept a `char*` and a size, like this:

```cpp
// In DataSink.h
class CDataSink {
public:
    // Existing functions...

    // Add this function to support writing a buffer of a given size
    virtual bool Write(const char* buf, std::size_t size) noexcept = 0;
};
```

Now, your `CDSVWriter` implementation in `DSVWriter.cpp` should compile without errors.

Make sure that `CDataSink` is correctly updated and that you have recompiled any other classes that depend on it. After making these changes, run `make clean` and then `make` again.

## Changes 2

None of the functions were actually implemented yet, so I implemented some code to see if that would change anything

## Q 3

what does this mean:
Expected equality of these values:
  Sink->String()
    Which is: "Hello,World!Hello,World!"
  "Hello,World!\nHello,World!"
With diff:
@@ -1,1 +1,2 @@
-Hello,World!Hello,World!
+Hello,World!
+Hello,World!

## Ans 3

This error message is coming from a testing framework and indicates that an equality check failed between the actual value (`Sink->String()`) and the expected value (`"Hello,World!\nHello,World!"`). The diff section shows the specific difference between the two values.

Here's a breakdown:

- The expected value is `"Hello,World!\nHello,World!"`, which includes a newline character `\n` between the two parts of the string.
- The actual value (`Sink->String()`) seems to be `"Hello,World!Hello,World!"`, without the newline character.

The diff shows that the test expected a string with a newline character between "Hello,World!" and the next "Hello,World!" but did not find it in the actual value.

To fix this issue, you may need to adjust your code to ensure that the newline character is correctly added after writing each row, as suggested in the comments in your DSVWriter implementation:

```cpp
// Remove the newline character here
// DSink->Put('\n');
```

You might want to uncomment that line to ensure that a newline character is added at the end of each row, aligning it with the expectations of your tests.

## Changes 3

I didn't uncomment that line since I wasn't sure if it was actually correct or not, so just continued to work on tests that involved newlines

## Q4

what does an empty semicolon mean in a for loop

## Ans 4

An empty semicolon in a for loop in C++ is used to omit the initialization or condition or the update part of the loop. This can be done when you want to skip one or more of these parts.

The general syntax of a for loop is:

```cpp
for (initialization; condition; update) {
    // loop body
}
```

However, any of these three parts can be omitted, and an empty semicolon is used as a placeholder.

Here are a few examples:

1. **Omitting Initialization:**
   ```cpp
   int i = 0;
   for (; i < 5; ++i) {
       // loop body
   }
   ```
   In this example, the initialization part is done outside the loop, and the loop starts with an empty semicolon.

2. **Omitting Condition:**
   ```cpp
   int i = 0;
   for (; ; ++i) {
       // loop body
       if (i >= 5)
           break;
   }
   ```
   Here, the condition is omitted, and it relies on a break statement inside the loop to exit when `i` reaches a certain value.

3. **Omitting Update:**
   ```cpp
   for (int i = 0; i < 5; ) {
       // loop body
       ++i; // update done inside the loop body
   }
   ```
   In this case, the update part is omitted from the for loop, and the variable `i` is updated inside the loop body.

While using empty semicolons can be a valid way to structure a for loop, it's important to ensure that the loop still behaves as intended and doesn't lead to confusing or error-prone code. In many cases, it's clearer to include all three parts for better readability and maintainability.

## Change 4

Used semi colon to skip re-initiation in my WriteRow for loop

## Q 5

class CStringDataSink : public CDataSink{
    private:
        std::string DString;
    public:
        const std::string &String() const; //can put chars into it and use this to find out what chars you put into it

        bool Put(const char &ch) noexcept override;
        bool Write(const std::vector<char> &buf) noexcept override;
};

#endif

#include "StringDataSink.h"

const std::string &CStringDataSink::String() const{
    return DString;
}

bool CStringDataSink::Put(const char &ch) noexcept{
    DString += std::string(1,ch);
    return true;
}
// Returns true if the row is successfully written, one string per column
// should be put in the row vector
bool CStringDataSink::Write(const std::vector<char> &buf) noexcept{
    DString += std::string(buf.data(),buf.size());
    return true;
}

explain how these different files create the CDataSink object and how stuff is "written " to it. 

## Ans 5

Let's break down the provided code into parts to understand how the `CStringDataSink` class, which is derived from `CDataSink`, is implemented and how it handles writing data.

1. **Header File (StringDataSink.h):**
```cpp
// StringDataSink.h

#ifndef STRING_DATA_SINK_H
#define STRING_DATA_SINK_H

#include "DataSink.h" // Assume CDataSink is defined in DataSink.h

class CStringDataSink : public CDataSink {
private:
    std::string DString;

public:
    const std::string &String() const;
    bool Put(const char &ch) noexcept override;
    bool Write(const std::vector<char> &buf) noexcept override;
};

#endif
```

This header file declares the `CStringDataSink` class, which inherits from `CDataSink`. It also declares member functions for getting the content of the string (`String()`), putting a character into the sink (`Put`), and writing a vector of characters into the sink (`Write`).

2. **Implementation File (StringDataSink.cpp):**
```cpp
// StringDataSink.cpp

#include "StringDataSink.h"

const std::string &CStringDataSink::String() const {
    return DString;
}

bool CStringDataSink::Put(const char &ch) noexcept {
    DString += std::string(1, ch);
    return true;
}

bool CStringDataSink::Write(const std::vector<char> &buf) noexcept {
    DString += std::string(buf.data(), buf.size());
    return true;
}
```

This implementation file defines the member functions declared in the header file. 

- `String()` returns a constant reference to the internal string `DString`.
- `Put` appends a single character to `DString`.
- `Write` appends a vector of characters to `DString`.

These functions update the `DString` member variable with the provided characters.

3. **Usage in CDSVWriter:**
```cpp
// Assume CDSVWriter.cpp includes CStringDataSink.h

#include "StringDataSink.h"

// Some code...

std::shared_ptr<CDataSink> sink = std::make_shared<CStringDataSink>();
CDSVWriter csvWriter(sink, ',', true);

// WriteRow example:
std::vector<std::string> row = {"Column1", "Column2", "Column3"};
csvWriter.WriteRow(row);

// Accessing the content of CStringDataSink:
const std::string &outputString = dynamic_cast<CStringDataSink *>(sink.get())->String();
```

In this example, an instance of `CStringDataSink` is created using `std::make_shared<CStringDataSink>()`, and it is passed as an argument to the constructor of `CDSVWriter`. The `WriteRow` function of `CDSVWriter` is then used to write a row of strings.

After the writing operation, you can access the content of `CStringDataSink` using the `String()` function. Note that `dynamic_cast` is used here because the `sink` is of type `std::shared_ptr<CDataSink>`, but we want to access the specific functionality provided by `CStringDataSink`. 

This way, the `CStringDataSink` class acts as a destination for the data written by `CDSVWriter`. The content of the sink can be retrieved using the `String()` function.

## Change 5

Answer helped me understand what the sink CDataString actually is 

## Q 6

so does the variable DString actually hold the output contents, making it the sink?

## Ans 6

Yes, that's correct. In the `CStringDataSink` class, the private member variable `DString` is used to hold the output contents, making it function as the sink for the data being written. The `CStringDataSink` class is essentially a simple sink that accumulates the characters and strings written to it, storing them in the `DString` member variable.

Here's a breakdown of how `DString` serves as the sink:

1. **`Put` Function:**
   ```cpp
   bool CStringDataSink::Put(const char &ch) noexcept {
       DString += std::string(1, ch);
       return true;
   }
   ```
   The `Put` function appends a single character to the `DString`. This function is part of the `CDataSink` interface, and it's overridden in `CStringDataSink` to define how characters are added to the sink.

2. **`Write` Function:**
   ```cpp
   bool CStringDataSink::Write(const std::vector<char> &buf) noexcept {
       DString += std::string(buf.data(), buf.size());
       return true;
   }
   ```
   The `Write` function appends a vector of characters to the `DString`. Similar to `Put`, this function is part of the `CDataSink` interface, and it's implemented in `CStringDataSink` to handle the case where multiple characters are written at once.

3. **`String` Function:**
   ```cpp
   const std::string &CStringDataSink::String() const {
       return DString;
   }
   ```
   The `String` function provides read-only access to the contents of the sink (`DString`). This allows external code to inspect the accumulated output.

In summary, the `DString` member variable holds the output contents, making it the sink for the data being written by the `CDSVWriter` or any other code using this sink. It's a simple example of a sink that accumulates data, and in a real-world scenario, a sink might involve more complex operations like writing to files, databases, or network streams.

## Change 6

Allowed me to understand how to use Dsink, such as in my Writer.cpp file to check if the shared pointer was point to it.
 if (!DSink)

 ## Q7

 here is StringDataSource.cpp, but I don't want to edit this or the .h files, so help me fix it by only modifying DSVTest.cpp, the Makefile, or DSVReader.cpp. There's no CStringDataSource.h file, just StringDataSource.h that has CStringDataSource

#include "StringDataSource.h"
//Implementations of get, peek, etc from class CStringDataSource in StringDataSource.h

//initializing members of constructor from CStringDdataSource
CStringDataSource::CStringDataSource(const std::string &str) : DString(str), DIndex(0){ 

}
// Returns true if all rows have been read from the DSV
//Double colon "::" used bc we want to use End(), which has already been initialized,
// so it's out of scope. We access it through the double colon.
bool CStringDataSource::End() const noexcept{
    return DIndex >= DString.length();
}

bool CStringDataSource::Get(char &ch) noexcept{
    if(DIndex < DString.length()){
        ch = DString[DIndex];
        DIndex++;
        return true;
    }
    return false;
}

bool CStringDataSource::Peek(char &ch) noexcept{
    if(DIndex < DString.length()){
        ch = DString[DIndex]; //Peek won't advance to the next character here unless incremented.
        return true;
    }
    return false;
}
// Returns true if the row is successfully read, one string will be put in
// the row per column
bool CStringDataSource::Read(std::vector<char> &buf, std::size_t count) noexcept{
    buf.clear();
    while(buf.size() < count){
        char TempChar;
        if(Get(TempChar)){
            buf.push_back(TempChar);
        }
        else{
            break;
        }
    }
    return !buf.empty();
}


DSVTest.cpp: 

#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "StringDataSink.h"
#include "StringDataSource.h"
#include "DSVReader.h"
#include "DSVWriter.h"

//READER TEST CASES

TEST(DSVReader, Readrow) {
    auto Source = std::make_shared<CStringDataSource>("Hello&World!");
    CDSVReader Reader(Source, '&');
    std::vector<std::string> output;

    EXPECT_TRUE(Reader.ReadRow(output));
    ASSERT_EQ(output.size(), 2);
    EXPECT_EQ(output[0], "Hello");
    EXPECT_EQ(output[1], "World!");
}

DSVReader.cpp: 

#include "DSVReader.h"

struct CDSVReader::SImplementation {
    std::shared_ptr<CDataSource> DSource;
    char DDelimiter;

    SImplementation(std::shared_ptr<CDataSource> src, char delimiter)
        : DSource(src), DDelimiter(delimiter) {}

    bool End() const {
        return DSource->End();
    }

    bool ReadRow(std::vector<std::string> &row) {
        row.clear();
        std::string field;

        char ch;
        while (DSource->Get(ch)) {
            if (ch == DDelimiter) {
                row.push_back(field);
                field.clear();
            } else if (ch == '\n') {
                row.push_back(field);
                return true; // End of row
            } else {
                field += ch;
            }
        }

        if (!field.empty()) {
            row.push_back(field);
            return true; // End of row
        }

        return false; // End of file
    }
};

CDSVReader::CDSVReader(std::shared_ptr<CDataSource> src, char delimiter)
    : DImplementation(std::make_unique<SImplementation>(src, delimiter)) {}

CDSVReader::~CDSVReader() {}

bool CDSVReader::End() const {
    return DImplementation->End();
}

bool CDSVReader::ReadRow(std::vector<std::string> &row) {
    return DImplementation->ReadRow(row);
}

DataSource.h:

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <vector>

class CDataSource{
    public:
//ALL THESE FUNCTIONS MUST BE OVERRIDDEN (they are overridden in a CDataSource object in StringDataSource.h)
        virtual ~CDataSource(){};
        virtual bool End() const noexcept = 0; //Lets you know your at end of input
        virtual bool Get(char &ch) noexcept = 0;
        virtual bool Peek(char &ch) noexcept = 0; /*can get next char w/o pulling it out of source.. helpful for finding out if your at the end of 
        the string (what if there are double quotes?)*/
        virtual bool Read(std::vector<char> &buf, std::size_t count) noexcept = 0; //Give how many chars you want to read
        //helpful when doing xml reader
        
};

#endif


## Ans 7

Thank you for providing additional details. Given your constraint to avoid modifying `StringDataSource.h` and `StringDataSource.cpp`, and assuming `CStringDataSource` is correctly implemented in `StringDataSource.cpp`, let's make sure `DSVTest.cpp` and `DSVReader.cpp` are correctly using `CStringDataSource`. 

If `CStringDataSource` is implemented in `StringDataSource.cpp`, make sure to include the necessary header in `DSVTest.cpp`. Also, modify the Makefile to include `StringDataSource.o` when building `testdsv`. Here are the modifications:

### DSVTest.cpp:

```cpp
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "StringDataSource.h"  // Include the necessary header
#include "StringDataSink.h"
#include "DSVReader.h"
#include "DSVWriter.h"

// ...

```

### Makefile:

Add a rule to compile `StringDataSource.cpp`:

```make
$(OBJ_DIR)/StringDataSource.o: $(SRC_DIR)/StringDataSource.cpp $(INC_DIR)/StringDataSource.h $(INC_DIR)/DataSource.h
    $(CXX) -o $(OBJ_DIR)/StringDataSource.o -c $(CXXFLAGS) $(SRC_DIR)/StringDataSource.cpp
```

Include `StringDataSource.o` in the dependency list for `testdsv`:

```make
$(BIN_DIR)/testdsv: $(OBJ_DIR)/DSVReader.o $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/DSVTest.o                                                                                       
    $(CXX) -o $(BIN_DIR)/testdsv $(CXXFLAGS) $(OBJ_DIR)/DSVReader.o $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/DSVTest.o $(LDFLAGS)
```

These modifications ensure that `StringDataSource.cpp` is compiled and linked properly when building `testdsv`. If you encounter any issues, please let me know, and we can further refine the solution.

## Change 7

Added StringDataSource.h dependency to DSVTest in Makefile so that it could link CStringDataSource...
Makefile became functionally complete for DSVReader