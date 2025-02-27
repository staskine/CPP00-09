/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:36 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/27 13:41:11 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}
Intern& Intern::operator=(const Intern& obj) {
	*this = obj;
	return (*this);
}

Intern::~Intern() {}

static AForm *makePresidentialPardonForm(const std::string target) {
	try {
		return (new PresidentialPardonForm(target));
	}
	catch {
		throw newFailedException();
	}
}

static AForm *makeShrubberyCreationForm(const std::string target) {
	try {
		return (new ShrubberyCreationForm(target));
	}
	catch {
		throw newFailedException();
	}
}

static AForm *makeRobotomyRequestForm(const std::string target) {
	try {
		return (new RobotomyRequestForm(target));
	}
	catch {
		throw newFailedException();
	}
}

AForm Intern::*makeForm(std::string form, std::string target)
{
	
}