/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:23:35 by sataskin          #+#    #+#             */
/*   Updated: 2025/05/12 11:05:12 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool parsing(const std::string& input) {
    const long long MAX_INT32 = std::numeric_limits<int32_t>::max();
    if (input.empty()) 
        return false;

    for (char c : input) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    try {
        long long value = std::stoll(input);
        if (value <= 0 || value > MAX_INT32) {
            return false;
        }
    } catch (...) {
        return false;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!parsing(arg)) {
            std::cerr << "Error: Parsing caught an error in input" << std::endl;
            return 1;
        }
        int val = std::stoi(arg);
        vec.push_back(val);
        deq.push_back(val);
    }

    std::cout << "Before: ";
    for (const int& n : vec) std::cout << n << " ";
        std::cout << std::endl;

    auto startVec = std::chrono::high_resolution_clock::now();
    PmergeMe::sortVector(vec);
    auto endVec = std::chrono::high_resolution_clock::now();

    auto startDeq = std::chrono::high_resolution_clock::now();
    PmergeMe::sortDeque(deq);
    auto endDeq = std::chrono::high_resolution_clock::now();

    std::cout << "After:  ";
    for (const int& n : vec) std::cout << n << " ";
    std::cout << std::endl;

    double vecTime = std::chrono::duration<double>(endVec - startVec).count() * 1e6;
    double deqTime = std::chrono::duration<double>(endDeq - startDeq).count() * 1e6;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;

    return 0;
}