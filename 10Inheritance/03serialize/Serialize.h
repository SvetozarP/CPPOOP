#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <string>
#include <vector>
#include <sstream>
#include <cstring> 

#include "Company.h" 

byte* serializeToMemory(const std::string& companiesString, size_t& bytesWritten) {
    std::istringstream companiesIn(companiesString);
    std::vector<Company> companies;
    Company company;

    while (companiesIn >> company) {
        companies.push_back(company);
    }

    size_t totalSize = 1;

    for (const auto& comp : companies) {
        totalSize += 1;
        totalSize += comp.getName().length() + 1;
        totalSize += 1;
        totalSize += comp.getEmployees().size() * 2;
    }

    byte* memory = new byte[totalSize];
    byte* currentPtr = memory;

    *currentPtr++ = static_cast<byte>(companies.size());

    for (const auto& comp : companies) {
        *currentPtr++ = static_cast<byte>(comp.getId());

        for (char c : comp.getName()) {
            *currentPtr++ = static_cast<byte>(c);
        }
        *currentPtr++ = '\0';

        *currentPtr++ = static_cast<byte>(comp.getEmployees().size());

        for (const auto& employee : comp.getEmployees()) {
            *currentPtr++ = static_cast<byte>(employee.first);
            *currentPtr++ = static_cast<byte>(employee.second);
        }
    }

    bytesWritten = totalSize;

    return memory;
}

#endif // SERIALIZE_H