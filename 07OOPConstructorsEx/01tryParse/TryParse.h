#pragma once
#include <sstream>

class Parser {

	bool success;
	int value;

public:

	Parser(const std::string& str) {
		std::istringstream istr(str);
		istr >> value;
		this->success = !istr.fail() && istr.eof();
	};

	int getValue() const {
		return value;
	}

	bool hasSucceeded() const {
		return success;
	}
	

};


bool tryParse(const std::string& str, int& value) {

	Parser parser(str);

	value = parser.getValue();

	return parser.hasSucceeded();

}

