#include "XMLWriter.h"
#include <expat.h>
#include <queue>
#include <string>
#include "XMLEntity.h"
#include "DataSink.h"

struct CXMLWriter::SImplementation {
    // datasource for XML writer
    std::shared_ptr< CDataSink > DDataSink;
    // XML parser for writing XML data
    XML_Parser DXMLParser;
    std::queue<SXMLEntity> DEntityQueue; // all entities stored in queue

    // class constructor, focus on formatting SXMLEntity into XML string
    SImplementation(std::shared_ptr< CDataSink > sink){
        DDataSink = sink;
        DXMLParser = XML_ParserCreate(NULL);
        XML_SetUserData(DXMLParser, this);
    }

    // class destructor
    ~SImplementation(){
        XML_ParserFree(DXMLParser);
    }
    
    // Outputs all end elements for those that have been started
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
    
    // Writes out the entity to the output stream
    bool WriteEntity(const SXMLEntity &entity){
        std::string EntityString;
        switch(entity.DType){
            case SXMLEntity::EType::StartElement:
                //the start element with attributes
                EntityString = "<" + entity.DNameData;
                for (auto &Attribute : entity.DAttributes){
                    EntityString += " " + Attribute.first + "=\"" + Attribute.second + "\"";
                }
                EntityString += ">";
                break;
            case SXMLEntity::EType::EndElement:
                //the end element
                EntityString = "</" + entity.DNameData + ">";
                break;
            case SXMLEntity::EType::CharData:
                //the character data
                EntityString = entity.DNameData;
                break;
        }
        // Write EntityString to output
        if (XML_Parse(DXMLParser, EntityString.c_str(), EntityString.length(), 1) != XML_STATUS_OK) {
            // Handle parsing error
            return false;
        }
        return true;
    }

}; //close struct SImplementation

// Constructor for XML writer, sink specifies the data destination
CXMLWriter::CXMLWriter(std::shared_ptr< CDataSink > sink){
    DImplementation = std::make_unique<SImplementation>(sink);
};

// Destructor for XML writer
CXMLWriter::~CXMLWriter(){

};

// call flush method implementation
bool CXMLWriter::Flush(){
    return DImplementation->Flush();
};

// call write entity method implementation
bool CXMLWriter::WriteEntity(const SXMLEntity &entity){
    return DImplementation->WriteEntity(entity);
};


