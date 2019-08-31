/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:38:01 by chermist          #+#    #+#             */
/*   Updated: 2019/08/31 00:42:50 by chermist         ###   ########.fr       */
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
			if (in->heat[y][x][2] != -1 && in->heat[y][x][2] < 4)// != 0
				return (2);
		//	else
		//		return (1);
		}
	return (1);
}

int		is_placeable(t_game *in, int y, int x, int *cost, int flag)
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
	int	costp;
	int	star;

	if (flag)
	{
		offy = (y > 0 && in->heat[y - 1][x][0] > in->heat[y][x][0]) ? 1 : -1;
		offx = (x > 0 && in->heat[y][x - 1][0] > in->heat[y][x][0]) ? 1 : -1;
	}
	else
	{
			offy = 1;
			offx = 1;
	}
	ty = -1;
	costp = 0;
	star = 0;
	while (++ty < in->tile.y && (tx = -1))//move token up-down left-right
		while (++tx <= in->tile.x)
		{
			if ((in->tile.y + y + ty * offy) <= in->board.y && (y + ty * offy) >= 0 &&
				(in->tile.x + x + tx * offx) <= in->board.x && (x + tx * offx) >= 0)
			{
				costp = 0;
				star = 0;
				i = -1; 
				while (++i < in->tile.y && (j = -1) && star <= 1)// is placeable
					while (++j < in->tile.x && star <= 1)
					{	
						if (in->heat[(y + ty * offy) + i][(x + tx * offx) + j][0] > 0 &&
							(in->tile.data[i][j] == '*'))
							costp += in->heat[(y + ty * offy) + i][(x + tx * offx) + j][flag];// changing here to 0, was 2
						else if (in->heat[(y + ty * offy) + i][(x + tx * offx) + j][0] == -1 &&
								(in->tile.data[i][j] == '*'))
							star++;
						else if (in->heat[(y + ty * offy) + i][(x + tx * offx) + j][0] == 0 &&
								(in->tile.data[i][j] == '*'))
						{
						 	star = 2;
							break ;
						}
					}
				if (star == 1 && (!*cost || *cost > costp))
		 		{
					in->p.y = y + ty * offy;
					in->p.x = x + tx * offx;
					*cost = costp;
//					ft_putnbr_fd(*cost, in->fd);
//					ft_putchar_fd('\n', in->fd);
				}
			}
		}
	return (star == 1 ? 1 : 0);

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

void	tkn_sz(t_game *in)
{
//	int g;

	in->p.k = (in->tile.y >= in->tile.x) ? in->tile.y : in->tile.x;
	if (in->p.k > 7)
		in->p.k /= 2;
/*	if (g <= 3)
		in->p.k = 8;
	else if (g <= 7)
		in->p.k = 14;
	else if (g <= 11)
		in->p.k = 24;
	else 
		in->p.k = 31;*/
}

int		approach(t_game *in)
{
	int	x;
	int	y;
	int	fcost;
	int	cost;

	y = -1;
	cost = 0;
	fcost = 0;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
			if ((in->heat[y][x][0] > 0) && // check for figure
				(in->heat[y][x][1] < 1000) &&
				(in->heat[y][x][1] <= in->p.k)) // check how close i'm to the player // check if i should consider this cell
				if ((!fcost || (fcost > in->heat[y][x][2]) ||
					((fcost == in->heat[y][x][2]) &&
					(in->heat[in->p.p_y][in->p.p_x][0] >
					 in->heat[y][x][0]))) &&
					is_placeable(in, y, x, &cost, 2))
					{
//						ft_putstr_fd("!here!", in->fd);
						in->p.p_y = y;
						in->p.p_x = x;
						fcost = in->heat[y][x][2];
					}
	// should make a last try function
	return (cost);
}

int		surround(t_game *in)
{
	int x;
	int y;
	int	cost;
	int	hcost;

	hcost = 0;
	cost = 0;
	y = -1;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
			if ((in->heat[y][x][0] > 0) && // check for figure
				(in->heat[y][x][1] < 1000) &&
				(in->heat[y][x][1] <= in->p.k))
					is_placeable(in, y, x, &cost, 0);
	return (cost);
}

void	player(t_game *in)
{
	int	strategy;
	int	place;

	strategy = check_map(in);
	place = 0;
	tkn_sz(in);
//	size_fig(in);
	if (strategy == 1)// !approached
		place = approach(in);
	else if (strategy == 2)
	{
		ft_putstr_fd("SURROUND\n", in->fd);
		place = surround(in);
	}
	if (place)
	{
		ft_putstr_fd("placed\n", in->fd);
		ft_putnbr(in->p.y);
		ft_putchar(' ');
		ft_putnbr(in->p.x);
		ft_putchar('\n');
	}
	else
		exit (1);

//	else if (strategy == 2)// approached
//		conquer(in);
//	else
//		fill(in);
}
