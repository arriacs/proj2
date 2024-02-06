#include "DSVWriter.h"

struct CDSVWriter::SImplementation {
    std::shared_ptr<CDataSink> DSink;
    char DDelimiter;
    bool DQuoteAll; //bool flag

//initializes above var's w provided args
    SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
        : DSink(sink), DDelimiter(delimiter), DQuoteAll(quoteall) {}

//Writes row of data to data sink
    bool WriteRow(const std::vector<std::string> &row) {
        if (!DSink) { //if no class obj
            return false;
        }

        auto it = row.begin(); //initializes iterator 'it' to beg of input vect 'row'
        if (it != row.end()) {
            WriteField(*it); //if not at end of line, WriteField func writes the element
            ++it; //inc iterator
        }

        for (; it != row.end(); ++it) { //empty init statement, it has already been declared
            DSink->Put(DDelimiter); //uses Put() to apply delim to input
            WriteField(*it); //separating each field in the row
        }

        return true; //func was successful
    }

private: //writes a single field (string) to data sink
    void WriteField(const std::string &field) {
        if (DQuoteAll || field.find(DDelimiter) != std::string::npos || field.find('"') != std::string::npos || field.find('\n') != std::string::npos) {
            DSink->Put('"');
            for (char ch : field) {
                if (ch == '"') {
                    DSink->Put('"');
                }
                DSink->Put(ch);
            }
            DSink->Put('"');
        } else {
            // Change to use Write with std::vector<char> by converting string to vector<char>
            std::vector<char> fieldVector(field.begin(), field.end());
            DSink->Write(fieldVector);
        }
    }
};

CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
    : DImplementation(std::make_unique<SImplementation>(sink, delimiter, quoteall)) {}

CDSVWriter::~CDSVWriter() {}

bool CDSVWriter::WriteRow(const std::vector<std::string> &row) {
    return DImplementation->WriteRow(row);
}



// struct CDSVWriter::SImplementation {
//     SImplementation(std::shared_ptr< CDataSink > sink, char delimiter, bool quoteall) {
       
//     }


//     bool WriteRow(const std::vector<std::string> &row){
//         //Details here
//     }

// };

// CDSVWriter::CDSVWriter(std::shared_ptr < CDataSink > sink, char delimiter, bool quoteall){
//     DImplementation(std::make_unique<SImplementation>(sink, delimiter ,quoteall));
// }

// CDSVWriter::~CDSVWriter(){

// }

// bool CDSVWriter::WriteRow(const std::vector<std::string> &row){
//     return DImplementation->WriteRow(row);
// }   

// class CDSVWriter{
//     private:
//         struct SImplementation
//         std::unique_ptr<SImplementation> DImplementation;

//         public:
//             CDSVWriter(std::shared_ptr< CDataSink > sink, char delimiter, bool quoteall = false);
//             ~CDSVWriter();

//             bool WriteRow(const std::vector<std::string> &row);
// };

// #endif