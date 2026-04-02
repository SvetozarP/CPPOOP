#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include "Defines.h"

void parseCommand(const std::string& command, std::string& type, std::string& action, int& index) {
    std::istringstream iss(command);
    iss >> action >> type >> index;
}

ErrorCode executeCommand(const std::string& command, std::vector<MemoryNode>& memory) {
    std::string typeStr; 
    std::string actionStr;
    int index;

    parseCommand(command, typeStr, actionStr, index);

    MemoryType requestedType = MemoryType::UNKNOWN;
    if (typeStr == "Single") {
        requestedType = MemoryType::SINGLE;
    }
    else if (typeStr == "Multiple") {
        requestedType = MemoryType::MULTIPLE;
    }

    if (actionStr == "Allocate") {
        if (memory[index].rawMemory != nullptr) {
            return ErrorCode::MEMORY_LEAK;
        }
        else {
            if (requestedType == MemoryType::SINGLE) {
                memory[index].rawMemory = new int;
                memory[index].memoryType = MemoryType::SINGLE;
            }
            else if (requestedType == MemoryType::MULTIPLE) {
                memory[index].rawMemory = new int[ALLOCATION_MULTIPLE_SIZE];
                memory[index].memoryType = MemoryType::MULTIPLE;
            }
            return ErrorCode::EXECUTE_SUCCESS;
        }
    }
    else if (actionStr == "Deallocate") {
        if (memory[index].rawMemory == nullptr) {
            return ErrorCode::DOUBLE_FREE;
        }
        else {
            if (memory[index].memoryType != requestedType) {
                return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
            }

            if (requestedType == MemoryType::SINGLE) {
                delete memory[index].rawMemory;
            }
            else if (requestedType == MemoryType::MULTIPLE) {
                delete[] memory[index].rawMemory;
            }
            memory[index].rawMemory = nullptr;
            memory[index].memoryType = MemoryType::UNKNOWN;
            return ErrorCode::EXECUTE_SUCCESS;
        }
    }
    return ErrorCode::EXECUTE_SUCCESS;
}

void printResult(const ErrorCode errorCode, const std::string& command) {
    std::cout << command << " - ";
    switch (errorCode) {
    case ErrorCode::EXECUTE_SUCCESS:
        std::cout << "success";
        break;
    case ErrorCode::MEMORY_LEAK:
        std::cout << "memory leak prevented, will not make allocation";
        break;
    case ErrorCode::DOUBLE_FREE:
        std::cout << "system crash prevented, will skip this deallocation";
        break;
    case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH:
        std::cout << "Warning allocate/deallocate mismatch, will skip this deallocation";
        break;
    }
    std::cout << std::endl;
}