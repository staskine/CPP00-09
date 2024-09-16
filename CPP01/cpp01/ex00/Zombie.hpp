/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:35:44 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 16:27:59 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();
        void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif