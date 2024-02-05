#include "StringUtils.h"

namespace StringUtils{

//Returns a substring of the string str, allows for negative values
std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    // if start negative, it adds the size of the string to start
    if (start < 0){
        start = str.size() + start;
    }
    // if end negative, it adds the size of the string to end
    if (end < 0){
        end = str.size() + end;
    }
    // if end is 0, it sets end to the size of the string
    if (end == 0){
        end = str.size();
    }
    // if start equal end, return empty string
    if (start == end){
        return "";
    }
    // if start is greater than end, return empty string
    if (start > end){
        return "";
    }
    return str.substr(start, end - start);
};

// Returns the Capitalized string
std::string Capitalize(const std::string &str) noexcept{
    if (str.size() > 0){
        std::string temp = str;
        temp[0] = toupper(temp[0]);
        return temp;
    }
    return "";
};

std::string Upper(const std::string &str) noexcept{
    if (str.size() > 0){
        std::string temp = str;
        for (size_t i = 0; i < temp.size(); i++){
            temp[i] = toupper(temp[i]);
        }
        return temp;
    }
    return "";
};

std::string Lower(const std::string &str) noexcept{
    if (str.size() > 0){
        std::string temp = str;
        for (size_t i = 0; i < temp.size(); i++){
            temp[i] = tolower(temp[i]);
        }
        return temp;
    }
    return "";
};

// Returns the left/right/both stripped strings 
// (white space characters are removed from left, right or both)
std::string LStrip(const std::string &str) noexcept{
    if (str.size() > 0){
        size_t i = 0;
        while (i < str.size() && isspace(str[i])){
            i++;
        }
        return str.substr(i);
    }
    return "";
};

std::string RStrip(const std::string &str) noexcept{
    if (str.size() > 0){
        size_t i = str.size() - 1;
        while (i > 0 && isspace(str[i])){
            i--;
        }
        return str.substr(0, i + 1);
    }
    return "";
};

std::string Strip(const std::string &str) noexcept{
    if (str.size() > 0){
        size_t i = 0;
        size_t j = str.size() - 1;
        while (i < str.size() && isspace(str[i])){
            i++;
        }
        while (j > 0 && isspace(str[j])){
            j--;
        }
        return str.substr(i, j - i + 1);
    }
    return "";
};

// // Returns the center/left/right justified strings
// std::string Center(const std::string &str, int width, char fill) noexcept{
//     if (str.size() > 0){
//         std::string temp = str;
//         if (width > temp.size()){
//             int left = (width - temp.size()) / 2;
//             int right = width - temp.size() - left;
//             temp = std::string(left, fill) + temp + std::string(right, fill);
//         }
//         return temp;
//     }
//     return "";
// };

// std::string LJust(const std::string &str, int width, char fill) noexcept{
//     if (str.size() > 0){
//         std::string temp = str;
//         if (width > temp.size()){
//             temp = temp + std::string(width - temp.size(), fill);
//         }
//         return temp;
//     }
//     return "";
// };

// std::string RJust(const std::string &str, int width, char fill) noexcept{
//     if (str.size() > 0){
//         std::string temp = str;
//         if (width > temp.size()){
//             temp = std::string(width - temp.size(), fill) + temp;
//         }
//         return temp;
//     }
//     return "";
// };

// Returns the string str with all instances of old replaced with rep
std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    if (str.size() > 0){
        std::string temp = str;
        size_t pos = 0;
        while ((pos = temp.find(old, pos)) != std::string::npos){
            temp.replace(pos, old.size(), rep);
            pos += rep.size();
        }
        return temp;
    }
    return "";
};

// Splits the string up into a vector of strings based on splt parameter, if
// splt parameter is empty string, then split on white space
std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    if (str.size() > 0){
        std::vector<std::string> temp;
        size_t pos = 0;
        size_t start = 0;
        while ((pos = str.find(splt, start)) != std::string::npos){
            temp.push_back(str.substr(start, pos - start));
            start = pos + splt.size();
        }
        temp.push_back(str.substr(start));
        return temp;
    }
    return {};
};

// Joins a vector of strings into a single string
std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    if (vect.size() > 0){
        std::string temp = vect[0];
        for (size_t i = 1; i < vect.size(); i++){
            temp += str + vect[i];
        }
        return temp;
    }
    return "";
};

// Replaces tabs with spaces aligning at the tabstops
std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string temp = str;
    size_t pos = 0;
    while ((pos = temp.find('\t', pos)) != std::string::npos){
        temp.replace(pos, 1, "    ");
    }
    return temp;
};

/*
// Calculates the Levenshtein distance (edit distance) between the two strings.
int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
std::vector< std::vector< int > > Distances(left.size() + 1, std::vector< int >(right.size() + 1, 0));
    for (size_t LIndex = 0; LIndex <= left.size(); LIndex++){
        Distances[LIndex][0] = LIndex;
    }
    for (size_t RIndex = 0; RIndex <= right.size(); RIndex++){
        Distances[0][RIndex] = RIndex;
    }
    for (size_t LIndex = 1; LIndex <= left.size(); LIndex++){
        for (size_t RIndex = 1; RIndex <= right.size(); RIndex++){
            int AddCost = Distances[LIndex - 1][RIndex] + 1;
            int DelCost = Distances[LIndex][RIndex - 1] + 1;
            int SubCost = Distances[LIndex - 1][RIndex - 1] + (left[LIndex - 1] == right[RIndex - 1] ? 0 : 1);
            Distances[LIndex][RIndex] = std::min(std::min(AddCost, DelCost), SubCost);
        }
    }
    return Distances[left.size()][right.size()];
};
*/
};