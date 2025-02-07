/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:23:51 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/06 14:39:32 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "-> Making a Bureaucrat and incrementing and decrementing it" << std::endl;
		Bureaucrat Burry;
		std::cout << Burry << "\n-> will increment" << std::endl;
		Burry.incrementGrade();
		std::cout << "Now making a Form" << std::endl;
		Form Formy;
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
	
	try {
		Bureaucrat Burry("Burry", 20);
		Form Form1("Important Form", 1, 1);
		std::cout << "->Now I will try to sign a Form that can't be signed by Bureaucrat\n" << std::endl;
		std::cout << Burry << "\n" << std::endl;
		std::cout << Form1 << std::endl;
		Form1.beSigned(Burry);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}	
