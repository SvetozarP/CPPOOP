#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string>& operator<<(std::vector<std::string>& lines, const std::string& line) {
	lines.push_back(line);
	return lines;
}

std::string operator+(const std::string& str, int num) {
	std::ostringstream oss;
	oss << str << num;
	return oss.str();
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& lines) {
	for (const auto& line : lines) {
		os << line << '\n';
	}
	return os;
}

#endif // !OPERATORS_H
