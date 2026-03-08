#include <iostream>
#include <string>
#include <vector>

#include "Defines.h"

class Parser {

    const std::string& commands;
    const char* rawDataBytes;
    const size_t rawDataBytesCount;
    std::vector<long long>& outParsedNumbers;
    const char* nextData;

public:

    Parser(
        const std::string& commands,
        const char* rawDataBytes,
        const size_t rawDataBytesCount,
        std::vector<long long>& outParsedNumbers
    ) : commands(commands),
        rawDataBytes(rawDataBytes),
        rawDataBytesCount(rawDataBytesCount),
        outParsedNumbers(outParsedNumbers),
		nextData(rawDataBytes)
    {}

    ErrorCode parse() {
        if (rawDataBytesCount == 0 || commands.size() == 0) {
            return ErrorCode::PARSE_EMPTY;
		}

		for (char c : commands) {
            switch (c) {
            case 's':
                if (!parseShort())
					return ErrorCode::PARSE_FAILURE;
                break;
			case 'i':
                if (!parseInt())
					return ErrorCode::PARSE_FAILURE;
				break;
			case 'l':
                if (!parseLong())
					return ErrorCode::PARSE_FAILURE;
                break;
            default:
				return ErrorCode::PARSE_FAILURE;
            }
        }

		return ErrorCode::PARSE_SUCCESS;
	}

private:

    size_t remainingBytes() const {
		size_t eatenBytes = nextData - rawDataBytes;
		if (eatenBytes >= rawDataBytesCount) {
            return 0;
        }

		return rawDataBytesCount - eatenBytes;
	}

    bool parseShort() {
		if (remainingBytes() < 2) { // sizeof(short) is 2 bytes
            return false;
        }

        short s = *((short*)nextData);

		nextData += 2; // Move the pointer forward by the size of short
		outParsedNumbers.push_back(s);
        return true;
	}

    bool parseInt() {
		if (remainingBytes() < 4) { // sizeof(int) is 4 bytes
            return false;
        }

		int i = *((int*)nextData);
        nextData += 4; // Move the pointer forward by the size of int
        outParsedNumbers.push_back(i);
        return true;
    }

    bool parseLong() {
		if (remainingBytes() < 8) { // sizeof(long long) is 8 bytes
            return false;
        }

        long long ll = *((long long *)nextData);
        nextData += 8; // Move the pointer forward by the size of long long
        outParsedNumbers.push_back(ll);
        return true;
	}

};



ErrorCode parseData(const std::string& commands,
    const char* rawDataBytes,
    const size_t	   	     rawDataBytesCount,
    std::vector<long long>& outParsedNumbers)

{
	Parser parser(commands, rawDataBytes, rawDataBytesCount, outParsedNumbers);
    return parser.parse();
}

void printResult(const ErrorCode                errorCode,
    const std::vector<long long>& parsedNumbers)
{
    if (errorCode == ErrorCode::PARSE_EMPTY)
    {
        std::cout << "No input provided" << std::endl;
        return;
    }

    for(auto l: parsedNumbers)
    {
        std::cout << l << " ";
	}

    if (errorCode == ErrorCode::PARSE_FAILURE)
    {
        std::cout << "Warning, buffer underflow detected" << std::endl;
    }
	std::cout << std::endl;
    
}