#ifndef VECTOR_COMPARISONS_H
#define VECTOR_COMPARISONS_H

#include "Vector.h"

class VectorLengthComparer {

public:

	bool operator()(const Vector& v1, const Vector& v2) const {
		return v1.getLengthSq() < v2.getLengthSq();
	}
};


template <typename T, typename Comparer>
class ReverseComparer {
	
	Comparer comparer;

public:
	
	bool operator()(const T& v1, const T& v2) const {
		return !comparer(v1, v2);
	}

};

#endif // !VECTOR_COMPARISONS_H