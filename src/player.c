/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:38:01 by chermist          #+#    #+#             */
/*   Updated: 2019/08/11 00:29:53 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_map(t_game *in)
{
	int	x;
	int	y;
	int	val;

	val = 0;
	y = -1;
	while (++y < in->board.y)
		while (++x < in->board.x)
			if (in->heat_map[y][x][1] == 1)
}

void	is_placeable(t_game *in)
{
	void
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

int		approach(t_game *in)
{
	int	x;
	int	y;
	int	fcost;
	int	hcost;

	y = -1;
	fcost = 0;
	hcost = 0;
	while (++y < in->board.y)
	{
		x = -1;
		while (++x < in->board.x)
		{
			if ((in->heat_map[y][x][0] > 0) &&
				(in->heat_map[y][x][1] == 1) &&
				(!fcost || fcost >= in->heat_map[y][x][2]))
				if (fcost == in->heat_map[y][x][2])
				//if found the same fcost => check for hcost
				fcost = in->he
		}
	}
}

void	player(t_game *in)
{
	static int	approached = 0;

	check_map(in);
	if (!approached)// !approached
		approached = approach(in);
	else // approached
		surround(in);
}
