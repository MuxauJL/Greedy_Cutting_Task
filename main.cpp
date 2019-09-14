#include "Greedy_Cutting_Task.h"
#include "Basic_Permutation.h"
#include "Sorting_Permutation.h"
#include "Brute_Force_Permutation.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <iomanip>

int main() {
	std::string dir = "Task1\\";
	std::vector<std::string> files = {
		"task_1_01_n10.txt",
		"task_1_02_n10.txt",
		"task_1_03_n100.txt",
		"task_1_04_n101.txt",
		"task_1_05_n101.txt",
		"task_1_06_n1002.txt",
		"task_1_07_n1001.txt",
		"task_1_08_n1001.txt",
		"task_1_09_n1000.txt",
		"task_1_10_n1000.txt"
	};

	std::cout << "Enter the number of iterations for the brute force algorithm:\n";
	size_t N;
	std::cin >> N;

	size_t A;
	size_t n;
	std::vector<size_t> b;

	auto get_n = [](std::string filename) {
		auto begin = filename.find('n') + 1;
		auto end = filename.find('.');
		return std::stoi(filename.substr(begin, end - begin));
	};

	std::cout
		<< " __________________________________________________________________________\n"
		<< "| N|lower bound|      Basic|                Sorting|            Brute Force|\n"
		<< "|  |           |res|(b-l)/b|res|  (r-l)/l|  (b-r)/b|res|  (r-l)/l|  (b-r)/b|\n";
	for (int i = 0; i < files.size(); ++i) {
		std::ifstream in(dir + files[i]);
		if (in.is_open()) {
			n = get_n(files[i]);
			in >> A;
			b = std::vector<size_t>();
			b.reserve(n);
			std::copy(std::istream_iterator<size_t>(in), {}, std::back_inserter(b));
			Greedy_Cutting_Task task(A, n, b);
			std::cout
				<< "|" << std::setw(2) << i + 1;
			double lower_bound= task.get_lower_bound();
			std::cout
				<< "|" << std::setw(11) << lower_bound;
			task.init();
			Basic_Permutation<size_t> basic_permutation;
			double basic = task.solve(&basic_permutation);
			std::cout
				<< "|" << std::setw(3) << basic
				<< "|" << std::setw(7)  <<std::setprecision(3) <<(basic - lower_bound) / basic;
			task.init();
			double record_sorting = n;
			for (int w = 0; w < 100; ++w) {
				Sorting_Permutation<size_t> sorting_permutation(n, w);
				double sorting = task.solve(&sorting_permutation);
				if (record_sorting > sorting)
					record_sorting = sorting;
			}
			std::cout
				<< "|" << std::setw(3) << record_sorting
				<< "|" << std::setw(9) <<  std::setprecision(3) << (record_sorting - lower_bound) / record_sorting
				<< "|" << std::setw(9) <<  std::setprecision(3) << (basic - record_sorting) / basic;
			task.init();
			Brute_Force_Permutation<size_t> brute_force_permutation;
			double record_brute_force = n;
			for (int k = 0; k < N; ++k) {
				size_t brute_force=task.solve(&brute_force_permutation);
				if (record_brute_force > brute_force)
					record_brute_force = brute_force;
			}
			std::cout
				<< "|" << std::setw(3) << record_brute_force
				<< "|" << std::setw(9)  << std::setprecision(3) << (record_brute_force - lower_bound) / record_brute_force
				<< "|" << std::setw(9)  << std::setprecision(3) << (basic - record_brute_force) / basic << "|\n";
		}
		else throw std::exception("filename is wrong");
		in.close();
	}
	return 0;
}