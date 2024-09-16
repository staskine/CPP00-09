/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:36:14 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 14:36:15 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string temp = "HI THIS IS BRAIN";
    std::string *stringPTR = &temp;
    std::string &stringREF = temp;

    std::cout << "The memory address of the string variable : " << &temp << std::endl;
    std::cout << "The memory address of stringPTR : " << &stringPTR << std::endl;
    std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;

    std::cout << "The value of the string variable : " << temp << std::endl;
    std::cout << "The value held by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value held by stringREF : " << stringREF << std::endl;
}
