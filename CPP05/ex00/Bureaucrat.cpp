/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:12:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/12/16 11:33:31 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Burry") {
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	if (grade > 150) {
		throw(Bureaucrat::GradeTooLowException());
	}
	if (grade < 1) {
		throw(Bureaucrat::GradeTooHighException());
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): _name(obj.getName()) {
	this->_grade = obj.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	this->_grade = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return (this->_name);	
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade += 1;
}
		
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is unfortunately too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is unfortunately too low");	
}		

std::ostream& operator<<(std::ostream &output, const Bureaucrat &obj) {
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade(); 
	return output;
}
