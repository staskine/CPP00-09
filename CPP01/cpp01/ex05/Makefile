# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:37:24 by sataskin          #+#    #+#              #
#    Updated: 2024/09/16 14:37:25 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl2.0

SOURCE = main.cpp \
			Harl.cpp

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