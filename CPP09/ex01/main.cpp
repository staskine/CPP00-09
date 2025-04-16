/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:23:35 by sataskin          #+#    #+#             */
/*   Updated: 2025/04/16 17:03:38 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Incorrect value of arguments" << std::endl;
		return 1;
	}
    std::regex pattern(R"(^(-?\d+|\+|\-|\*|\/)(\s+(-?\d+|\+|\-|\*|\/))*$)");
    std::string input = argv[1];

    if (std::regex_match(input, pattern)) {
        calculator(input);
    } else {
        std::cerr << "Error\n";
		return 1;
    }
    return 0;
}