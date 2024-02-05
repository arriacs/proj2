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