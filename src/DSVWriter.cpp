#include "DSVWriter.h"

struct CDSVWriter::SImplementation {
    std::shared_ptr<CDataSink> DSink; //shared pointer DSink of type CDataSink
    char DDelimiter;
    bool DQuoteAll; //bool flag, if everything is in quotes or not

//initializes above var's w provided args
    SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
        : DSink(sink), DDelimiter(delimiter), DQuoteAll(quoteall) {}

//Writes row of data to data sink
    bool WriteRow(const std::vector<std::string> &row) { //takes the row read from ReadRow
        if (!DSink) { //if no class obj
            return false;
        }

        auto it = row.begin(); //initializes iterator 'it' to beg of input vect 'row' from ReadRow
        if (it != row.end()) { //writing row to the sink Writefield
            WriteField(*it); //if not at end of line, WriteField takes the it variable which contains the row string
            ++it; //inc iterator
        }

        for (; it != row.end(); ++it) { //empty init statement, it has already been declared
            DSink->Put(DDelimiter); //uses Put() to apply delim to input
            WriteField(*it); //separating each field in the row
        }

        return true; //func was successful
    }

private: //writes a single field (string) to data sink
    void WriteField(const std::string &field) { //refernce to field (actual object, not copy) //npos = position in the string
        if (DQuoteAll || field.find(DDelimiter) != std::string::npos || field.find('"') != std::string::npos || field.find('\n') != std::string::npos) {
            DSink->Put('"');
            for (char ch : field) {
                if (ch == '"') {
                    DSink->Put('"'); //put quotes around char's in the field if it's the double quote char
                }
                DSink->Put(ch); //put char in DSink
            }
            DSink->Put('"'); //second quote encapsulating the ch double quote
        } else {
            // Change to use Write with std::vector<char> by converting string to vector<char>
            std::vector<char> fieldVector(field.begin(), field.end());
            DSink->Write(fieldVector); //write data from field to fieldVector, which is of the vector class (Dsink accesses the Write() func)
        }
    }
};

CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall) //constructor of CDSVWriter
    : DImplementation(std::make_unique<SImplementation>(sink, delimiter, quoteall)) {} //DImp takes a unique pointer of type struct SImp

CDSVWriter::~CDSVWriter() {} //Decstructor

bool CDSVWriter::WriteRow(const std::vector<std::string> &row) { //row as parameter
    return DImplementation->WriteRow(row); //return row which is passed into WriteRow func()
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