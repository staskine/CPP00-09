/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:05:07 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/21 17:15:39 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdint>

struct Data {
	int num;
	std::string text;
	Data(int n, const std::string& t) : num(n), text(t) {}
};

class Serializer {
	private:
	Serializer &operator=(const Serializer& obj);
	~Serializer();
	Serializer();
	Serializer(const Serializer& obj);
	
	public:
    	static uintptr_t serialize(Data* ptr);
    	static Data* deserialize(uintptr_t raw);
};