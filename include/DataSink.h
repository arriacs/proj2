#ifndef DATASINK_H
#define DATASINK_H

#include <vector>
//Doesn't provide a func to check if smth is written to the sink
class CDataSink{
    public:
        virtual ~CDataSink(){};
        virtual bool Put(const char &ch) noexcept = 0;
        virtual bool Write(const std::vector<char> &buf) noexcept = 0;
};

#endif
