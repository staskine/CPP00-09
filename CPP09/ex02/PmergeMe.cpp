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


void PmergeMe::jacobsthalInsert(std::deque<int>& final, const std::deque<int>& _b, const std::deque<int>& _a) {
    size_t size = _b.size();
    if (size == 0) 
        return;

    auto it_a = std::find(final.begin(), final.end(), _a[0]);
    auto pos = std::lower_bound(final.begin(), it_a, _b[0]);
    final.insert(pos, _b[0]);

    std::vector<size_t> jacob = generateJacobsthalSequence(size);
    std::vector<bool> inserted(size, false);
    inserted[0] = true;

    for (size_t i = 1; i < jacob.size(); ++i) {
        size_t current = jacob[i];
        size_t previous = jacob[i - 1];

        // Insert elements in reverse between (previous, current]
        for (size_t j = std::min(current, size - 1); j > previous && j < size; --j) {
            if (!inserted[j]) {
                auto it_a = std::find(final.begin(), final.end(), _a[j]);
                auto pos = std::lower_bound(final.begin(), it_a, _b[j]);
                final.insert(pos, _b[j]);
                inserted[j] = true;
            }
        }

        // Also insert _b[current] if not already done
        if (current < size && !inserted[current]) {
            auto it_a = std::find(final.begin(), final.end(), _a[current]);
            auto pos = std::lower_bound(final.begin(), it_a, _b[current]);
            final.insert(pos, _b[current]);
            inserted[current] = true;
        }
    }

    // Making sure everythong was inserted
    for (size_t i = 0; i < size; ++i) {
        if (!inserted[i]) {
            auto it_a = std::find(final.begin(), final.end(), _a[i]);
            auto pos = std::lower_bound(final.begin(), it_a, _b[i]);
            final.insert(pos, _b[i]);
        }
    }
}




void PmergeMe::jacobsthalInsert(std::vector<int>& final, const std::vector<int>& _b, const std::vector<int>& _a) {
    size_t size = _b.size();
    if (size == 0) 
        return;

    auto it_a = std::find(final.begin(), final.end(), _a[0]);
    auto pos = std::lower_bound(final.begin(), it_a, _b[0]);
    final.insert(pos, _b[0]);

    std::vector<size_t> jacob = generateJacobsthalSequence(size);
    std::vector<bool> inserted(size, false);
    inserted[0] = true;

    for (size_t i = 1; i < jacob.size(); ++i) {
        size_t current = jacob[i];
        size_t previous = jacob[i - 1];

        // Insert in reverse between (previous, current]
        for (size_t j = std::min(current, size - 1); j > previous && j < size; --j) {
            if (!inserted[j]) {
                auto it_a = std::find(final.begin(), final.end(), _a[j]);
                auto pos = std::lower_bound(final.begin(), it_a, _b[j]);
                final.insert(pos, _b[j]);
                inserted[j] = true;
            }
        }

        // Also insert current one if not already done
        if (current < size && !inserted[current]) {
            auto it_a = std::find(final.begin(), final.end(), _a[current]);
            auto pos = std::lower_bound(final.begin(), it_a, _b[current]);
            final.insert(pos, _b[current]);
            inserted[current] = true;
        }
    }

    // Fallback for any not yet inserted
    for (size_t i = 0; i < size; ++i) {
        if (!inserted[i]) {
            auto it_a = std::find(final.begin(), final.end(), _a[i]);
            auto pos = std::lower_bound(final.begin(), it_a, _b[i]);
            final.insert(pos, _b[i]);
        }
    }
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
    

	// std::cout << "_____________________________________\nThis is for checking!!!!!!\n\na:";
	// for (const int& val : final) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "b: ";
    // for (const int& val : _b) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;

    jacobsthalInsert(final, _b, _a);

	// std::cout << "\nThis is after Jacobstahl!!!!!!\n\na:";
	// for (const int& val : final) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;

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
    
    jacobsthalInsert(final, _b, _a);

    // Return the fully sorted deque
    return final;
}
