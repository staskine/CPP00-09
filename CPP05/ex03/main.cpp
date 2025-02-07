/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:23:51 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 14:03:54 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		std::cout << "-> Making a Bureaucrat and incrementing and decrementing it" << std::endl;
		Bureaucrat Burry;
		std::cout << Burry << "\n-> will increment" << std::endl;
		Burry.incrementGrade();
		std::cout << "Now making a Form" << std::endl;
		PresidentialPardonForm Formy("Sahra");
		std::cout << Burry << std::endl;
		std::cout << Formy << std::endl;
		std::cout << "->Now I'm going to sign the Form\n";
		Formy.beSigned(Burry);
		std::cout << "\n" << Formy << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n\n----------------------------------------------------\n\n";
	try {
		Bureaucrat Burry("Burry", 1);
		PresidentialPardonForm Form1("Sahra");
		std::cout << "->Now I will try to sign a Form that can be signed & executed by Bureaucrat\n" << std::endl;
		std::cout << Burry << "\n" << std::endl;
		std::cout << Form1 << std::endl;
		Form1.beSigned(Burry);
		Burry.executeForm(Form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n----------------------------------------------------\n\n";

	try {
		Bureaucrat Burry("Burry", 10);
		PresidentialPardonForm Form1("Sahra");
		
		std::cout << Burry << "\n" << std::endl;
		std::cout << Form1 << std::endl;
		Form1.beSigned(Burry);
		std::cout << "->Now I will try to execute a Form that can't be executed by Bureaucrat\n" << std::endl;
		Burry.executeForm(Form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n\n----------------------------------------------------\n\n";

	try {
		Bureaucrat Burry("Burry", 70);
		RobotomyRequestForm Form1("Sahra");
		std::cout << Burry << "\n" << std::endl;
		std::cout << Form1 << std::endl;
		Form1.beSigned(Burry);
		std::cout << "->Now I will try to execute a Form that can't be executed by Bureaucrat\n" << std::endl;
		Burry.executeForm(Form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n----------------------------------------------------\n\n";

	try {
		Bureaucrat Burry("Burry", 10);
		RobotomyRequestForm Form1("Sahra");
		
		std::cout << Burry << "\n" << std::endl;
		std::cout << Form1 << std::endl;
		Form1.beSigned(Burry);
		std::cout << "->Now I will try to execute a Form that can be executed by Bureaucrat\n" << std::endl;
		Burry.executeForm(Form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

		std::cout << "\n\n----------------------------------------------------\n\n";

	try {
		Bureaucrat Burry("Burry", 142);
		ShrubberyCreationForm Form1("Sahra");
		std::cout << Burry << "\n" << std::endl;
		std::cout << Form1 << std::endl;
		Form1.beSigned(Burry);
		std::cout << "->Now I will try to execute a Form that can't be executed by Bureaucrat\n" << std::endl;
		Burry.executeForm(Form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n----------------------------------------------------\n\n";

	try {
		Bureaucrat Burry("Burry", 10);
		ShrubberyCreationForm Form1("Sahra");
		
		std::cout << Burry << "\n" << std::endl;
		std::cout << Form1 << std::endl;
		Form1.beSigned(Burry);
		std::cout << "->Now I will try to execute a Form that can be executed by Bureaucrat\n" << std::endl;
		Burry.executeForm(Form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}	
