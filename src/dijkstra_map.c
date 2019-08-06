/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:57:25 by chermist          #+#    #+#             */
/*   Updated: 2019/08/07 01:21:02 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	heat_map(t_game *in)
{
	int			y;
	static int	inited = 0;

	y = 0;
	if (!inited)
	{
		if (!(in->heat_map = (int**)malloc(sizeof(int *) * in->board.y)))
			exit(1);
		while (y < in->board.y)
			if (!(in->heat_map[y++] = (int *)malloc(sizeof(int) * in->board.x)))
				exit(1);
		inited = 1;
	}
	locate_players(in);
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
			if ((in->board.data)[y][x] == in->player[0] ||
					(in->board.data)[y][x] == in->player[0] + 32)
				(in->heat_map)[y][x] = -1;
			else if ((in->board.data)[y][x] == in->player[1] ||
					(in->board.data)[y][x] == in->player[1] + 32)
				(in->heat_map)[y][x] = 0;
			else
				((in->heat_map)[y])[x] = 1;
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
