/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:57:25 by chermist          #+#    #+#             */
/*   Updated: 2019/09/01 18:36:11 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_wave(t_game *in)
{
	int	y;
	int	x;
	
	y = -1;
	while (++y < in->board.y && in->heat[y])
	{
		x = -1;
		while (++x < in->board.x && in->heat[y][x])
		{
			free(in->heat[y][x]);
			in->heat[y][x] = NULL;
		}
//		free(in->heat[y]);
//		in->heat[y] = NULL;
	}
	if (in->heat)
	{
		free(in->heat);
		in->heat = NULL;
	}
}

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
{
	if (x + 1 < in->board.x && in->heat[y][x + 1][f] == 1000)
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
	if (y + 1 < in->board.y && x + 1 < in->board.x &&
			in->heat[y + 1][x + 1][f] == 1000)
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

void	wave_map(t_game *in)
{
	int			x;
	int			y;
	static int	inited = 0;

	y = -1;
	if (!inited)
	{
		if (!(in->heat = (int***)malloc(sizeof(int**) * in->board.y)))
			err_handle(1, in);
		while (++y < in->board.y)
		{
			if (!(in->heat[y] = (int**)malloc(sizeof(int*) * in->board.x)))
				err_handle(1, in);
			x = -1;
			while (++x < in->board.x)
				if (!(in->heat[y][x] = (int*)malloc(sizeof(int) * 3)))
					err_handle(1, in);
		}
		inited = 1;
	}
	locate_players(in);
	wave_algo(in);
}
