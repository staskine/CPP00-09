/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:22:50 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/06 14:19:15 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Basic"), _gradeToSign(150), _gradeToExecute(150) {
	_signed = false;
}

Form::Form(std::string name, int sign, int execute): _name(name), _gradeToSign(sign), _gradeToExecute(execute) {
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	_signed = false;
}

Form::Form(const Form& obj): _name(obj.getName()), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute()) {
	_signed = false;
}

Form& Form::operator=(const Form& obj) {
	_signed = obj.getSign();
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSign() const {
	return (this->_signed);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}
		
const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high\n");
}
		
const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low\n");
}
		
void Form::beSigned(Bureaucrat& obj) {
	
	if (obj.getGrade() <= this->_gradeToSign)
		_signed = true;
	obj.signForm(*this);
	if (_signed == false) {
		throw GradeTooLowException();
	}
	
}

std::ostream& operator<<(std::ostream &output, const Form &obj) {
	std::string amISigned = "false";
	if (obj.getSign() == true)
		amISigned = "true";
	output << "Form name: " << obj.getName() << "\nForm grade to sign: " << obj.getGradeToSign() << "\nForm signed: " << amISigned << "\nAnd grade to execute: " << obj.getGradeToExecute() << std::endl;
	return output; 
}
