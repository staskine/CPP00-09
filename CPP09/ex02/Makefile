# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 11:21:06 by sataskin          #+#    #+#              #
#    Updated: 2025/05/12 10:55:04 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SOURCE = main.cpp PmergeMe.cpp

OBJECT = $(SOURCE:.cpp=.o)

HEADER = PmergeMe.hpp

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