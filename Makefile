# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mkaefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chermist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 18:07:03 by chermist          #+#    #+#              #
#    Updated: 2019/08/15 18:19:19 by chermist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/rust.filler

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
#		read_line.c		\

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
