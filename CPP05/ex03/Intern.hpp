/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:47:51 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:38 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern();

		AForm *makeForm(std::string form, std::string target);
};

#endif