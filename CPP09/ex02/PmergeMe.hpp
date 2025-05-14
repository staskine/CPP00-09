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

// Static member functions in C++ are class-level functions that are associated with the
// class itself rather than with individual instances (objects) of the class. They are
// declared using the static keyword, and we can call such a function with a class name
// without the need to create an object.

class PmergeMe {
	public:
		static std::vector<int> sortVector(const std::vector<int>& input);
		static std::deque<int> sortDeque(const std::deque<int>& input);
	
	private:
		static std::vector<size_t> generateJacobsthalSequence(size_t size);
		static void binaryInsert(std::vector<int>& sorted, int value);
		static void binaryInsert(std::deque<int>& sorted, int value);
		static void jacobsthalInsert(std::vector<int>& final, const std::vector<int>& _b, const std::vector<int>& _a);
    	static void jacobsthalInsert(std::deque<int>& final, const std::deque<int>& _b, const std::deque<int>& _a);
};
