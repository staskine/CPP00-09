/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:22:50 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/03 11:27:37 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Basic"), _gradeToSign(150), _gradeToExecute(150) {
	_signed = false;
}

AForm::AForm(std::string name, int sign, int execute): _name(name), _gradeToSign(sign), _gradeToExecute(execute) {
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	_signed = false;
}

AForm::AForm(const AForm& obj): _name(obj.getName()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute()) {
	_signed = false;
}

AForm& AForm::operator=(const AForm& obj) {
	_signed = obj.getSign();
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return (this->_name);
}

bool AForm::getSign() const {
	return (this->_signed);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}
		
const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high\n");
}
		
const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low\n");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form has not been signed\n");
}

const char* AForm::newFailedException::what() const throw() {
	return ("New failed\n");
}
		
void AForm::beSigned(const Bureaucrat& obj) {
	
	if (obj.getGrade() <= this->_gradeToSign)
		_signed = true;
	else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &output, const AForm &obj) {
	std::string amISigned = "false";
	if (obj.getSign() == true)
		amISigned = "true";
	output << "Form name: " << obj.getName() << "\nForm grade to sign: " << obj.getGradeToSign() << "\nForm signed: " << amISigned << "\nAnd grade to execute: " << obj.getGradeToExecute() << std::endl;
	return output; 
}
