#include "StringDataSink.h"

const std::string &CStringDataSink::String() const{
    return DString;
}

bool CStringDataSink::Put(const char &ch) noexcept{
    DString += std::string(1,ch);
    return true;
}
// Returns true if the row is successfully written, one string per column
// should be put in the row vector
bool CStringDataSink::Write(const std::vector<char> &buf) noexcept{
    DString += std::string(buf.data(),buf.size());
    return true;
}
