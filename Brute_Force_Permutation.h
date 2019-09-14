#pragma once
#include "IPermutation.h"
template<typename T> class Brute_Force_Permutation :
	public IPermutation<T>
{
private:
	std::vector<T>* current_array;
	short w;
public:
	Brute_Force_Permutation(short w) {
		current_array = nullptr;
		if (w >= 0 || w <= 100)
			this->w = w;
		else throw std::invalid_argument("w must be in [0;100]");
	}
	~Brute_Force_Permutation() = default;
	virtual void get_permutation(std::vector<T>& arr) {
		if (&arr != current_array) {
			size_t k = w * arr.size() / 100;
			auto bound = std::next(arr.begin(), k);
			std::sort(arr.begin(), bound, [](const T& a, const T& b) {return a > b; });
			if (k < arr.size())
				std::sort(std::next(bound), arr.end());
			current_array = &arr;
		}
		std::next_permutation(arr.begin(), arr.end());
	}
};
