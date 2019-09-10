#pragma once
#include <vector>
template<typename T> class IPermutation {
public:
	virtual void get_permutation(std::vector<T>&) = 0;
};