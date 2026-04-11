#pragma once

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {

public:

	SumAggregator(std::istream& stream) : StreamAggregator(stream) {
		aggregationResult = 0;
	}

protected:
	virtual void aggregate(int next) override {
		StreamAggregator::aggregate(next);
		aggregationResult += next;
	}

};