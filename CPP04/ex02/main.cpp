/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:54:20 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/03 17:48:38 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	//Animal hello;
	const Animal* array[10];
	std::cout << "Making the array\n";
	for (int i = 9; i > 0; i--) {
		array[i] = new Cat();
		i--;
		array[i] = new Dog();
	}
	
	std::cout << "\n\n";
	for (int i = 0; i < 10; i++) {
		std::cout << "\n" << "Making sound for ";
		array[i]->makeSound();
		std::cout << "for type = " << array[i]->getType();
	}

	std::cout << "\n\nTesting brain \n";
	Cat cat("Jerry");
	cat.setIdea("Completely new and original idea", 0);
	std::cout << cat.getIdea(0) << "\n" << cat.getIdea(2) << std::endl;
	cat.setIdea("Gibberish", 999);
	std::cout << cat.getIdea(101) << std::endl;
	
	std::cout << "\n\ndestroying array \n";
	for (int i = 0; i < 10; i++) {
		delete array[i];
	}
	return 0;
}