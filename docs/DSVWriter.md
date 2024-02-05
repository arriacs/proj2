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

Purpose: To write a string to an output sink (DSink), which is a shared pointer to a CDataSink object (and where the data will be stored).