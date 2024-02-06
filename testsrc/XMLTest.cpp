#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "StringDataSink.h"
#include "StringDataSource.h"
#include "XMLReader.h"
#include "XMLWriter.h"

TEST(XMLReader, ReadStartElement) {
    std::string xml = "<example attr=\"Hello World\"></example>";
    auto dataSource = std::make_shared<CStringDataSource>(xml);
    CXMLReader reader(dataSource);
    SXMLEntity entity;

    EXPECT_TRUE(reader.ReadEntity(entity));
    EXPECT_EQ(entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(entity.AttributeValue("attr"), "Hello World");
}

TEST(XMLReader, ReadEndElement) {
    std::string xml = "</example>";
    auto dataSource = std::make_shared<CStringDataSource>(xml);
    CXMLReader reader(dataSource);
    SXMLEntity entity;

    EXPECT_TRUE(reader.ReadEntity(entity));
    EXPECT_EQ(entity.DType, SXMLEntity::EType::EndElement);
}

TEST(XMLReader, ReadCharData) {
    std::string xml = "Hello World";
    auto dataSource = std::make_shared<CStringDataSource>(xml);
    CXMLReader reader(dataSource);
    SXMLEntity entity;

    EXPECT_TRUE(reader.ReadEntity(entity));
    EXPECT_EQ(entity.DType, SXMLEntity::EType::CharData);
    EXPECT_EQ(entity.DNameData, "Hello World");
}

TEST(XMLReader, End) {
    std::string xml = "<example attr=\"Hello World\"></example>";
    auto dataSource = std::make_shared<CStringDataSource>(xml);
    CXMLReader reader(dataSource);
    SXMLEntity entity;

    EXPECT_TRUE(reader.ReadEntity(entity));
    EXPECT_EQ(entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(entity.AttributeValue("attr"), "Hello World");

    EXPECT_TRUE(reader.ReadEntity(entity));
    EXPECT_EQ(entity.DType, SXMLEntity::EType::EndElement);
}

TEST(XMLReader, ReadEntity) {
    auto InputStream = std::make_shared<CStringDataSource>("<example attr=\"Hello World\"></example>");
    CXMLReader Reader(InputStream);
    SXMLEntity E;

    EXPECT_TRUE(Reader.ReadEntity(E));
    EXPECT_EQ(E.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(E.AttributeValue("attr"), "Hello World");

    EXPECT_TRUE(Reader.ReadEntity(E));
    EXPECT_EQ(E.DType, SXMLEntity::EType::EndElement);
}

TEST(XMLWriter, Flush){
    auto OutputStream = std::make_shared<CStringDataSink>();
    CXMLWriter Writer(OutputStream);

    EXPECT_TRUE(Writer.Flush());
    EXPECT_EQ(OutputStream->String(), "");
}

TEST(XMLWriter, WriteEntity) {
    auto OutputStream = std::make_shared<CStringDataSink>();
    CXMLWriter Writer(OutputStream);

    EXPECT_TRUE(Writer.WriteEntity({SXMLEntity::EType::StartElement, "example", {{"attr","Hello World"}}}));
    EXPECT_TRUE(Writer.WriteEntity({SXMLEntity::EType::EndElement, "example", {}}));

    EXPECT_EQ(OutputStream->String(), "<example attr=\"Hello World\"></example>");
}