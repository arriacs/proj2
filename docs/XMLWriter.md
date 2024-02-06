##  SImplementation 
```cpp
struct CXMLWriter::SImplementation {}
```
- struct: create class SImplementation within the CXMLWriter class
## XML elements
```cpp
    std::shared_ptr< CDataSink > DDataSink;
    XML_Parser DXMLParser;
    std::queue<SXMLEntity> DEntityQueue; 
```
- datasink for XML reader
- XML parser for reading XML data
- all entities stored in queue


## class Constructor 
```cpp
    SImplementation(std::shared_ptr< CDataSink > sink){
        DDataSink = sink;
        DXMLParser = XML_ParserCreate(NULL);
        XML_SetUserData(DXMLParser, this);
    }
```
- focus on formatting SXMLEntity into XML string
- takes a shared pointer to a CDataSource object
- src specifies the data source and initializes data



## class Destructor 
```cpp
~SImplementation(){
    XML_ParserFree(DXMLParser);
}
```
- destructor to free XML_Parser

## Flush
```cpp
bool Flush(){
    while (!DEntityQueue.empty()){
        auto Entity = DEntityQueue.front();
        DEntityQueue.pop();
        if (!WriteEntity(Entity)){
            return false;
        }
    }
    return true;
}
```
- Outputs all end elements for those that have been started
- write outs all entities in DEntityQueue to the output stram
- if any entity fails than return false
- otherwise, return true


## WriteEntity
```cpp
bool WriteEntity(const SXMLEntity &entity){
    std::string EntityString;
    switch(entity.DType){
        //...
    }
    if (XML_Parse(DXMLParser, EntityString.c_str(), EntityString.length(), 1) != XML_STATUS_OK) {
        return false;
    }
    return true;
}
```
- takes a reference to SXMLEntity object (StartElement, EndElement, CharData, and CompleteElement) convert to string 
- writes it to the output stream
- if entity fails, then returns false
- otherwise, it returns true.

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
bool CXMLWriter::Flush(){
    return DImplementation->Flush();
};
```
- calls the Flush method on the SImplementation
```cpp
bool CXMLWriter::WriteEntity(const SXMLEntity &entity){
    return DImplementation->WriteEntity(entity);
};
```
- calls the WriteEntity method on the SImplementation, passing the SXMLEntity object