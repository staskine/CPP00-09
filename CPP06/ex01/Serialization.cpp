/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:12:05 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/21 17:20:13 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& obj) {(void)obj; }

Serializer &Serializer::operator=(const Serializer& obj) {
	(void)obj;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	if (ptr == nullptr)
		return 0;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	if (raw == 0)
		return nullptr;
    return reinterpret_cast<Data*>(raw);
}