#pragma once

#include <sstream>

#include "Company.h"
#include "ProfitCalculator.h"


std::string getProfitReport(Company* fromInclusive, Company* toInclusive, const std::map<int, ProfitCalculator>& profitCalculatorsByCompany) {
	std::ostringstream out;
	for (Company* c = fromInclusive; c <= toInclusive; ++c) {
		out << c->getName() << " = " << profitCalculatorsByCompany.at(c->getId()).calculateProfit(*c) << std::endl;
	}
	return out.str();
}
