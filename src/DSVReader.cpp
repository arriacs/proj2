#include "DSVReader.h"

struct CDSVReader::SImplementation { //SImp is a struct inside class CDSVReader
    std::shared_ptr<CDataSource> DSource; //member shared pointer DSource points to object CDataSource
    char DDelimiter;

//The shared pointer src is pointing to the bas class CDataSource, so in the future 
//it can point to any object of CDataSource... pointing to an object of CDataSource
    SImplementation(std::shared_ptr<CDataSource> src, char delimiter) 
        : DSource(src), DDelimiter(delimiter) {} //initialized member funcs of struct SImp

    bool End() const {
        return DSource->End();  //DSource takes pointer src which points to CDataSource
                                // DSource and src are shared pointers sharing ownership of CDataSource
    }
                                                 //&row means your working directly w/ the object, so no copies
    bool ReadRow(std::vector<std::string> &row) { //boolean return type with parameter of a dynamic array taking in a string type
        row.clear();     //removes all elements from vector referenced by 'row' (vector size would be 0)                    
        std::string field; //var field is a object of the string class, holding a dynamic array of chars

        char ch; //var char defined
        while (DSource->Get(ch)) { //DSource of type CDataSource is accessing the get func from Cdatasource
            if (ch == DDelimiter) { //if char is equal to the delimiter
                row.push_back(field); //add the field to the vector of strings (row)
                field.clear(); //clear those vars from the field since they've already been added
            } else if (ch == '\n') { // if char is a newline character
                row.push_back(field); //do the same thing
                return true; // End of row
            } else {
                field += ch; //append the char to the field string which holds the string of chars
            }
        }

        if (!field.empty()) { //if not empty
            row.push_back(field); //add the contents of field to row
            return true; // End of row
        }

        return false; // End of file, finished reading all chars
    }
};

CDSVReader::CDSVReader(std::shared_ptr<CDataSource> src, char delimiter)
    : DImplementation(std::make_unique<SImplementation>(src, delimiter)) {}

CDSVReader::~CDSVReader() {}

bool CDSVReader::End() const {
    return DImplementation->End();
}

bool CDSVReader::ReadRow(std::vector<std::string> &row) {
    return DImplementation->ReadRow(row); //return the read row (the actual reference, not a copy)
}




