#include <iostream>
#include <vector>
#include <sstream>

#include "Defines.h"

class CommandProcessor {

    static int* allocatedMemory;

    const std::string& command;
    std::vector<int*>& memory;

    enum Command {
        ALLOCATE,
		DEALLOCATE,
        IDLE
    };

public:

    CommandProcessor(const std::string& command, std::vector<int*>& memory)
        : command(command), memory(memory) {}
	

    ErrorCode execute() {

		std::pair<Command, int> cmd = parse(command);

        switch (cmd.first)
        {
        default:
        case Command::IDLE:
			return ErrorCode::EXECUTE_IDLE;
            break;
        case Command::ALLOCATE:
			return doAllocate(cmd.second);
        case Command::DEALLOCATE:
            return doDeAllocate(cmd.second);
        }

    }

private:

    std::pair<Command, int> parse(const std::string& command) {

        std::istringstream iss(command);
        std::pair<Command, int> res;
        std::string subCommand;

        iss >> subCommand;

        if (subCommand == "Allocate") {
            res.first = Command::ALLOCATE;
        }
        else if (subCommand == "Deallocate") {
            res.first = Command::DEALLOCATE;
        }
        else {
            res.first = Command::IDLE;
		}

		if (res.first != Command::IDLE) {
            iss >> res.second;
        }

        return res;
    }

    ErrorCode doAllocate(const int index) {
        if (index < 0 || index >= memory.size()) {
            return ErrorCode::INDEX_OUT_OF_BOUND;
        }
        if (memory[index] != nullptr) {
            return ErrorCode::MEMORY_LEAK;
        }
        memory[index] = allocatedMemory;
        return ErrorCode::EXECUTE_SUCCESS;
    }

    ErrorCode doDeAllocate(const int index) {
        if (index < 0 || index >= memory.size()) {
            return ErrorCode::INDEX_OUT_OF_BOUND;
        }
        if (memory[index] == nullptr) {
            return ErrorCode::DOUBLE_FREE;
        }
        // delete memory[index];
        memory[index] = nullptr;
        return ErrorCode::EXECUTE_SUCCESS;

    }
};

static int someInt = 1;
int* CommandProcessor::allocatedMemory = &someInt;

ErrorCode executeCommand(const std::string& command,
    std::vector<int*>& memory) {

	CommandProcessor cp(command, memory);

	return cp.execute();
}

void printResult(const ErrorCode     errorCode,
    const std::string& command) {

    std::string message;

    switch (errorCode)
    {
        case ErrorCode::EXECUTE_SUCCESS:
            message = "success";
			break;
		case ErrorCode::EXECUTE_IDLE:
			message = "this exam is a piece of cake! Where is the OOP already?!?";
            break;
		case ErrorCode::MEMORY_LEAK:
			message = "memory leak prevented, will not make allocation";
            break;
		case ErrorCode::DOUBLE_FREE:
			message = "system crash prevented, will skip this deallocation";
            break;
		case ErrorCode::INDEX_OUT_OF_BOUND:
			message = "out of bound";
            break;

    default:
        break;
    }

	std::cout << command << " - " << message << std::endl;
}