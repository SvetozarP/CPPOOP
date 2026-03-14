#ifndef PARSER_H
#define PARSER_H

#include <sstream>


template <typename T>
class Parser
{

	std::istream& in;
	std::string stopLine;

public:

	Parser(std::istream & in, const std::string stopLine) : in(in), stopLine(stopLine) {}

	bool readNext(T& t) {

		std::string line;
		std::getline(in, line);

		if (line == stopLine) {
			return false;
		}

		std::istringstream iss(line);
		return (iss >> t) ? true : false;
	}

};

#endif // PARSER_H
