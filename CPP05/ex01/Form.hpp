/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:42:37 by sataskin          #+#    #+#             */
/*   Updated: 2025/01/08 13:27:00 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string		_name;
		bool					_signed;
		const int 				_gradeToSign; // 1 highest and 150 lowest
		const int				_gradeToExecute;
	public:
		Form();
		Form(std::string name, int sign, int execute);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();

		std::string getName() const;
		bool getSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		void beSigned(Bureaucrat& obj);	
};

std::ostream& operator<<(std::ostream &output, const Form &obj);

#endif
