#ifndef SORT_BY_H
#define SORT_BY_H

#include <algorithm>
#include "Company.h"

void sortBy(Company** begin, Company** end, bool (*lessThan)(const Company&, const Company&)) {

    std::sort(begin, end, [lessThan](Company* a, Company* b) {
        
        return lessThan(*a, *b);
        });
}


#endif // SORT_BY_H