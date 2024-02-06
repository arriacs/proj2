#include "XMLReader.h"
#include <expat.h>
#include <queue>
#include <string>
#include "XMLEntity.h"

// implementation of XML reader
struct CXMLReader::SImplementation {
    // datasource for XML reader
    std::shared_ptr< CDataSource > DDataSource;
    // XML parser for reading XML data
    XML_Parser DXMLParser;
    std::queue<SXMLEntity> DEntityQueue; // all entities stored in queue

    void StartElementHandler(const std::string &name, const std::vector<std::string> &attrs){
        SXMLEntity StartEntity;
        StartEntity.DNameData = name;
        StartEntity.DType = SXMLEntity::EType::StartElement;
        if (attrs.size() % 2 == 0) { // Ensure even number of attributes
            for (size_t Index = 0; Index < attrs.size(); Index += 2){
                StartEntity.SetAttribute(attrs[Index], attrs[Index + 1]);
            }
        }
        DEntityQueue.push(StartEntity);
    }

    void CharacterDataHandler(const std::string &data){
        SXMLEntity CharacterEntity;
        CharacterEntity.DNameData = data; // Assuming DNameData is used to store character data
        CharacterEntity.DType = SXMLEntity::EType::CharData;
        DEntityQueue.push(CharacterEntity);
    }

    void EndElementHandler(const std::string &name){
        SXMLEntity EndEntity;
        EndEntity.DNameData = name;
        EndEntity.DType = SXMLEntity::EType::EndElement;
        DEntityQueue.push(EndEntity);
    }

    static void StartElementHandlerCallback(void *context, const XML_Char *name, const XML_Char **atts){
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        std::vector<std::string> Attributes;
        for (const XML_Char **AttPtr = atts; *AttPtr != nullptr; AttPtr += 2){
            Attributes.push_back(*AttPtr);
            Attributes.push_back(*(AttPtr + 1));
        }
        ReaderObject->StartElementHandler(std::string(name), Attributes);
    }

    static void EndElementHandlerCallback(void *context, const XML_Char *name){
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        // Create an empty vector for attributes, as EndElement does not have attributes
        // std::vector<std::string> Attributes;
        ReaderObject->EndElementHandler(std::string(name));
    }


    static void CharacterDataHandlerCallback(void *context, const XML_Char *str, int len){
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        ReaderObject->CharacterDataHandler(std::string(str, len));
    }

    // class constructor
    SImplementation(std::shared_ptr< CDataSource > src){
        DDataSource = src;
        DXMLParser = XML_ParserCreate(NULL);
        XML_SetUserData(DXMLParser, this);
        XML_SetElementHandler(DXMLParser, StartElementHandlerCallback, EndElementHandlerCallback);
        XML_SetCharacterDataHandler(DXMLParser, CharacterDataHandlerCallback);
    }

    // class destructor
    ~SImplementation(){
        XML_ParserFree(DXMLParser);
    }

    // Returns true if all entities have been read from the XML
    bool End() const{
        return DDataSource->End() && DEntityQueue.empty();
    }

    // returns true if the entity is successfully read
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
}; //close struct SImplementation

// constructor for XML reader, src specifies the data source
CXMLReader::CXMLReader(std::shared_ptr< CDataSource > src){
    DImplementation = std::make_unique<SImplementation>(src);
}

// Destructor for XML reader
CXMLReader::~CXMLReader(){

}

bool CXMLReader::End() const{
    return DImplementation->End();
}

bool CXMLReader::ReadEntity(SXMLEntity &entity, bool skipcdata){
    return DImplementation->ReadEntity(entity, skipcdata);
}

 
