#pragma once
#include "IPermutation.h"
template<typename T>class Sorting_Permutation :
	public IPermutation<T>
{
private:
	T A;
public:
	Sorting_Permutation(T A) {
		if (A > 0)
			this->A = A;
		else throw std::invalid_argument("A must be > 0");
	}
	~Sorting_Permutation() = default;
	virtual void get_permutation(std::vector<T>& arr) {
		std::sort(arr.begin(), arr.end(), [](const T& a, const T& b) {return a > b; });
		T sum = 0;
		for (size_t i = 0; i < arr.size(); ++i) {
			if (sum + arr[i] > A) {
				for (size_t j = arr.size() - 1; j > i; --j) {
					if (sum + arr[j] <= A) {
						T tmp = arr[j];
						arr[j] = arr[i];
						arr[i] = tmp;
						++i;
						sum += arr[j];
					}
					else {
						sum = 0;
						if (j < arr.size() - 1) {
							T tmp = arr[arr.size() - 1];
							arr[arr.size() - 1] = arr[i + 1];
							arr[i + 1] = tmp;
						}
						break;
					}
				}
			}
			else
				sum += arr[i];
		}
	}
};
