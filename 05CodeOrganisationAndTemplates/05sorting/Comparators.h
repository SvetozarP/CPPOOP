#ifndef COMPARATORS_H
#define COMPARATORS_H

template <typename T> class LessThan {
public:

	bool operator()(const T& left, const T& right) const {
		return left < right;
	}
};

template <typename T, typename Comparator> class Reverse {

public:

	bool operator()(const T& left, const T& right) const {
		Comparator c;
		return !c(left, right);
	}

};



#endif // COMPARATORS_H
