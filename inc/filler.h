/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:06:55 by chermist          #+#    #+#             */
/*   Updated: 2019/08/03 01:00:27 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_data
{
	int			y;
	int			x;
	char		**data;
}				t_data;

typedef struct	s_game
{
	int			fd;
	int			fdm;
	char		player[2];
	int			**heat_map;
	t_data		board;
	t_data		tile;
}				t_game;

void			save_data(t_data*save, int flag, int fd, int fdm);
void			dims(char **line, int *x, int *y, int flag);
void			play(t_game *in);
int				init_game(t_game *in);
void			locate_players(t_game *in);
void			distance(t_game *in);
void			free_token(t_data *token, int flag);
void			heat_map(t_game *in);
void			distance(t_game *in);
unsigned long	atoi_move_hex(char **str);
int				atoi_move(char **str);

#endif
