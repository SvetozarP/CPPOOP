#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> operator+(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
	std::vector<std::string> vecResult;

	size_t len = vec1.size() > vec2.size() ? vec1.size() : vec2.size();
	vecResult.reserve(len);

	for (int i = 0; i < len; i++)
	{
		std::ostringstream ostr;

		if (i < vec1.size())
		{
			ostr << vec1[i];
		}
		if (i < vec1.size() && i < vec2.size())
		{
			ostr << " ";
		}
		if (i < vec2.size())
		{
			ostr << vec2[i];
		}

		vecResult.push_back(ostr.str());
	}
	return vecResult;
}


#endif // !SUMOFVECTORS_H
