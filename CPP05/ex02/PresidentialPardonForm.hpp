/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:50:27 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 12:47:39 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
        PresidentialPardonForm(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();
    
        const std::string getTarget() const;
    
        void execute(Bureaucrat const & executor) const override;
    
    private:
        std::string _target;
};

#endif