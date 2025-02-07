/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:17 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 13:21:47 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
    this->_target = target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    if (this == &obj) {
		std::cout << "Copy operator was attempted on itself" << std::endl;
	}
	else {
        this->_target = obj.getTarget();
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj) {
    this->_target = obj.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm() {
}
    
const std::string PresidentialPardonForm::getTarget() const {
    return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign())
    {
        if (this->getGradeToExecute() >= executor.getGrade())
        {
            std::cout <<  this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        }
        else
            throw GradeTooLowException();
    }
    else
        throw FormNotSignedException();
}
