#pragma once

#include <vector>
#include <algorithm>

#include "Company.h"

Company *find(const std::vector<Company*>& companies, int id) {
	auto it = std::find_if(companies.begin(), companies.end(), [id](Company* c) {
		return c->getId() == id;
	});
	if (it != companies.end()) {
		return *it;
	}
	else {
		return nullptr;
	}
}
