/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:37:47 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/03 17:34:26 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &obj);
		Cat& operator=(const Cat& obj);
		~Cat();
		
		void makeSound() const override;
		std::string getIdea(unsigned int i);
		void setIdea(std::string brainfart, unsigned int i);
};

#endif