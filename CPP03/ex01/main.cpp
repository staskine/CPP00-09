/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:30:43 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/30 13:42:11 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap JaneDoe;
	ScavTrap JohnDoe("TestSubject");
	ScavTrap TestCopy;
	TestCopy = JaneDoe;
	ClapTrap ForRef("Clapping");
	
	JaneDoe.attack("you");
	JaneDoe.takeDamage(20);
	JaneDoe.beRepaired(20);
	JohnDoe.attack("him");
	JohnDoe.takeDamage(30);
	JohnDoe.beRepaired(30);
	TestCopy.attack("the world");
	TestCopy.takeDamage(60);
	TestCopy.beRepaired(60);
	ForRef.attack("itself");
	ForRef.takeDamage(3);
	ForRef.beRepaired(2);

	JaneDoe.guardGate();
	JohnDoe.guardGate();
	TestCopy.guardGate();
	
	for (int i = 5; i > -1 ; i--) {
		JaneDoe.attack("you");
	}
	for (int i = 2; i > -1 ; i--) {
		JohnDoe.takeDamage(30);
	}
	for (int i = 2; i > -1 ; i--) {
		TestCopy.beRepaired(60);
	}
}