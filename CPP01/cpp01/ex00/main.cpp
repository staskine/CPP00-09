/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:35:09 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 14:35:13 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    try {
        Zombie* stack = newZombie("Jack");
        randomChump("Jill");
        stack->announce();
        delete stack;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}