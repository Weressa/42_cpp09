# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assabich <assabich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 20:58:51 by assabich          #+#    #+#              #
#    Updated: 2026/06/02 17:49:54 by assabich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

FLAG = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		PmergeMe.cpp \

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
