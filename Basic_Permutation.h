#pragma once
#include "IPermutation.h"
#include <algorithm>
template<typename T> class Basic_Permutation :
	public IPermutation<T>
{
public:
	Basic_Permutation() = default;
	~Basic_Permutation() = default;
	virtual void get_permutation(std::vector<T>& arr) {
		std::sort(arr.begin(), arr.end(), [](const T& a, const T& b) {return a > b; });
	}
};