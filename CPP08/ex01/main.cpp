/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:57:24 by sataskin          #+#    #+#             */
/*   Updated: 2025/04/01 13:54:00 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric>

int main() {
	
	try {
		std::cout << "-----------PDF MAIN!--------------" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	
	try {
		std::cout << "\n\n-----------First Test!--------------" << std::endl;
		Span sp(9);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		std::vector<int> extra = { 8, 12, 2, 33};
		std::cout << "\n----------Now lets add some more values!-----------" << std::endl;
		sp.addRange(extra.begin(), extra.end());

		std::cout << "Shortest Span after adding more numbers: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span after adding more numbers: " << sp.longestSpan() << std::endl;	
		std::cout << "\n----------And now let's throw an exception!------------" << std::endl;
		sp.addNumber(25);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	
	try {
		std::cout << "\n\n-----------Second Test!--------------" << std::endl;
        Span Test(15000);
        std::vector<int> temp(15000);
        std::iota(temp.begin(), temp.end(), 0); // fills up temp
        Test.addRange(temp.begin(), temp.end());
        std::cout << "Shortest Span: " << Test.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << Test.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}