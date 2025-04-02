/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:58:28 by sataskin          #+#    #+#             */
/*   Updated: 2025/04/01 14:21:14 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> lst;
	
	mstack.push(5);
	lst.push_back(5);
	mstack.push(17);
	lst.push_back(17);
	std::cout << "Mutant: " << mstack.top() << std::endl;
	std::cout << "std::list: " << lst.back() << std::endl;
	mstack.pop();
	lst.pop_front();
	std::cout << "Mutant size: " << mstack.size() << std::endl;
	std::cout << "std::list size after pop: " << lst.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
	
	std::cout << "Print out mutant stack" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nstd::list elements:\n";
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }
	return 0;
}