/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:35:52 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 16:30:56 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    try {
        Zombie* horde = zombieHorde(10, "Jack");
        for (int i = 0; i < 10; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}