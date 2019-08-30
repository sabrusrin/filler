/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:57:25 by chermist          #+#    #+#             */
/*   Updated: 2019/08/31 00:52:37 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	locate_players(t_game *in)
{
	int x;
	int	y;

	y = -1;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
		{
			if (in->board.data[y][x] == in->player[0])
			{
				in->heat[y][x][0] = -1;
				in->heat[y][x][1] = 0;
			}
			else if (in->board.data[y][x] == in->player[1] ||
					in->board.data[y][x] == in->player[1] + 32)
			{
				in->heat[y][x][0] = 0;
				in->heat[y][x][1] = -1;
			}
			else
			{
				in->heat[y][x][0] = 1000;
				in->heat[y][x][1] = 1000;
			}
		}
}

void	mark_map(t_game *in, int y, int x, int f)
{/*
	ft_putnbr_fd(y, in->fd);
	ft_putchar_fd(' ', in->fd);
	ft_putnbr_fd(x, in->fd);
	ft_putchar_fd('\n', in->fd);
*/	if (x + 1 < in->board.x && in->heat[y][x + 1][f] == 1000)
		in->heat[y][x + 1][f] = in->d;
	if (x - 1 >= 0 && in->heat[y][x - 1][f] == 1000)
		in->heat[y][x - 1][f] = in->d;
	if (y + 1 < in->board.y && in->heat[y + 1][x][f] == 1000)
		in->heat[y + 1][x][f] = in->d;
	if (y - 1 >= 0 && in->heat[y - 1][x][f] == 1000)
		in->heat[y - 1][x][f] = in->d;
	if (y - 1 >= 0 && x + 1 < in->board.x && in->heat[y - 1][x + 1][f] == 1000)
		in->heat[y - 1][x + 1][f] = in->d;
	if (y - 1 >= 0 && x - 1 >= 0 && in->heat[y - 1][x - 1][f] == 1000)
		in->heat[y - 1][x - 1][f] = in->d;
	if (y + 1 < in->board.y && x - 1 >= 0 && in->heat[y + 1][x - 1][f] == 1000)
		in->heat[y + 1][x - 1][f] = in->d;
	if (y + 1 < in->board.y && x + 1 < in->board.x && in->heat[y + 1][x + 1][f] == 1000)
		in->heat[y + 1][x + 1][f] = in->d;
}
void	wave_algo(t_game *in)
{
	int	y;
	int	x;
	int	d;
	int i;

	in->d = 0;
	d = 1000;
	i = 0;
	while (d && i < in->board.x)
	{
		i = in->d++;
		d = 0;
		y = -1;
	//	ft_putnbr_fd(i, in->fd);
	//	ft_putchar_fd('\n', in->fd);
		while (++y < in->board.y && (x = -1))
			while (++x < in->board.x)
			{
				if (in->heat[y][x][0] == 1000 || in->heat[y][x][1] == 1000)
					d = 1000;
				if (in->heat[y][x][0] == i)
					mark_map(in, y, x, 0);
				if (in->heat[y][x][1] == i)
					mark_map(in, y, x, 1);
				in->heat[y][x][2] = in->heat[y][x][0] + in->heat[y][x][1];
			}
	}
}

void	distance(t_game *in, int x, int y)
{//THIS FRICKING FUNCTION TAKES TOO MUCH TIME
	int	xe;
	int	ye;
	int	hv;
	int	gv;

	hv = 0;
	gv = 0;
	ye = -1;
	while (++ye < in->board.y && (xe = -1))
		while (++xe < in->board.x)
		{
			if (in->heat[ye][xe][0] == 0) // enemy
				hv = (!hv || hv > ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))))
				? ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))) : hv;
			if (in->heat[ye][xe][1] == 0)// multiplied here by 10
				gv = (!gv || gv > ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))))
				? ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))) : gv;
		}
	in->heat[y][x][0] = hv;
	in->heat[y][x][1] = gv;
}

void	fill_cell(t_game *in)
{
	int	x;
	int	y;
	int	*fcost;

	y = -1;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
		{
			fcost = in->heat[y][x];
			if (in->heat[y][x][0] == 1000)
			{
				distance(in, x, y);
				fcost[2] = fcost[0] + fcost[1];
			}
			else
				fcost[2] = 0;
		}
}

void	heat_map(t_game *in)
{
	int			x;
	int			y;
	static int	inited = 0;

	y = -1;
	if (!inited)
	{
		if (!(in->heat = (int***)malloc(sizeof(int**) * in->board.y)))
			exit(1);
		while (++y < in->board.y)
		{
			if (!(in->heat[y] = (int**)malloc(sizeof(int*) * in->board.x)))
				exit(1);
			x = -1;
			while (++x < in->board.x)
				if (!(in->heat[y][x] = (int*)malloc(sizeof(int) * 3)))
					exit(1);
		}
		inited = 1;
	}
	locate_players(in);
	wave_algo(in);
//	fill_cell(in);
	ft_putstr_fd("|0|\n", in->fd);
	y = -1;
	while (++y < in->board.y)
	{
		x = -1;
		while (++x < in->board.x)
		{
			ft_putnbr_fd((in->heat)[y][x][0], in->fd);
			ft_putchar_fd(' ', in->fd);
		}
		ft_putchar_fd('\n', in->fd);
	}
	ft_putstr_fd("|0|\n", in->fd);
/*	ft_putstr_fd("|1|\n", in->fd);
	y = -1;
	while (++y < in->board.y)
	{
		x = -1;
		while (++x < in->board.x)
		{
			ft_putnbr_fd((in->heat)[y][x][1], in->fd);
			ft_putchar_fd(' ', in->fd);
		}
		ft_putchar_fd('\n', in->fd);
	}
	ft_putstr_fd("|1|\n", in->fd);
	ft_putstr_fd("|2|\n", in->fd);
	y = -1;
	while (++y < in->board.y)
	{
		x = -1;
		while (++x < in->board.x)
		{
			ft_putnbr_fd((in->heat)[y][x][2], in->fd);
			ft_putchar_fd(' ', in->fd);
		}
		ft_putchar_fd('\n', in->fd);
	}
	ft_putstr_fd("|2|\n", in->fd);
*/
}
