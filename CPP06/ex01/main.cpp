/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:18:28 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/21 17:28:31 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main() {
    Data originalData(42, "This is a test string!");
	Data copyCat(41, "I am a copycat!");
	Data realCat(41, "I am a real cat!");

    // convert pointer to uintptr_t
    uintptr_t serialized = Serializer::serialize(&originalData);

    // Deserialize the uintptr_t back to a Data pointer
    Data* deserializedData = Serializer::deserialize(serialized);

    // Check if the original pointer and the deserialized pointer are the same
    if (&originalData == deserializedData) {
        std::cout << "Serialization and Deserialization successful!" << std::endl;
        std::cout << "Data: " << deserializedData->num << ", " << deserializedData->text << std::endl;
    } else {
        std::cout << "Failed to correctly deserialize the pointer!" << std::endl;
    }

	//uintptr_t realSerialized = Serializer::serialize(&copyCat);
	uintptr_t copySerialized = Serializer::serialize(&realCat);
	
	//Data* realdeserializedData = Serializer::deserialize(realSerialized);
	Data* copydeserializedData = Serializer::deserialize(copySerialized);
 
	if (&copyCat == copydeserializedData) {
		std::cout << "Serialization and Deserialization successful!" << std::endl;
	} else {
		std::cout << "Failed to correctly deserialize the pointer!" << std::endl;
	}

    return 0;
}