#ifndef MEMORY_SET_OPERATION_H
#define MEMORY_SET_OPERATION_H

#include <stack>
#include "Operation.h"

class MemorySetOperation : public Operation {
    std::stack<int> memory;
public:

    void addOperand(int operand) override {
        this->memory.push(operand);
    }

    bool isCompleted() override {
        return false;
    }

    int getResult() override {
        if(memory.size() == 0)
            return 0;

        int top = memory.top();
        memory.pop();
        return top;
    }
};

#endif // MEMORY_SET_OPERATION_H
