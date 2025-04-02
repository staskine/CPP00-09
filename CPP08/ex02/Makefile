# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 11:21:06 by sataskin          #+#    #+#              #
#    Updated: 2025/04/01 13:55:09 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutatedAbomination

SOURCE = main.cpp MutantStack.cpp

OBJECT = $(SOURCE:.cpp=.o)

HEADER = MutantStack.hpp

all: $(NAME)

$(NAME): $(OBJECT) $(HEADER)
	c++ -Wall -Wextra -Werror $(OBJECT) -o $(NAME)

%.o: %.cpp
	c++ -Wall -Wextra -Werror -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re