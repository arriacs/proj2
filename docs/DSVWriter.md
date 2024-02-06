struct CDSVWriter::SImplementation {
    std::shared_ptr<CDataSink> DSink;
    char DDelimiter;
    bool DQuoteAll;

    SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
        : DSink(sink), DDelimiter(delimiter), DQuoteAll(quoteall) {}
};


## sink
std::shared_ptr<CDataSink> sink: A shared pointer to a CDataSink object.

## WriteRow() 
bool WriteRow(const std::vector<std::string> &row) 

Writes a row of data to a data sink given a specified delimiter.
1) First it checks if the shared pointer is pointing to a class object first (if it's valid or not), returning false if not.
2) initializes an iterator to the beginning of an input vector ('row' in this case),
calling a function (that is defined later) that writes the element.
3) Uses a for loop to iterate through the row and use the Put() function to apply a delimiter (DDelimiter) to the input, separating each field in the row.
4) Returns true if successful
Parameters: const std::vector<std::string> &row
    This parameter is a constant reference to a vector of strings
Return value: bool

## WriteField()
 void WriteField(const std::string &field)

Purpose: To write a string (field) to an output sink (DSink), which is a shared pointer to a CDataSink object (and where the data will be stored). It also handles nuanced special cases with certain char's.

1) if (DQuoteAll || field.find(DDelimiter) != std::string::npos || field.find('"') != std::string::npos || field.find('\n') != std::string::npos) 

If any of the above conditions are met, the field needs to be quoted.
If quoting is required, the func starts by putting a double quote into the data sink (DSink). A

A 'for' loop is then called, checking if additional quotations are run into. If they are double quotes are added to the sink. The purpose is not to confuse a double quote describing the beginning or ending of the string, but recognize that it is part of the input.

A closing quote is added into the data sink to end the process.

2) Else statement

Purpose: used when input doesn't require quoting
A vector is created by copying the characters from the field string using the begin() and end() functions.
The Write function is called to write the vector to DSink.

## Constructor CDSVWriter
CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
    : DImplementation(std::make_unique<SImplementation>(sink, delimiter, quoteall)) {}

Purpose: Create an instance of SImplementation as to leave this stuct untouched