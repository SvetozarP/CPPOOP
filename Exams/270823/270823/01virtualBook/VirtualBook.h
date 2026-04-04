#pragma once
#include <vector>
#include "VirtualPage.h"

class VirtualBook {
	std::vector<VirtualPage> pages;

public:
	void addPage(const VirtualPage& page);
	void printContent() const;
	void removeLastPage();
	void removeAllPages();
};