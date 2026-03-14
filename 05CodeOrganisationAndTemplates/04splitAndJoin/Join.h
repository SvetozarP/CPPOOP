#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <vector>
#include <sstream>


template <typename T>

std::string join(const std::vector<T>& elements, const std::string& joinStr) {
	std::ostringstream ss;

	bool first = true;

	for (size_t i = 0; i < elements.size(); i++) {
		
		if (i != elements.size()) {
			if (first) {
				first = false;
			}
			else {
				ss << joinStr;
			}
			ss << elements[i];
		}
	}
	return ss.str();
}



#endif // JOIN_H
