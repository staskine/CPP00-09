/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:44:33 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/20 11:44:36 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}

template<typename T>
T min(T &a, T &b) {
	if (a < b)
		return a;
	return b;
}

template<typename T>
T max(T &a, T &b) {
	if (a > b)
		return a;
	return b;
}

#endif