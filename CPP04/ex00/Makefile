# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 10:30:53 by sataskin          #+#    #+#              #
#    Updated: 2024/10/02 11:37:27 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Simos

SOURCE = main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

OBJECT = $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	c++ -Wall -Wextra -Werror $(OBJECT) -o $(NAME)

%.o: %.cpp
	c++ -Wall -Wextra -Werror -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re