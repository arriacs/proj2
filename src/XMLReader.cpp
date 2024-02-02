#include "XMLReader.h"
#include <expat.h>
#include <queue>


struct CXMLReader::SImplementation{
    std::shared_ptr< CDataSource >DDateSource;
    XML_Parser DXMLParser;
    std::queue<SXMLEntity> DEntityQueue;

    void StartElementHandler(const std::string &name, const std::string> &atts){
        SXMLEntity TempEntity;
        TempEntity.DNameData = name;
        TempEntity.DType = SXMLEntity::EType::Element;
        for (size_t Index = 0; Index <attrs.size(); Index += 2){ 
            //why 2? bc the first is the name and the second is the value
            TempEntity.DAttributes[attrs[Index]] = attrs[Index + 1]; //+1 is for the value
        }
    };

    void EndElementHandler(const std::string &name, const std::string> &atts){
        // Details here
    };

    void CharacterDataHandler(const std::string &data){
        // check the back entity is the character data 
    };


    static void StartElementHandlerCallback(void *context, const XML_Char *name, const XML_Char **atts){
        // what type the data is?
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        std::vector<std::string>Attributes;
        auto AttrPtr = atts;
        while (*AttrPtr){
            Attributes.push_back(*AttrPtr);
            AttrPtr++;
        }
        ReaderObject->StartElementHandler(name, Attributes);
    };

    static void EndElementHandlerCallback(void *context, const XML_Char *name){
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        ReaderObject->EndElementHandler(name);
    };

    static void CharacterDataHandlerCallback(void *context, const XML_Char *str, int len){
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        ReaderObject->CharacterDataHandler(std::string(str, len));
    };

    SImplementation(std::shared_ptr< CDataSource > src){
        DDataScource = src; //read data
        DXMLParser = XML_ParserCreate(NULL); //creare parser
        XML_SetStartElementHandler(DXMLParser, StartElementHandlerCallback);
        XML_SetEndElementHandler(DXMLParser, EndElementHandlerCallback);
        XML_SetCharacterDataHandler(DXMLParser, CharacterDataHandlerCallback);
        XML_SetUserData(DXMLParser, this); //
    };

    bool End() const{
        // Details here 
    };

    bool ReadEntity(SXMLEntity &entity, bool skipcdata){
        // Reader from scource of necessary
        // pass to XML_Parse fuction
        // return entity
        std::vector<char> DataBuffer:
        while (DEntityQueue.empty(){
            if (DDateSource->Read(DataBuffer, 256)){
                XML_Parse(DXMLParser, DataBuffer.data(), DataBuffer.size(), DataBuffer.size()<256);
            }
            else{
                XML_Parse(DXMLParser, DataBuffer.data(), 0, true);
            }
        }
        if(DEntityQueue.empty()){
            return false;
        }
        entity = DEntityQueue.front(); //if the front is emtpy then pop the front
        DEntity.pop();
        return true;
    }
}

CXMLReader::CXMLReader(std::shared_ptr< CDataSource > src){
    DImplementation(std::make_unique<SImplementation>(src));
}

CXMLReader::~CXMLReader(){

}

bool CXMLReader::End() const{
    // return DImplementation->End();
}

bool CXMLReader::ReadEntity(SXMLEntity &entity, bool skipcdata){
    // return DImplementation->ReadEntity(entity, skipcdata);
}

 
