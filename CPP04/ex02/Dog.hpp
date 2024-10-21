/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:51:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/03 17:43:31 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &obj);
		Dog& operator=(const Dog& obj);
		~Dog();

		void makeSound() const override;
		std::string getIdea(unsigned int i);
		void setIdea(std::string brainfart, unsigned int i);
};

#endif