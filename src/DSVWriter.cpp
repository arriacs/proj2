#include "DSVWriter.h"

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


// DSVWriter.cpp


struct CDSVWriter::SImplementation {
    std::shared_ptr<CDataSink> DSink;
    char DDelimiter;
    bool DQuoteAll;

    SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
        : DSink(sink), DDelimiter(delimiter), DQuoteAll(quoteall) {}

    bool WriteRow(const std::vector<std::string> &row) {
        if (!DSink) {
            return false;
        }

        auto it = row.begin();
        if (it != row.end()) {
            WriteField(*it);
            ++it;
        }

        for (; it != row.end(); ++it) {
            DSink->Put(DDelimiter);
            WriteField(*it);
        }

        // Remove the newline character here
        // DSink->Put('\n');

        return true;
    }

private:
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



