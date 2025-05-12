#include "PmergeMe.hpp"
#include <algorithm>

// Function to generate the Jacobsthal sequence which goes:
// J(0)=0
// J(1)=1
// J(2)=J(1)+2×J(0)=1+2×0=1
// J(3)=J(2)+2×J(1)=1+2×1=3
// J(4)=J(3)+2×J(2)=3+2×1=5
// J(5)=J(4)+2×J(3)=5+2×3=11
// J(6)=J(5)+2×J(4)=11+2×5=21
// J(7)=J(6)+2×J(5)=21+2×11=43
// J(8)=J(7)+2×J(6)=43+2×21=85
// J(9)=J(8)+2×J(7)=85+2×43=171
// J(10)=J(9)+2×J(8)=171+2×85=341 etc

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t size) {
    
	// Initialize the Jacobsthal sequence with the first two elements: 0 and 1
    std::vector<size_t> jacobsthal = {0, 1};
    
    // Generate the sequence until the last element is greater than or equal to 'size'
    while (jacobsthal.back() < size) {
        //This part does: "J(n) = J(n−1) + 2 × J(n−2)"
        jacobsthal.push_back(jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    
    // Return the Jacobsthal sequence
    return jacobsthal;
}


// Function to perform binary insertion of an integer into a sorted vector.

void PmergeMe::binaryInsert(std::vector<int>& final, int value) {
    // Find the position where 'value' should be inserted in 'final' to maintain sorted order
    auto pos = std::lower_bound(final.begin(), final.end(), value);
    
    // Insert the value at the correct position
    final.insert(pos, value);
}

// Overloaded function to perform binary insertion of an integer into a sorted deque.

void PmergeMe::binaryInsert(std::deque<int>& final, int value) {
    // Find the position where 'value' should be inserted in 'final' to maintain sorted order
    auto pos = std::lower_bound(final.begin(), final.end(), value);
    
    // Insert the value at the correct position
    final.insert(pos, value);
}

// Function to sort a vector using a merge approach and the Jacobsthal sequence for insertion.

std::vector<int> PmergeMe::sortVector(const std::vector<int>& input) {
    size_t n = input.size();
    
    // If the vector has 1 or fewer elements, it is already sorted
    if (n <= 1)
        return input;

    // Split the input vector into two vectors: _a and _b
    std::vector<int> _a;
    std::vector<int> _b;
    
    // Pair elements from the input vector, sorting each pair into _a and _b
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (input[i] < input[i + 1]) {
            _b.push_back(input[i]);
            _a.push_back(input[i + 1]);
        } else {
            _b.push_back(input[i + 1]);
            _a.push_back(input[i]);
        }
    }
    
    // If the number of elements is odd, move the last element into _a
    if (n % 2 != 0) 
        _a.push_back(input.back());

    // Recursively sort vector _a
    std::vector<int> final = sortVector(_a);
    
    // Generate the Jacobsthal sequence based on the size of _b
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(_b.size());
    
    // Vector to keep track of which elements of _b have been inserted into the final result
    std::vector<bool> inserted(_b.size(), false);

    // Insert elements from _b into the sorted result using the Jacobsthal indices
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t idx = jacobsthal[i];

        if (idx < _b.size() && !inserted[idx]) {
            binaryInsert(final, _b[idx]);
            inserted[idx] = true;  // Mark this element as inserted
        }
    }

    // Insert any remaining elements from _b that were not inserted using Jacobsthal indices
	// This is done to handle overflow.
    for (size_t i = 0; i < _b.size(); ++i) {
        if (!inserted[i]) 
            binaryInsert(final, _b[i]);
    }

    // Return the fully sorted vector
    return final;
}

// Function to sort a deque using a merge-like approach and the Jacobsthal sequence for insertion.
std::deque<int> PmergeMe::sortDeque(const std::deque<int>& input) {
    size_t n = input.size();
    
    // If the deque has 1 or fewer elements, it is already sorted
    if (n <= 1) 
        return input;

    // Split the input deque into two deques: _a and _b
    std::deque<int> _a;
    std::deque<int> _b;
    
    // Pair elements from the input deque, sorting each pair into _a and _b
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (input[i] < input[i + 1]) {
            _b.push_back(input[i]);
            _a.push_back(input[i + 1]);
        } else {
            _b.push_back(input[i + 1]);
            _a.push_back(input[i]);
        }
    }
    
    // If the number of elements is odd, move the last element into _a
    if (n % 2 != 0) 
        _a.push_back(input.back());

    // Recursively sort deque _a
    std::deque<int> final = sortDeque(_a);
    
    // Generate the Jacobsthal sequence based on the size of _b
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(_b.size());
    
    // Vector to keep track of which elements of _b have been inserted into the final result
    std::vector<bool> inserted(_b.size(), false);

    // Insert elements from _b into the sorted result using the Jacobsthal indices
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t idx = jacobsthal[i];

        if (idx < _b.size() && !inserted[idx]) {
            binaryInsert(final, _b[idx]);
            inserted[idx] = true;  // Mark this element as inserted
        }
    }

    // Insert any remaining elements from _b that were not inserted using Jacobsthal indices
    for (size_t i = 0; i < _b.size(); ++i) {
        if (!inserted[i]) 
            binaryInsert(final, _b[i]);
    }

    // Return the fully sorted deque
    return final;
}
