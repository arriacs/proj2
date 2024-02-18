//implement this one first

#ifndef DSVWRITER_H
#define DSVWRITER_H

#include <memory>
#include <string>
#include "DataSink.h"

class CDSVWriter{
    private: //data members
        struct SImplementation; //forward declaration
        std::unique_ptr<SImplementation> DImplementation; //unique_ptr keeps track of object, where only 1 thing can 
        //point to implementation. Pointer is pointing to your actual code... user only knows that (can't see actual code)

    public:
        CDSVWriter(std::shared_ptr< CDataSink > sink, char delimiter, bool quoteall = false);
        ~CDSVWriter();

        bool WriteRow(const std::vector<std::string> &row);
};

#endif
