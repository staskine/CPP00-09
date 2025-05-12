#pragma once

# include <vector>
# include <deque>
# include <iostream>
# include <vector>
# include <deque>
# include <chrono>
# include <sstream>
# include <string>
# include <limits>
# include <cctype>

class PmergeMe {
	public:
		static std::vector<int> sortVector(const std::vector<int>& input);
		static std::deque<int> sortDeque(const std::deque<int>& input);
	
	private:
		static std::vector<size_t> generateJacobsthalSequence(size_t size);
		static void binaryInsert(std::vector<int>& sorted, int value);
		static void binaryInsert(std::deque<int>& sorted, int value);
};
