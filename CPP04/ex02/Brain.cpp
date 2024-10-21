/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:56:20 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/03 18:00:40 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Making a brain for your animal using default\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "No thoughts, brain empty";
	}
}

Brain::Brain(const Brain& obj) {
	std::cout << "Making a brain from another one\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = obj.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& obj) {
	std::cout << "Filling brain using copy operator\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Destroying your brain\n";
}

std::string Brain::getIdea(unsigned int i) {
	if (i > 99) {
		return nullptr;
	}
	return this->ideas[i];
}

void Brain::setIdea(std::string brainfart, unsigned int i) {
	if (i > 99) {
	}
	else  {
		this->ideas[i] = brainfart;
	}
}
