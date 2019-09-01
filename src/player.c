/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:38:01 by chermist          #+#    #+#             */
/*   Updated: 2019/09/01 02:54:14 by chermist         ###   ########.fr       */
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
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
		{
			if (in->heat[y][x][2] != -1 && in->heat[y][x][2] < 4)
				return (2);
		}
	return (1);
}

void	size_fig(t_game *in)
{
	int	x;
	int	y;
	int	val;

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

int		is_valid(t_game *in, int y, int x, int flag)
{
	int	i;
	int j;
	int	star;
	int	cost;

	i = -1;
	cost = 0;
	star = 0;
	while (++i < in->tile.y && (j = -1) && star <= 1)
		while (++j < in->tile.x && star <= 1)
		{
			if (in->heat[y + i][x + j][0] > 0 && (in->tile.data[i][j] == '*'))
				cost += in->heat[y + i][x + j][flag];
			else if (in->heat[y + i][x + j][0] == -1 &&
					(in->tile.data[i][j] == '*'))
				star++;
			else if (in->heat[y + i][x + j][0] == 0 &&
				(in->tile.data[i][j] == '*'))
			{
				star = 2;
				break ;
			}
		}
	return (star == 1 ? cost : 0);
}

int		is_placeable(t_game *in, int flag)
{
	int	x;
	int	y;
	int	cost;
	int	costs;

	y = -1;
	costs = 0;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
			if ((in->tile.y + y) < in->board.y &&
				(in->tile.x + x) < in->board.x)
			{
				if ((cost = is_valid(in, y, x, flag)))
					if (!costs || cost < costs)
					{
						in->p.y = y;
						in->p.x = x;
						costs = cost;
					}
			}
	return (costs);
}

void	player(t_game *in)
{
	int	strategy;
	int	place;

	heat_map(in);
	strategy = check_map(in);
	place = 0;
//	size_fig(in);
	if (strategy == 1)//apr
		place = is_placeable(in, 2);
	else if (strategy == 2)
	{
		place = is_placeable(in, 0);// or 2
	}
	if (place)
	{
		ft_putnbr(in->p.y);
		ft_putchar(' ');
		ft_putnbr(in->p.x);
		ft_putchar('\n');
	}
	else
		exit(1);
}
