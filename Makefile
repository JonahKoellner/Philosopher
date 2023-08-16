# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 09:29:31 by jkollner          #+#    #+#              #
#    Updated: 2023/08/16 11:15:14 by jkollner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ------------------------ Compiler / Project -----------------------##
CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = philo

## ------------------------ Source / Objects / Files -----------------------##
SRC = philosopher.c utils.c behaviour.c graphics.c time.c death.c errors.c
OBJ = ${SRC:.c=.o}
## ------------------------ Libraries -----------------------##
PTHREAD = -pthread

## ------------------------ Commands -----------------------##

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $(FLAGS) $(PTHREAD) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $< -c -o $@

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: fclean
