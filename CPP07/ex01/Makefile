# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 11:21:06 by sataskin          #+#    #+#              #
#    Updated: 2025/02/20 12:01:41 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Whatever

SOURCE = main.cpp

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