#include "PmergeMe.hpp"

void PmergeMe::binaryInVec(std::vector<int>& sorted, int value) {
    auto pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

void PmergeMe::binaryInDeq(std::deque<int>& sorted, int value) {
    auto pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

std::vector<int> PmergeMe::fordJohnsonVec(const std::vector<int>& input) {
    if (input.size() <= 1)
		return input;

    std::vector<int> bigs;
	std::vector<int> smalls;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i + 1]) {
            smalls.push_back(input[i]);
            bigs.push_back(input[i + 1]);
        } else {
            smalls.push_back(input[i + 1]);
            bigs.push_back(input[i]);
        }
    }
    if (input.size() % 2 == 1) 
		bigs.push_back(input.back());

    std::vector<int> sorted = fordJohnsonVec(bigs);
    for (int val : smalls)
		binaryInVec(sorted, val);

    return sorted;
}

std::deque<int> PmergeMe::fordJohnsonDeq(const std::deque<int>& input) {
    if (input.size() <= 1)
		return input;

    std::deque<int> bigs;
	std::deque<int> smalls;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i + 1]) {
            smalls.push_back(input[i]);
            bigs.push_back(input[i + 1]);
        } else {
            smalls.push_back(input[i + 1]);
            bigs.push_back(input[i]);
        }
    }
    if (input.size() % 2 == 1)
		bigs.push_back(input.back());

    std::deque<int> sorted = fordJohnsonDeq(bigs);
    for (int val : smalls)
		binaryInDeq(sorted, val);

    return sorted;
}

void PmergeMe::sortVector(std::vector<int>& vec) {
    vec = fordJohnsonVec(vec);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
    deq = fordJohnsonDeq(deq);
}