# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mkaefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chermist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 18:07:03 by chermist          #+#    #+#              #
#    Updated: 2019/09/01 02:59:17 by chermist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/chermist.filler

CC = gcc

INCDIR = -I libft/includes -I inc

LIBDIR = -L libft

LIB = -lft

CFLAGS = -Wall -Werror -Wextra $(INCDIR)

SRCDIR = src

SRC =	main.c			\
		filler.c		\
		parse.c			\
		dijkstra_map.c	\
		support.c		\
		player.c

OBJ = $(SRC:.c=.o)

vpath %.c $(SRCDIR)

all: DEPS $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INCDIR) $(LIBDIR) $(LIB) $(OBJ) -o $@

DEPS:
	make -C libft/

%.o: %.c %.h

clean:
	make -C libft $@
	rm -f $(OBJ)

fclean: clean
	make -C libft $@
	rm -f $(NAME)

re: fclean all
