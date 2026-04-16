#include "FilterFactory.h"

Filter* FilterFactory::buildFilter(std::string filterDefinition) const {
	if (filterDefinition == "A-Z") {
		return new CapsFilter();
	}
	if (filterDefinition == "a-z") {
		return new SmallFilter();
	}
	if (filterDefinition == "0-9") {
		return new NumberFilter();
	}
	return nullptr;
}