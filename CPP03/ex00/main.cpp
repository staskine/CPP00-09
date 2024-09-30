/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:30:43 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/30 10:41:21 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap JaneDoe;
	ClapTrap JohnDoe("Johnny");
	ClapTrap TestCopy;
	TestCopy = JaneDoe;
	
	JaneDoe.attack("you");
	JaneDoe.takeDamage(2);
	JaneDoe.beRepaired(2);
	JohnDoe.attack("him");
	JohnDoe.takeDamage(3);
	JohnDoe.beRepaired(3);
	TestCopy.attack("the world");
	TestCopy.takeDamage(6);
	TestCopy.beRepaired(6);

	for (int i = 10; i > -1 ; i--) {
		JaneDoe.attack("you");
	}
	for (int i = 10; i > -1 ; i--) {
		JohnDoe.takeDamage(3);
	}
	for (int i = 10; i > -1 ; i--) {
		TestCopy.beRepaired(6);
	}
}