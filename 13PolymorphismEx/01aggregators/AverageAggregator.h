#pragma once

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {

protected:

	int aggregationSum;

public:

	AverageAggregator(std::istream& stream) : StreamAggregator(stream) {
		aggregationResult = 0;
		aggregationSum = 0;
	}

protected:

	virtual void aggregate(int next) override {
		StreamAggregator::aggregate(next);

		aggregationSum += next;

		aggregationResult = aggregationSum / StreamAggregator::getNumAggregated();
	}

};