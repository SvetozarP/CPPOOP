#pragma once

#include "InputInterpreter.h"
#include "DivisionOperation.h"
#include "MemorySetOperation.h"
#include "MemoryReadOperation.h"

class AdvancedInterpreter : public InputInterpreter {

    std::shared_ptr<MemorySetOperation> ms;

public:

	AdvancedInterpreter(CalculationEngine& engine) : InputInterpreter(engine), ms(new MemorySetOperation()) {}


    virtual std::shared_ptr<Operation> getOperation(std::string operation) override {
 
        if (operation == "/") {
            return std::make_shared<DivisionOperation>();
        } else if (operation == "ms") {
            return ms;
        }
        else if (operation == "mr")
        {
            return std::make_shared<MemoryReadOperation>(ms);
        }

        return InputInterpreter::getOperation(operation);
    }   

};