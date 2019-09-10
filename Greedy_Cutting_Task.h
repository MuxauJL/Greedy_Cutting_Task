#pragma once
#include "IPermutation.h"
#include <algorithm>

template<typename T = size_t>class Greedy_Cutting_Task
{
private:
	T A;
	std::vector<T> b;
	std::vector<size_t> x;
	size_t n;
public:
	Greedy_Cutting_Task(T A, size_t n, std::vector<T> b) {
		this->A = A;
		this->n = n;
		x = std::vector<size_t>(n);
		this->b = b;
	}
	~Greedy_Cutting_Task() = default;
	size_t greedy_algorithm();
	size_t solve(IPermutation<T>* permutation) {
		permutation->get_permutation(b);
		return greedy_algorithm();
	}
	std::vector<size_t> get_solution() { return x; }
};

template<typename T>
size_t Greedy_Cutting_Task<T>::greedy_algorithm() {
	std::vector<T> rods;
	rods.push_back(A);
	bool is_cutted;
	for (size_t i = 0; i < n; ++i) {
		is_cutted = false;
		for (size_t j = 0; j < rods.size(); ++j) {
			if (b[i] <= rods[j]) {
				x[i] = j;
				rods[j] -= b[i];
				is_cutted = true;
				break;
			}
		}
		if (!is_cutted) {
			rods.push_back(A - b[i]);
			x[i] = rods.size() - 1;
		}
	}
	return *std::max_element(x.begin(), x.end()) + 1;
}

