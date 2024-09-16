/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:36:54 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 14:36:55 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
    private:
        std::string type;

    public:
        Weapon(std::string name);
        Weapon();
        const std::string &getType() const;
        void setType(std::string type);
        ~Weapon();
};

#endif
