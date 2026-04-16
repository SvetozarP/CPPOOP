// DigitsExtractor.h
#ifndef DIGITS_EXTRACTOR_H
#define DIGITS_EXTRACTOR_H

#include "Extractor.h"
#include <string>
#include <cctype>

class DigitsExtractor : public Extractor {
protected:
    bool process(char symbol, std::string& output) override {
        if (std::isdigit(symbol)) {
            output = std::string(1, symbol);
            return true;
        }
        return false;
    }

public:
    DigitsExtractor(std::istream& stream) : Extractor(stream) {}
};

#endif // DIGITS_EXTRACTOR_H