# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assabich <assabich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/08 15:10:10 by assabich          #+#    #+#              #
#    Updated: 2026/03/09 18:07:29 by assabich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

FLAG = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	BitcoinExchange.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		c++ $(FLAG) -o $(NAME) $(OBJS)
		
%.o: %.cpp
		c++ $(FLAG) -c $< -o $@
		
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
