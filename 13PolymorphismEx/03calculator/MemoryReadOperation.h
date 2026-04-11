#pragma once

#include <stack>
#include "Operation.h"
#include "MemorySetOperation.h"

class MemoryReadOperation : public Operation {
    std::shared_ptr<MemorySetOperation> ms;

public:

    MemoryReadOperation(std::shared_ptr<MemorySetOperation> ms) : ms(ms) {}

    void addOperand(int operand) override {
    }

    bool isCompleted() override {
        return true;
    }

    int getResult() override {
        return ms->getResult();
    }
};

