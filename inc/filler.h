/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:06:55 by chermist          #+#    #+#             */
/*   Updated: 2019/07/23 20:49:37 by chermist         ###   ########.fr       */
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

typedef struct	s_tile
{
	int		y;
	int		x;
	char	**token;
}				t_tile;

typedef struct	s_map
{
	int			y;
	int			x;
	int			fd;
	char		player[2];
	char		**board;
}				t_map;

void			save_data(char ***save, int x, int y, int flag, int fd);
void			dims(char **line, int *x, int *y, int flag);
void			play(t_map *in, t_tile *tile);
int				init_game(t_map *in, t_tile *tile);
unsigned long	atoi_move_hex(char **str);
int				atoi_move(char **str);

#endif
