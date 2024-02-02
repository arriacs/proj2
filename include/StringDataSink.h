#ifndef STRINGDATASINK_H
#define STRINGDATASINK_H

#include "DataSink.h"
#include <string>

class CStringDataSink : public CDataSink{
    private:
        std::string DString;
    public:
        const std::string &String() const; //can put chars into it and use this to find out what chars you put into it

        bool Put(const char &ch) noexcept override;
        bool Write(const std::vector<char> &buf) noexcept override;
};

#endif
