#include "PmergeMe.hpp"
#include <algorithm>

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<size_t> jacobsthal = {0, 1};
    while (jacobsthal.back() < size) {
        jacobsthal.push_back(jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    return jacobsthal;
}

void PmergeMe::binaryInsert(std::vector<int>& final, int value) {
    auto pos = std::lower_bound(final.begin(), final.end(), value);
    final.insert(pos, value);
}

void PmergeMe::binaryInsert(std::deque<int>& final, int value) {
    auto pos = std::lower_bound(final.begin(), final.end(), value);
    final.insert(pos, value);
}

std::vector<int> PmergeMe::sortVector(const std::vector<int>& input) {
    size_t n = input.size();
    if (n <= 1)
		return input;

    std::vector<int> _a;
	std::vector<int> _b;
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (input[i] < input[i + 1]) {
            _b.push_back(input[i]);
            _a.push_back(input[i + 1]);
        } else {
            _b.push_back(input[i + 1]);
            _a.push_back(input[i]);
        }
    }
    if (n % 2 != 0) 
        _a.push_back(input.back());

    std::vector<int> final = sortVector(_a);
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(_b.size());
    std::vector<bool> inserted(_b.size(), false);

    // Improved readability for iterating over Jacobsthal indices
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t idx = jacobsthal[i];

        if (idx < _b.size() && !inserted[idx]) {
            binaryInsert(final, _b[idx]);
            inserted[idx] = true;
        }
    }

    // Insert any remaining elements from _b that weren't inserted using Jacobsthal indices
    for (size_t i = 0; i < _b.size(); ++i) {
        if (!inserted[i]) 
            binaryInsert(final, _b[i]);
    }

    return final;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int>& input) {
    size_t n = input.size();
    if (n <= 1) 
		return input;

    std::deque<int> _a;
	std::deque<int> _b;
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (input[i] < input[i + 1]) {
            _b.push_back(input[i]);
            _a.push_back(input[i + 1]);
        } else {
            _b.push_back(input[i + 1]);
            _a.push_back(input[i]);
        }
    }
    if (n % 2 != 0) 
        _a.push_back(input.back());

    std::deque<int> final = sortDeque(_a);
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(_b.size());
    std::vector<bool> inserted(_b.size(), false);

    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t idx = jacobsthal[i];

        if (idx < _b.size() && !inserted[idx]) {
            binaryInsert(final, _b[idx]);
            inserted[idx] = true;
        }
    }

    // Insert any remaining elements from _b that weren't inserted using Jacobsthal indices
    for (size_t i = 0; i < _b.size(); ++i) {
        if (!inserted[i]) 
            binaryInsert(final, _b[i]);
    }

    return final;
}