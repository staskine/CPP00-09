/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:42:37 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/03 11:53:56 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string		_name;
		bool					_signed;
		const int 				_gradeToSign; // 1 highest and 150 lowest
		const int				_gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int sign, int execute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();

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

		class FormNotSignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class newFailedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		void beSigned(const Bureaucrat& obj);	
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &output, const AForm &obj);

#endif
