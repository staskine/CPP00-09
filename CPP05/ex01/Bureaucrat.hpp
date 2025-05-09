/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:11:21 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/06 14:39:32 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


# include <exception>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int 				_grade; // 1 highest and 150 lowest

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void signForm(Form& obj) const;
};

std::ostream& operator<<(std::ostream &output, const Bureaucrat &obj);

#endif