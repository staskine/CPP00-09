/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:36:40 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 14:36:41 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club1 = Weapon("Chainsaw");
        HumanA bob("Bob", club1);
        bob.attack();
        club1.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club2 = Weapon("Throwing stars");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club2);
        jim.attack();
        club2.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
