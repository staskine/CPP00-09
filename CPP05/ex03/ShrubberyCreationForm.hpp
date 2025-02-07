/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:59:01 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 14:13:41 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm {
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();
    
        const std::string getTarget() const;
    
        void execute(Bureaucrat const & executor) const override;
    
    private:
        std::string _target;
};

#endif