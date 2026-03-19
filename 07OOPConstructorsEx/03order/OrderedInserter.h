#pragma once

#include <vector>
#include <algorithm>

#include "Company.h"

bool compareCompanyPointers(const Company* a, const Company* b) {
    return a->getId() < b->getId(); // Or whatever comparison logic
}

class OrderedInserter {
	std::vector<const Company*>& companies;

public:

	OrderedInserter(std::vector<const Company*>& companies) : companies(companies) {}

	void insert(const Company* company) {
		auto it = std::lower_bound(companies.begin(), companies.end(), company, compareCompanyPointers);
		companies.insert(it, company);
	}

};