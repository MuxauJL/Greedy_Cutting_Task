#pragma once
#include "IPermutation.h"
template<typename T>class Sorting_Permutation :
	public IPermutation<T>
{
public:
	Sorting_Permutation() = default;
	~Sorting_Permutation() = default;
	virtual void get_permutation(std::vector<T>&) { };
};
