/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:36:05 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 16:29:40 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        void setname(std::string name);
        Zombie();
        ~Zombie();
        void announce();
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif