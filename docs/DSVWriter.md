struct CDSVWriter::SImplementation {
    std::shared_ptr<CDataSink> DSink;
    char DDelimiter;
    bool DQuoteAll;

    SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
        : DSink(sink), DDelimiter(delimiter), DQuoteAll(quoteall) {}
};



std::shared_ptr<CDataSink> sink: A shared pointer to a CDataSink object.


bool WriteRow(const std::vector<std::string> &row) 

Writes a row of data to a data sink given a specified delimiter.
1) First it checks if the shared pointer is pointing to a class object first (if it's valid or not), returning false if not.
2) 
Parameters: const std::vector<std::string> &row
    This parameter is a constant reference to a vector of strings
Return value: bool

