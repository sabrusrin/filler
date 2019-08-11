/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:38:01 by chermist          #+#    #+#             */
/*   Updated: 2019/08/11 17:25:29 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_map(t_game *in)
{
	int	x;
	int	y;
	int	val;

	val = 0;
	y = -1;
	while (++y < in->board.y)
		while (++x < in->board.x)
		{
			if (in->heat_map[y][x][2] <= 7)
				return (2);
			else
				return (1);
		}
	return (0);
}

void	is_placeable(t_game *in)
{
	// 1 * should overlap
	// 
}

void	size_fig(t_game *in)
{
	int	x;
	int	y;

	in->p.r_x = 0;
	in->p.r_x = 0;
	y = -1;
	while (++y < in->tile.y)
	{
		val = 0;
		x = -1;
		while (++x < in->tile.x)
			if (in->tile.data[y][x] == '*')
				val++;
		in->p.r_x = (in->p.r_x < val) ? val : in->p.r_x;
		in->p.r_y += (val) ? 1 : 0;
	}
}

void	approach(t_game *in)
{
	int	x;
	int	y;
	int	fcost;
	int	hcost;

	y = -1;
	fcost = 0;
	hcost = 0;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
			if ((in->heat_map[y][x][2] > 0) && // check for figure
				(in->heat_map[y][x][1] == 3 ||
			   	in->heat_map[y][x][1] == 4) && // check how close i'm to player
				(!fcost || fcost >= in->heat_map[y][x][2])) // check if i should consider this cell
				if ((fcost > in->heat_map[y][x][2]) ||
					((fcost == in->heat_map[y][x][2]) &&
					(in->heat_map[in->p.p_y][in->p.p_x][0] >
					 in->heat_map[y][x][0])) &&
					is_placeable(in, y, x))
					{
						in->p.p_y = y;
						in->p.p_x = x;
						fcost = in->heat_map[y][x][2];
					}
	place_fig(in);
}

void	player(t_game *in)
{
	int	strategy;

	strategy = check_map(in);
	size_fig(in);
	if (strategy == 1)// !approached
		approach(in);
	else if (strategy == 2)// approached
		surround(in);
	else
		fill(in);
}
