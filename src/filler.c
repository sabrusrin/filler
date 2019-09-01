/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/09/01 18:08:51 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	play(t_game *in)
{
	char	*line;
	int		val;

	line = NULL;
	while ((val = get_next_line(0, &line)))
	{
		if (val == -1)
			err_handle(2, in);
		if (ft_strstr(line, "Plateau"))
		{
			if (in->board.x == 0 && in->board.y == 0)
				dims(&line, &in->board.x, &in->board.y, 8);
			save_data(&(in->board), in, 4);
		}
		if (ft_strstr(line, "Piece"))
		{
			dims(&line, &in->tile.x, &in->tile.y, 6);
			save_data(&(in->tile), in, 0);
			player(in);
		}
		ft_strdel(&line);
	}
}

int		init_game(t_game *in)
{
	char *line;

	get_next_line(0, &line);
	if (line && (line[10] == '1' || line[10] == '2'))
	{
		in->player[0] = (ft_strstr(line, "p1")) ? 'O' : 'X';
		in->player[1] = (ft_strstr(line, "p1")) ? 'X' : 'O';
		ft_strdel(&line);
		in->board.data = NULL;
		in->tile.data = NULL;
		in->board.x = 0;
		in->board.y = 0;
		in->p.x = 0;
		in->p.y = 0;
		in->p.strategy = 1;
		return (1);
	}
	return (0);
}
