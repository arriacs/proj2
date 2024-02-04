#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <vector>

class CDataSource{
    public:
//ALL THESE FUNCTIONS MUST BE OVERRIDDEN (they are overridden in a CDataSource object in StringDataSource.h)
        virtual ~CDataSource(){};
        virtual bool End() const noexcept = 0; //Lets you know your at end of input
        virtual bool Get(char &ch) noexcept = 0;
        virtual bool Peek(char &ch) noexcept = 0; /*can get next char w/o pulling it out of source.. helpful for finding out if your at the end of 
        the string (what if there are double quotes?)*/
        virtual bool Read(std::vector<char> &buf, std::size_t count) noexcept = 0; //Give how many chars you want to read
        //helpful when doing xml reader
        
};

#endif
