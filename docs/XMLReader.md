##  SImplementation 
```cpp
struct CXMLReader::SImplementation{
    std::shared_ptr< CDataSource > DDataSource;
    XML_Parser DXMLParser;
    std::queue<SXMLEntity> DEntityQueue; 
}; 
```
- struct: create class SImplementation within the CXMLReader class
- datasource for XML reader
-  XML parser for reading XML data
- all entities stored in queue

## XML elements
StartElementHandler, EndElementHandler, and CharacterDataHandler
- create an SXMLEntity as run data and push it onto DEntityQueue respectively

## static methods 
StartElementHandlerCallback, EndElementHandlerCallback, and CharacterDataHandlerCallback
- callbacks for the Expat library when run XML elements

## class Constructor 
```cpp
    SImplementation(std::shared_ptr< CDataSource > src){
        DDataSource = src;
        DXMLParser = XML_ParserCreate(NULL);
        XML_SetUserData(DXMLParser, this);
        XML_SetElementHandler(DXMLParser, StartElementHandlerCallback, EndElementHandlerCallback);
        XML_SetCharacterDataHandler(DXMLParser, CharacterDataHandlerCallback);
    }
```
- takes a shared pointer to a CDataSource object
- src specifies the data source and initializes data
- creates an XML_Parser, and sets the user data of the XML_Parser to the SImplementation and the  element and character data handlers to the corresponding callback methods.

## class Destructor 
```cpp
~SImplementation(){
        XML_ParserFree(DXMLParser);
    }
```
- destructor to free XML_Parser

## End 
```cpp
bool End() const{
    return DDataSource->End() && DEntityQueue.empty();
}
```
 - returns true if all entities have been read from the XML
 - wait and later call outside struct

## ReadEntity
- returns true if the entity is successfully read
```cpp
bool ReadEntity(SXMLEntity &entity, bool skipcdata = false){
        std::vector<char> DataBuffer(256);
        while (DEntityQueue.empty()){
            if (DDataSource->Read(DataBuffer, 256)){
                if (!XML_Parse(DXMLParser, DataBuffer.data(), DataBuffer.size(), false)){
                    return false;
                }
            }
            else{
                XML_Parse(DXMLParser, DataBuffer.data(), 0, true);
            }
        }
        if (DEntityQueue.empty()){
            return false;
        }
        entity = DEntityQueue.front();
        DEntityQueue.pop();
        return true;
    }
```
- creates a vector of characters with a size of 256 (a buffer to read data from the data source)
- creates while loop continues as long as the entity queue is empty
    - reads data from the data source into the data buffer
        - parses the data that was read into the data buffer. If the parse operation fails, it returns false
    - if there is no more data to read then finalizes the parsing operation
- if the entity queue is still empty after read and parse data, then returns false, which means there's no entity could be read
- if sucess read then remove from queue and stored in SXMLEntity
- wait and later call outside struct

## interface of class
```cpp
CXMLWriter::CXMLWriter(std::shared_ptr< CDataSink > sink){
    DImplementation = std::make_unique<SImplementation>(sink);
};
```
- takes a shared pointer to a CDataSink object 
    - create DImplementation as unique pointer to SImplementation object to pass sink

```cpp
CXMLWriter::~CXMLWriter(){
};
```
- do nothing, but when a CXMLWriter object is destroyed, the DImplementation unique pointer will automatically be deleted, which means the SImplementation object is deleted as well

```cpp
bool Flush(){
    return DImplementation->Flush();
};
```
- calls the Flush method on the SImplementation

```cpp
bool WriteEntity(const SXMLEntity &entity){
    return DImplementation->WriteEntity(entity);
};
```
- calls the WriteEntity method on the SImplementation, passing the SXMLEntity object 