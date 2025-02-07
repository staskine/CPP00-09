/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:44:24 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 13:55:23 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
*/
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this == &obj)
    {
        std::cout << "Copy operator was attempted on itself" << std::endl;
    }
    else
    {
        this->_target = obj.getTarget();
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
    this->_target = obj.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign())
    {
        if (this->getGradeToExecute() >= executor.getGrade())
        {
            std::cout << this->getTarget() << "*ANNOYING DRILLING SOUNDS*" << std::endl;
            std::srand(std::time(0));
                if (std::rand() % 2 == 1) {
                    std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
                }
                else {
                    std::cout << this->getTarget() << " robotomy has failed" << std::endl;
                }
        }
        else
            throw GradeTooLowException();
    }
    else
        throw FormNotSignedException();
}

