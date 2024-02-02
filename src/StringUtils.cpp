#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    if (start < 0) {
        start = str.length() + start;
    }
    if (end <= 0){
        end = str.length() + end + 1;
    }
    return str.substr(start, end - start); 
}
}

/* std::string Capitalize(const std::string &str) noexcept{
    auto Copy = str;
    Copy[0] = toupper(str[0]);
    for(size_t Index = 1; Index < Copy.length(); Index++){
        Copy[Index] = tolower(Copy[Index]);
    }
    return Copy;
}

std::string Upper(const std::string &str) noexcept{
    auto Copy = str;
    for(size_t Index = 0; Index < Copy.length(); Index++) {
        Copy[Index] = toupper(Copy[Index]); }
    return Copy;
}

std::string Lower(const std::string &str) noexcept{
    auto Copy = str;
    for(size_t Index = 0; Index < Copy.length(); Index++) {
        Copy[Index] = tolower(Copy[Index]); }
    return "";
}

std::string LStrip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string RStrip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Strip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

}; */