/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:36 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/03 11:58:45 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}
Intern& Intern::operator=(const Intern& obj) {
	if (this != &obj)
		*this = obj;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::cout << "Form is " << form << std::endl; 
	for (int i = 0; i < 3; i++) {
		if (forms[i] == form) {
			switch (i) {
				case 0:
            	    return new ShrubberyCreationForm(target);
                case 1:
                	return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
                default:
                    std::cout << "This form does not exist";
			}
		}
	}
	std::cout << "Form: <" << form << "> does not exist" << std::endl;
	return nullptr;
}