# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chermist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 18:07:03 by chermist          #+#    #+#              #
#    Updated: 2019/12/16 15:31:51 by chermist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/chermist.filler

CC = gcc

INCDIR = -I libft/includes -I inc

LIBDIR = -L libft

LIB = -lft

CFLAGS = -Wall -Werror -Wextra -Ofast $(INCDIR)

SRCDIR = src

SRC =	main.c			\
		filler.c		\
		parse.c			\
		wave_map.c	\
		support.c		\
		player.c

OBJ = $(SRC:.c=.o)

vpath %.c $(SRCDIR)

all: DEPS $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) $(LIB) $(OBJ) -o $@

linux:
	make -C libft/
	make -C visualizer linux

DEPS:
	make -C libft/
	make -C visualizer/

%.o: %.c %.h

clean:
	make -C libft $@
	make -C visualizer $@
	rm -f $(OBJ)

fclean: clean
	make -C libft $@
	make -C visualizer $@
	rm -f $(NAME)

re: fclean all
