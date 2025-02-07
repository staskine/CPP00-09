/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:36 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 14:59:19 by sataskin         ###   ########.fr       */
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

AForm Intern::*makeForm(std::string form, std::string target)
{
	
}