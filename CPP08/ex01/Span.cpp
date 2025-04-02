/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:27:07 by sataskin          #+#    #+#             */
/*   Updated: 2025/04/01 13:09:08 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span::Span(const Span &obj): _N(obj._N), _values(obj._values) {}

Span& Span::operator=(const Span &obj) {
	if (this != &obj) {
		_N = obj._N;
		_values = obj._values;
	}
	return (*this);
}

Span::~Span() {
	std::cout << "Destructor was called" << std::endl;
}

void Span::addNumber(int num) {
	if (_values.size() >= _N) {
		throw std::out_of_range("The container is full!");
	}
	_values.push_back(num);
}

int Span::shortestSpan() const {
	if (_values.size() <= 2)
		throw std::runtime_error("Not enough values in container");
	std::vector<int> sortThis = _values;
	std::sort(sortThis.begin(), sortThis.end());

	int minimum = 2147483647;
	for (std::vector<int>::size_type i = 1; i < sortThis.size(); i++) {
		minimum = std::min(minimum, sortThis[i] - sortThis[i - 1]);
	}

	return minimum;
}

int Span::longestSpan() const {
	if (_values.size() <= 2)
		throw std::runtime_error("Not enough values in container");
    int min = *std::min_element(_values.begin(), _values.end());
    int max = *std::max_element(_values.begin(), _values.end());

    return max - min;
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (_values.size() + std::distance(start, end) > _N)
		throw std::out_of_range("You're trying to add too many values at once! :(");
	_values.insert(_values.end(), start, end);
}
