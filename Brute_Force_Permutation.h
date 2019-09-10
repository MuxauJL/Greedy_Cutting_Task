#pragma once
#include "IPermutation.h"
template<typename T> class Brute_Force_Permutation :
	public IPermutation<T>
{
public:
	Brute_Force_Permutation() = default;
	~Brute_Force_Permutation() = default;
	virtual void get_permutation(std::vector<T>&) {};
};
