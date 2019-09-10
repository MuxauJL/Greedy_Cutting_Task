#include "Greedy_Cutting_Task.h"
#include "Brute_Force_Permutation.h"
#include <memory>
#include <iostream>

int main() {
	size_t A = 3;
	const size_t n = 3;
	std::vector<size_t> b = { 2,2,1};
	Greedy_Cutting_Task<size_t> task(A, n, b);
	std::cout << task.solve(std::unique_ptr<IPermutation<size_t>>(new Brute_Force_Permutation<size_t>()).get()) << "\n";
	for (auto x : task.get_solution())
		std::cout << x << " ";
	return 0;
}