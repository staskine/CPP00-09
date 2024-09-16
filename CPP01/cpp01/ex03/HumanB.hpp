/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:36:36 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 14:36:37 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB(std::string name);
        void attack();
        ~HumanB();
        void setWeapon(Weapon& weapon);
};

#endif