/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:47:45 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/21 17:58:58 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base {
public:
    virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);