/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:01:51 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/20 12:16:45 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

template<typename T, typename F>
void iter(T *array, size_t size, F func) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

#endif