#include "StringDataSource.h"
//Implementations of get, peek, etc from class CStringDataSource in StringDataSource.h

//initializing members of constructor from CStringDdataSource
CStringDataSource::CStringDataSource(const std::string &str) : DString(str), DIndex(0){ 

}
// Returns true if all rows have been read from the DSV
//Double colon "::" used bc we want to use End(), which has already been initialized,
// so it's out of scope. We access it through the double colon.
bool CStringDataSource::End() const noexcept{
    return DIndex >= DString.length();
}

bool CStringDataSource::Get(char &ch) noexcept{
    if(DIndex < DString.length()){
        ch = DString[DIndex];
        DIndex++;
        return true;
    }
    return false;
}

bool CStringDataSource::Peek(char &ch) noexcept{
    if(DIndex < DString.length()){
        ch = DString[DIndex]; //Peek won't advance to the next character here unless incremented.
        return true;
    }
    return false;
}
// Returns true if the row is successfully read, one string will be put in
// the row per column
bool CStringDataSource::Read(std::vector<char> &buf, std::size_t count) noexcept{
    buf.clear();
    while(buf.size() < count){
        char TempChar;
        if(Get(TempChar)){
            buf.push_back(TempChar);
        }
        else{
            break;
        }
    }
    return !buf.empty();
}
