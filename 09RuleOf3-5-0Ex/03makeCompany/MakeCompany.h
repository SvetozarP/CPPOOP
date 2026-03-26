#pragma once

#include "Company.h"

#include <memory>
#include <string>
#include <vector>

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& props) {
	
	int id = std::stoi(props[0]);
	std::string name = props[1];
	std::vector<std::pair<char, char>> employees;

	for (size_t curElement = 2; curElement < props.size(); curElement++) {
		std::pair<char, char> curEmployee = std::pair<char, char>(props[curElement][0], props[curElement][1]);
		employees.push_back(curEmployee);
	}

	std::shared_ptr<Company> res(new Company(id, name, employees));

	return res;
}