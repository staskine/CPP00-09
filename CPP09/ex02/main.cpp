/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:23:35 by sataskin          #+#    #+#             */
/*   Updated: 2025/05/12 12:57:21 by sataskin         ###   ########.fr       */
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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vecInput;
    std::deque<int> deqInput;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!parsing(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int value = std::stoi(arg);
        vecInput.push_back(value);
        deqInput.push_back(value);
    }

    // Display initial array
    std::cout << "Before: ";
    for (const auto& val : vecInput) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Vector part
    auto startVec = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVec = PmergeMe::sortVector(vecInput);
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationVec = endVec - startVec;

    // Deque part
    auto startDeq = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeq = PmergeMe::sortDeque(deqInput);
    auto endDeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationDeq = endDeq - startDeq;

    // Display sorted array
    std::cout << "After:  ";
    for (const auto& val : sortedVec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vecInput.size() << " elements with std::vector : " << durationVec.count() << " us" << std::endl;

    std::cout << "Time to process a range of " << deqInput.size() << " elements with std::deque  : " << durationDeq.count() << " us" << std::endl;

    return 0;
}