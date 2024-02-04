#include "DSVWriter.h"

struct CDSVWriter::SImplementation {
    SImplementation(std::shared_ptr< CDataSink > sink, char delimiter, bool quoteall) {
        //Details here
    }


    bool WriteRow(const std::vector<std::string> &row){
        //Details here
    }

};

CDSVWriter::CDSVWriter(std::shared_ptr < CDataSink > sink, char delimiter, bool quoteall){
    DImplementation(std::make_unique<SImplementation>(sink, delimiter ,quoteall));
}

CDSVWriter::~CDSVWriter(){

}

bool CDSVWriter::WriteRow(const std::vector<std::string> &row){
    return DImplementation->WriteRow(row);
}   

class CDSVWriter{
    private:
        struct SImplementation
        std::unique_ptr<SImplementation> DImplementation;

        public:
            CDSVWriter(std::shared_ptr< CDataSink > sink, char delimiter, bool quoteall = false);
            ~CDSVWriter();

            bool WriteRow(const std::vector<std::string> &row);
};

#endif
