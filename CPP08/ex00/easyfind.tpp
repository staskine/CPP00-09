/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:14:48 by sataskin          #+#    #+#             */
/*   Updated: 2025/04/01 12:14:50 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int val) {
	typename T::iterator i = std::find(container.begin(), container.end(), val);
	if (i == container.end()) {
		throw std::runtime_error("Integer not found.");
	}
	return i;
}

#endif