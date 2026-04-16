// ExtractorInitialization.h
#ifndef EXTRACTOR_INITIALIZATION_H
#define EXTRACTOR_INITIALIZATION_H

#include <string>
#include <istream>
#include <memory>

#include "Extractor.h"
#include "DigitsExtractor.h"
#include "NumbersExtractor.h"
#include "QuotesExtractor.h"

std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istream& lineIn) {
    if (extractType == "digits") {
        return std::make_shared<DigitsExtractor>(lineIn);
    }
    else if (extractType == "numbers") {
        return std::make_shared<NumbersExtractor>(lineIn);
    }
    else if (extractType == "quotes") {
        return std::make_shared<QuotesExtractor>(lineIn);
    }
    return nullptr;
}

#endif // EXTRACTOR_INITIALIZATION_H