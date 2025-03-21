/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:46:50 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/21 17:53:21 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base* obj = generate();

    std::cout << "Pointer identification: ";
    identify(obj);

    std::cout << "Reference identification: ";
    identify(*obj);

    delete obj;
    return 0;
}