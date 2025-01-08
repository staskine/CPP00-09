/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:23:51 by sataskin          #+#    #+#             */
/*   Updated: 2025/01/08 13:21:48 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "-> Making a Bureaucrat and incrementing and decrementing it" << std::endl;
		Bureaucrat Burry;
		std::cout << Burry << "\n-> will increment" << std::endl;
		Burry.incrementGrade();
		std::cout << "Now making a form" << std::endl;
		Form formy;
		std::cout << Burry << std::endl;
		std::cout << formy << std::endl;
		std::cout << "->Now I'm going to sign the form\n";
		formy.beSigned(Burry);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
/*
	try {
		std::cout << "\n\n\n" << "-> Making a bureaucrat with input" << std::endl;
		Bureaucrat Burton("Burton", 2);
		std::cout << Burton << "\n-> will increment" << std::endl;
		Burton.incrementGrade();
		std::cout << Burton << "\n-> will decrement" << std::endl;
		Burton.decrementGrade();
		std::cout << Burton << std::endl;
		std::cout << "-> Now I'm going to increment above the highest level\n";
		Burton.incrementGrade();
		Burton.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	try {
		std::cout << "\n\n\n-> I will now make a Bureaucrat that is above highest level\n";
		Bureaucrat Bur("Higih", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n\n\n-> I will now make a Bureaucrat that is below lowest level\n";
		Bureaucrat Bur("lowi", 166);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}*/
	return 0;
}	
