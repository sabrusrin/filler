# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mkaefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chermist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 18:07:03 by chermist          #+#    #+#              #
#    Updated: 2019/09/03 18:01:33 by chermist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../resources/visu

CC = gcc

INCDIR = -I ../minilibx_macos -I ../libft/includes -I ../visu_inc

LIBDIR = -L ../minilibx_macos -L ../libft

LIB = -lft -lmlx

CFLAGS = -Wall -Werror -Wextra $(INCDIR)

FW = -framework OpenGL -framework AppKit

SRCDIR = src

SRC =	visu.c \
		win.c \
		draw.c \
		lists.c

OBJ = $(SRC:.c=.o)

vpath %.c $(SRCDIR)

all: DEPS $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INCDIR) $(LIBDIR) $(LIB) $(FW) $(OBJ) -o $@

DEPS:
	make -C ../libft/
	make -C ../minilibx_macos/

%.o: %.c %.h

clean:
	make -C ../libft $@
	make -C ../minilibx_macos $@
	rm -f $(OBJ)

fclean: clean
	make -C ../libft $@
	rm -f $(NAME)

re: fclean all
