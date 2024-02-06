## SImplementation
SImplementation(std::shared_ptr<CDataSource> src, char delimiter)
        : DSource(src), DDelimiter(delimiter) {}
-Constructor which initializes the data source and delimiter

## ReadRow
bool ReadRow(std::vector<std::string> &row)

Purpose: Reads from the data source into a vector of strings

1) row.clear()
   std::string field;
-Clears the output vector and prepares a string field

2) The while loop goes through the char's in the source, accomodating for running into a delimiter, newline, the end of the row. If there's no delimiter, it adds the char to the current field.

3) if (!field.empty()) {
    row.push_back(field); 
    return true;          
    }
-Checks to see if the field is empty (if there's any data)
-If so, the content of the field string is added to the row vector

4) Return false to indicate EOF

## CDSVReader Constructor

CDSVReader::CDSVReader(std::shared_ptr<CDataSource> src, char delimiter)
    : DImplementation(std::make_unique<SImplementation>(src, delimiter)) {}

-Contains member intializer list where DImple. is an instance of SImp. to work with the PIMPL technique