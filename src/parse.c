/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:33 by chermist          #+#    #+#             */
/*   Updated: 2019/07/30 20:42:44 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_data(t_data *save, int flag, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = (!flag) ? save->y : save->y + 1;
	while (j--)
	{
		get_next_line(0, &line);
		if (line && (line[0] != ' ' || flag == 0))
			save->data[i++] = line + flag;
	}
}

void	dims(char **line, int *x, int *y, int flag)
{
	char	*tmp;
	
	tmp = *line;
	*line += flag;
	*y = atoi_move(line);
	*line += 1;
	*x = atoi_move((line));
	*line = tmp;
}

void	locate_players(t_game *in)
{
	int x;
	int	y;

	y = -1;
	while (++y < in->board.y)
	{
		x = -1;
		while (++x < in->board.x)
		{
			if ((in->board.data)[y][x] == in->player[0])
				(in->heat_map)[y][x] = -1;
			else if ((in->board.data)[y][x] == in->player[1])
				(in->heat_map)[y][x] = 0;
			else
				(in->heat_map)[y][x] = 1;	
		}
	}
	distance(in);
}

void	distance(t_game *in)
{
	int	x;
	int	y;
	int	xe;
	int	ye;
	int	val;

	y = -1;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
			if ((in->heat_map)[y][x] == 1 && !(val = 0))
			{
				ye = -1;
				while (++ye < in->board.y && (xe = -1))
					while (++xe < in->board.x)
						if ((in->heat_map)[ye][xe] == 0)
							val = (!val || val > sqrt(pow(ye - y, 2) + pow(xe - x, 2))) \
								  ? sqrt(pow(ye - y, 2) + pow(xe - x, 2)) : val;
				(in->heat_map)[y][x] = val;
			}
}
