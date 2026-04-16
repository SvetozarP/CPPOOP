// QuotesExtractor.h
#ifndef QUOTES_EXTRACTOR_H
#define QUOTES_EXTRACTOR_H

#include "Extractor.h"
#include <sstream>

class QuotesExtractor : public Extractor {
private:
    std::ostringstream buffer;
    bool inQuote = false;

protected:
    bool process(char symbol, std::string& output) override {
        if (symbol == '"') {
            if (inQuote) {
                inQuote = false;
                if (!buffer.str().empty()) {
                    output = buffer.str();
                    buffer.str("");
                    buffer.clear();
                    return true;
                }
                output = "";
                return true;
            }
            else {
                inQuote = true;
                buffer.str("");
                buffer.clear();
                return false;
            }
        }
        else if (inQuote) {
            buffer << symbol;
            return false;
        }
        return false;
    }

public:
    QuotesExtractor(std::istream& stream) : Extractor(stream) {}
};

#endif // QUOTES_EXTRACTOR_H