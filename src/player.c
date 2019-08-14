/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:38:01 by chermist          #+#    #+#             */
/*   Updated: 2019/08/14 20:58:25 by chermist         ###   ########.fr       */
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
			if (in->heat_map[y][x][2] <= 10)
				return (2);
			else
				return (1);
		}
	return (0);
}

int	j	is_placeable(t_game *in, int y, int x)
{
	// 1 * should overlap
	// it should cover least possible fcost on the map 
	// try to fit  your figure around the coordinates passed
	int	i;
	int	j;
	int	ty;
	int	tx;
	int	offy;
	int	offx;
	int	cost;
	int	costp;
	int	star;

	offy = (y > 0 && in->heat_map[y - 1][x][0] > in->heat_map[y][x][0]) ? 1 : -1;
	offx = (x > 0 && in->heat_map[y][x - 1][0] > in->heat_map[y][x][0]) ? 1 : -1;
	ty = -1;
	cost = 0;
	costp = 0;
	while ((offy * ty + y) < (offy * in->tile.y + y) && (tx = -1)) //ty < in->tile.y && (tx = -1))
		while ((offy * ty + y) < (offy * in->tile.y + y)) //tx < in->tile.x)
		{
			if ((y + ty * offy) < in->board.y && (y + ty * offy) > 0 &&
				(x + tx * offx) < in->board.x && (x + tx * offx) > 0)
			{
				star = 0;
				i = -1; 
				while (i < in->tile.y && (j = -1) && star <= 1)
					while (j < in->tile.x && star <= 1)
					{
						if (in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][0] > 0 &&
							(in->tile.data[i][j] == '*'))
							costp += in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][2];
						else if (in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][0] == -1 &&
								(in->tile.data[i][j] == '*'))
							star++;
						else if (in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][0] == -1 &&
								(in->tile.data[i][j] == '*'))
							break ;
					}
				if (star == 1 && (!cost || cost > costp))
		 		{
					in->p.r_y = y + ty * offy;
					in->p.r_x = x + tx * offx;
					cost = costp;
				}
			}//save the optimal coordinates
//			[y + ty * offy][x + tx * offx] // here I have to check wether the token fits in place and overlaps one and only
				
			   //	cell of my territory and count cost covered by my figure
//			if (star == 1 && (!cost || cost > costp))
//				cost = costp;
		}

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
			   	in->heat_map[y][x][1] == 4) && // check how close i'm to the player
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
