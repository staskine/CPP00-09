/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:59:01 by sataskin          #+#    #+#             */
/*   Updated: 2025/02/07 13:53:08 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>

class RobotomyRequestForm: public AForm {
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        ~RobotomyRequestForm();

        const std::string getTarget() const;

        void execute(Bureaucrat const & executor) const override;

    private:
        std::string _target;
};

#endif