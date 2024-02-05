#include "DSVWriter.h"
#include "StringDataSink.h"
#include <iostream>

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

struct CDSVWriter::SImplementation {
    std::shared_ptr<CDataSink> DSink;
    char DDelimiter;
    bool DQuoteAll;

    SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteAll)
        : DSink(sink), DDelimiter(delimiter), DQuoteAll(quoteAll) {}

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
            DSink->Write({field.begin(), field.end()});
        }
    }
};

CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteAll)
    : DImplementation(std::make_unique<SImplementation>(sink, delimiter, quoteAll)) {}

CDSVWriter::~CDSVWriter() {}

bool CDSVWriter::WriteRow(const std::vector<std::string> &row) {
    if (!DImplementation->DSink) {
        return false;
    }

    auto it = row.begin();
    if (it != row.end()) {
        DImplementation->WriteField(*it);
        ++it;
    }

    for (; it != row.end(); ++it) {
        DImplementation->DSink->Put(DImplementation->DDelimiter);
        DImplementation->WriteField(*it);
    }

    DImplementation->DSink->Put('\n');
    return true;
}
