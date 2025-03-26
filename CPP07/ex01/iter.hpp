/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:01:51 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/26 12:52:00 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

template<typename T>
void iter(T *array, size_t size, void(*f)(T&)) {
	for (size_t i = 0; i < size; i++) {
		f(array[i]);
	}
}

template<typename T>
void iter(T *array, size_t size, void(*f)(const T&)) {
	for (size_t i = 0; i < size; i++) {
		(*f)(array[i]);
	}
}

#endif