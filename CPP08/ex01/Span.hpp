/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:20:03 by sataskin          #+#    #+#             */
/*   Updated: 2025/04/01 12:53:56 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _values;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &obj);
		Span &operator=(const Span &obj);
		~Span();

		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;

		void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
};