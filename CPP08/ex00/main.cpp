/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:07:18 by sataskin          #+#    #+#             */
/*   Updated: 2025/04/01 12:14:27 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
	//Testing with standard inputs
    std::vector<int> v = {1, 3, 5, 7, 9, 11, 13, 14};
    std::list<int> l = {10, 15, 20, 4, 3};
    try {
        std::vector<int>::iterator iv = easyfind(v, 3);
        std::cout << "Found in vector: " << *iv << std::endl;

        std::list<int>::iterator il = easyfind(l, 20);
        std::cout << "Found in list: " << *il << std::endl;

        easyfind(v, 135);
    } catch (const std::exception& e) {
        std::cout << "Caught this: " << e.what() << std::endl;
    }

	// Trying with an empty container
	std::deque<int> d = {11, 22, 33, 44};
	std::deque<int> empty = {};
	try {
		std::deque<int>::iterator id = easyfind(d, 11);
        std::cout << "Found in vector: " << *id << std::endl;

		std::deque<int>::iterator id2 = easyfind(empty, 3);
        std::cout << "Found in vector: " << *id2 << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught empty with this message: " << e.what() << std::endl; 
	}

    return 0;
}