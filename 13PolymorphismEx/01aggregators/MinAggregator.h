#pragma once

#include <climits>
#include "Aggregator.h"

class MinAggregator : public StreamAggregator {

public:

	MinAggregator(std::istream& stream) : StreamAggregator(stream) {
		aggregationResult = INT_MAX;
	}

protected:

	virtual void aggregate(int next) override {
		StreamAggregator::aggregate(next);

		if(aggregationResult > next) 
			aggregationResult = next;

	}

};