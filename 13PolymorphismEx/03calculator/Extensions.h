#pragma once

#include <memory>
#include <sstream>
#include "CalculationEngine.h"
#include "InputInterpreter.h"

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine);
