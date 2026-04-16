// NumbersExtractor.h (SIMPLIFIED)
#ifndef NUMBERS_EXTRACTOR_H
#define NUMBERS_EXTRACTOR_H

#include "BufferedExtractor.h"
#include <cctype>

class NumbersExtractor : public BufferedExtractor {
protected:
    bool shouldBuffer(char symbol) override {
        return std::isdigit(symbol);
    }

public:
    NumbersExtractor(std::istream& stream) : BufferedExtractor(stream) {}
};

#endif // NUMBERS_EXTRACTOR_H