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
    	static void sortVector(std::vector<int>& vec);
    	static void sortDeque(std::deque<int>& deq);

	private:
    	static std::vector<int> fordJohnsonVec(const std::vector<int>& input);
    	static std::deque<int> fordJohnsonDeq(const std::deque<int>& input);

    	static void binaryInVec(std::vector<int>& sorted, int value);
    	static void binaryInDeq(std::deque<int>& sorted, int value);
};
