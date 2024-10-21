/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:54:20 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/02 15:09:58 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Making Animal class" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "\nMaking an Animal class pointer to Dog Class" << std::endl;
	const Animal* j = new Dog();
	std::cout << "\nMaking an Animal class pointer to Dog Class" << std::endl;
	const Animal* i = new Cat();
	std::cout << "\n\n";
	
	std::cout << "Printing out types" << std::endl;
	std::cout << "type for Dog is = " << j->getType() << " " << std::endl;
	std::cout << "type for Cat is = " << i->getType() << " "  << std::endl;
	std::cout << "type for Animal is = " << meta->getType() << " "  << std::endl;
	std::cout << "\n\n";
	
	std::cout << "Printing out sounds" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "order above was cat, dog, animal" << std::endl;
	std::cout << "\n\n";
	
	std::cout << "Making wrong ones" << std::endl;
	const WrongAnimal* cat = new WrongCat();
	std::cout << "type for WrongAnimal is = " << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << "\n\n";
	
	Cat hello;
	const Animal* test = new Cat(hello);
	std::cout << "type for copyconsructor is = " << test->getType() << " " << std::endl;
	test->makeSound();
	
	std::cout << "\n\n";
	delete cat;
	std::cout << "\n";
	delete meta;
	std::cout << "\n";
	delete j;
	std::cout << "\n";
	delete i;
	std::cout << "\n";
	delete test;
	std::cout << "\n";
	return 0;
}