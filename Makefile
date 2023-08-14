# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 09:29:31 by jkollner          #+#    #+#              #
#    Updated: 2023/08/14 08:58:22 by jkollner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ------------------------ Compiler / Project -----------------------##
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = philosopher.a

## ------------------------ Source / Files -----------------------##
SRC = philosopher.c utils.c behaviour.c graphics.c time.c death.c

## ------------------------ Libraries -----------------------##
PTHREAD = -pthread

## ------------------------ Commands -----------------------##

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(PTHREAD) $(SRC) -o $(NAME)

re: fclean all

clean:

fclean:
	rm $(NAME)

.PHONY: fclean
