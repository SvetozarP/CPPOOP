#include "Extensions.h"
#include "AdvancedInterpreter.h"

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
	return std::make_shared<AdvancedInterpreter>(engine);
}