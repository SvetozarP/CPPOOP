#pragma once

#include <sstream>
#include <vector>
#include <set>
#include "Company.h"


class CompanyFactory {

	const std::string& input;
	int& numCompanies;
	std::string(*uniqueIdGenerator)(const Company& c);

public:

	CompanyFactory(
		const std::string& input_,
		int& numCompanies_,
		std::string(*uniqueIdGenerator_)(const Company& c)
	) : input(input_), numCompanies(numCompanies_), uniqueIdGenerator(uniqueIdGenerator_) {
	}

	Company* create() {

		std::vector<Company> companies;
		std::set<std::string> companiesSet;
		numCompanies = 0;


		std::istringstream istr(input);
		std::string curLine;

		while (getline(istr, curLine)) {

			std::istringstream curLineStream(curLine);
			int id;
			std::string name;

			curLineStream >> id >> name;

			Company curCompany(id, name);

			std::string uniqueId = uniqueIdGenerator(curCompany);

			std::pair<
				std::set<std::string>::iterator,
				bool
			> p = companiesSet.insert(uniqueId);

			if (p.second == true) {
				//there was insert

				companies.push_back(curCompany);
				numCompanies++;
			}

		}
		Company* retArray = new Company[companies.size()];

		for (size_t index = 0; index < companies.size(); index++) {
			retArray[index] = companies[index];
		}

		return retArray;
	}
};


Company* parseUniqueCompanies(
	const std::string& input, 
	int& numCompanies, 
	std::string(*uniqueIdGenerator)(const Company& c)
) {
	return CompanyFactory(input, numCompanies, uniqueIdGenerator).create();
}