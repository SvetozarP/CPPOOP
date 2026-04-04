#include "VirtualBook.h"

void VirtualBook::addPage(const VirtualPage& page) {
	pages.push_back(page);
}

void VirtualBook::printContent() const {
	for (const auto& page : pages) {
		page.printContent();
	}
}

void VirtualBook::removeLastPage() {
	if (!pages.empty()) {
		pages.pop_back();
	}
}

void VirtualBook::removeAllPages() {
	pages.clear();
}