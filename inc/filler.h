/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:06:55 by chermist          #+#    #+#             */
/*   Updated: 2019/07/22 19:03:02 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_map
{
	int 		me;
	int			y;
	int			x;
	int			tx;
	int			ty;
	int			fd;
	char		player[2];
	char		*board;
	char		*tile;
}				t_map;

void			place_token(t_map *in);
void			save_data(char **save, int x, int y, int flag, int fd);
void			dims(char **line, int *x, int *y, int flag);
void			play(t_map *in);
int				init_game(t_map *in);
unsigned long	atoi_move_hex(char **str);
int				atoi_move(char **str);

#endif
