/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:57:25 by chermist          #+#    #+#             */
/*   Updated: 2019/08/29 22:16:47 by chermist         ###   ########.fr       */
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
				in->heat_map[y][x][0] = -1;
				in->heat_map[y][x][1] = -1;
			}
			else if (in->board.data[y][x] == in->player[1] ||
					in->board.data[y][x] == in->player[1] + 32)
			{
				in->heat_map[y][x][0] = 0;
				in->heat_map[y][x][1] = 0;
			}
			else
			{
				in->heat_map[y][x][0] = 1;
				in->heat_map[y][x][1] = 1;
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
			if (in->heat_map[ye][xe][0] == 0)
				hv = (!hv || hv > ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))))
				? ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))) : hv;
			if (in->heat_map[ye][xe][1] == -1)// multiplied here by 10
				gv = (!gv || gv > ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))))
				? ft_sqrt(((ye - y) * (ye - y)
					+ (xe - x) * (xe - x))) : gv;
		}
	in->heat_map[y][x][0] = hv;
	in->heat_map[y][x][1] = gv;
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
			fcost = in->heat_map[y][x];
			if (in->heat_map[y][x][0] == 1)
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
		if (!(in->heat_map = (int***)malloc(sizeof(int**) * in->board.y)))
			exit(1);
		while (++y < in->board.y)
		{
			if (!(in->heat_map[y] = (int**)malloc(sizeof(int*) * in->board.x)))
				exit(1);
			x = -1;
			while (++x < in->board.x)
				if (!(in->heat_map[y][x] = (int*)malloc(sizeof(int) * 3)))
					exit(1);
		}
		inited = 1;
	}
	locate_players(in);
	fill_cell(in);
	ft_putstr_fd("|0|\n", in->fd);
	y = -1;
	while (++y < in->board.y)
	{
		x = -1;
		while (++x < in->board.x)
		{
			ft_putnbr_fd((in->heat_map)[y][x][0], in->fd);
			ft_putchar_fd(' ', in->fd);
		}
		ft_putchar_fd('\n', in->fd);
	}
	ft_putstr_fd("|0|\n", in->fd);
	ft_putstr_fd("|1|\n", in->fd);
	y = -1;
	while (++y < in->board.y)
	{
		x = -1;
		while (++x < in->board.x)
		{
			ft_putnbr_fd((in->heat_map)[y][x][1], in->fd);
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
			ft_putnbr_fd((in->heat_map)[y][x][2], in->fd);
			ft_putchar_fd(' ', in->fd);
		}
		ft_putchar_fd('\n', in->fd);
	}
	ft_putstr_fd("|2|\n", in->fd);

}
