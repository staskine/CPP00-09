/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:22:50 by sataskin          #+#    #+#             */
/*   Updated: 2024/12/19 11:48:28 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Basic"), _gradeToSign(150), _gradeToExecute(150) {
	_signed = false;
}

Form::Form(std::string name, int sign, int execute): _name(name), _gradeToSign(sign), _gradeToExecute(execute) {
	_signed = false;
}

Form(const Form& obj);
Form& operator=(const Form& obj);
~Form();

const std::string getName() const;
const std::string getSign();
const int getGradeToSign() const;
const int getGradeToExecute() const;
		
Form::GradeTooHighException virtual const char* what() const throw();
		
class GradeTooLowException virtual const char* what() const throw();
		
void beSigned(Bureaucrat& obj) const;

std::ostream& operator<<(std::ostream &output, const Form &obj);