#include "DSVReader.h"

struct CDSVReader::SImplementation {
    std::shared_ptr<CDataSource> DSource;
    char DDelimiter;

    SImplementation(std::shared_ptr<CDataSource> src, char delimiter)
        : DSource(src), DDelimiter(delimiter) {}

    bool End() const {
        return DSource->End();
    }

    bool ReadRow(std::vector<std::string> &row) {
        row.clear();
        std::string field;

        char ch;
        while (DSource->Get(ch)) {
            if (ch == DDelimiter) {
                row.push_back(field);
                field.clear();
            } else if (ch == '\n') {
                row.push_back(field);
                return true; // End of row
            } else {
                field += ch;
            }
        }

        if (!field.empty()) {
            row.push_back(field);
            return true; // End of row
        }

        return false; // End of file
    }
};

CDSVReader::CDSVReader(std::shared_ptr<CDataSource> src, char delimiter)
    : DImplementation(std::make_unique<SImplementation>(src, delimiter)) {}

CDSVReader::~CDSVReader() {}

bool CDSVReader::End() const {
    return DImplementation->End();
}

bool CDSVReader::ReadRow(std::vector<std::string> &row) {
    return DImplementation->ReadRow(row);
}
