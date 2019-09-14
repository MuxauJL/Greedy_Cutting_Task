#pragma once
#include "IPermutation.h"
template<typename T>class Sorting_Permutation :
	public IPermutation<T>
{
private:
	short w;
	size_t n;
public:
	Sorting_Permutation(size_t n, short w) {
		if (n > 0)
			this->n = n;
		else throw std::invalid_argument("n must be > 0");
		if (w >= 0 || w <= 100)
			this->w = w;
		else throw std::invalid_argument("w must be in [0;100]");
	}
	~Sorting_Permutation() = default;
	virtual void get_permutation(std::vector<T>& arr) {
		size_t k = w * n / 100;
		auto bound = std::next(arr.begin(), k);
		std::sort(arr.begin(), bound, [](const T& a, const T& b) {return a > b; });
		if (k < n)
			std::sort(bound + 1, arr.end());
	}
};
