/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:42:26 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/03 17:33:24 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		~Brain();

		std::string getIdea(unsigned int i);
		void setIdea(std::string brainfart, unsigned int i);
};