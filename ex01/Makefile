# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assabich <assabich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/10 18:06:18 by assabich          #+#    #+#              #
#    Updated: 2026/05/10 18:14:41 by assabich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

FLAG = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		rpn.cpp \

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

re:	fclean all

.PHONY: re clean fclean all