/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:38:01 by chermist          #+#    #+#             */
/*   Updated: 2019/08/16 02:00:43 by chermist         ###   ########.fr       */
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
			if (in->heat_map[y][x][2] != 0 && in->heat_map[y][x][2] <= 10)
				return (2);
		//	else
		//		return (1);
		}
	return (1);
}

int		is_placeable(t_game *in, int y, int x, int *cost)
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

	offy = (y > 0 && in->heat_map[y - 1][x][0] > in->heat_map[y][x][0]) ? 1 : -1;
	offx = (x > 0 && in->heat_map[y][x - 1][0] > in->heat_map[y][x][0]) ? 1 : -1;
	ty = -1;
	costp = 0;
	star = 0;
	ft_putstr_fd("func", in->fd);
	ft_putstr_fd("|", in->fd);
	ft_putnbr_fd(y, in->fd);
	ft_putstr_fd("|", in->fd);
	ft_putnbr_fd(x, in->fd);
	ft_putstr_fd("|", in->fd);
/*	ft_putnbr_fd(offy, in->fd);
	ft_putstr_fd("|", in->fd);
	ft_putnbr_fd(offx, in->fd);
	ft_putstr_fd("|", in->fd);*/
	ft_putchar_fd('\n', in->fd);

	while (++ty < in->tile.y && (tx = -1))//move token up-down left-right
		while (++tx <= in->tile.x)
		{
			if ((in->tile.y + y + ty * offy) < in->board.y && (y + ty * offy) > 0 &&
				(in->tile.x + x + tx * offx) < in->board.x && (x + tx * offx) > 0)
			{
			ft_putstr_fd("valid", in->fd);
			ft_putstr_fd("|", in->fd);
			ft_putnbr_fd(y + ty * offy, in->fd);
			ft_putstr_fd("|", in->fd);
			ft_putnbr_fd(x + tx * offx, in->fd);
			ft_putstr_fd("|", in->fd);
			ft_putchar_fd('\n', in->fd);

				costp = 0;
				star = 0;
				i = -1; 
				while (++i < in->tile.y && (j = -1) && star <= 1)// is placeable
					while (++j < in->tile.x && star <= 1)
					{	
						if (in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][0] > 0 &&
							(in->tile.data[i][j] == '*'))
							costp += in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][2];
						else if (in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][0] == -1 &&
								(in->tile.data[i][j] == '*'))
							star++;
						else if (in->heat_map[(y + ty * offy) + i][(x + tx * offx) + j][0] == 0 &&
								(in->tile.data[i][j] == '*'))
							break ;
					}
				if (star == 1 && (!*cost || *cost > costp))
		 		{
					ft_putstr_fd("vals\n", in->fd);
					in->p.y = y + ty * offy;
					in->p.x = x + tx * offx;
					ft_putstr_fd("|", in->fd);
					ft_putnbr_fd(*cost, in->fd); 
					ft_putstr_fd("|", in->fd);
					ft_putnbr_fd(costp, in->fd);
					ft_putstr_fd("|", in->fd);
					ft_putnbr_fd(in->p.y, in->fd);
					ft_putstr_fd("|", in->fd);
					ft_putnbr_fd(in->p.x, in->fd);
					ft_putstr_fd("|", in->fd);
					ft_putchar_fd('\n', in->fd);
					*cost = costp;
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

void	approach(t_game *in)
{
	int	x;
	int	y;
	int	fcost;
	int	hcost;
	int	cost;

	y = -1;
	cost = 0;
	fcost = 0;
	hcost = 0;
	while (++y < in->board.y && (x = -1))
		while (++x < in->board.x)
			if ((in->heat_map[y][x][2] > 0) && // check for figure
				(in->heat_map[y][x][1] <= 9 &&// change the view point depending on the token +-size
				 in->heat_map[y][x][1] > 0) && // check how close i'm to the player
				(!fcost || fcost >= in->heat_map[y][x][2])) // check if i should consider this cell
				if ((!fcost || (fcost > in->heat_map[y][x][2]) ||
					((fcost == in->heat_map[y][x][2]) &&
					(in->heat_map[in->p.p_y][in->p.p_x][0] >
					 in->heat_map[y][x][0]))) &&
					is_placeable(in, y, x, &cost))
					{
//						ft_putstr_fd("!here!", in->fd);
						in->p.p_y = y;
						in->p.p_x = x;
						fcost = in->heat_map[y][x][2];
					}
	// should make a last try function
	ft_putnbr(in->p.y);
	ft_putchar(' ');
	ft_putnbr(in->p.x);
	ft_putchar('\n');
	//place_fig(in);
}

void	player(t_game *in)
{
	int	strategy;

	strategy = check_map(in);
	size_fig(in);
	if (strategy == 1)// !approached
		approach(in);
	else if (strategy == 2)
		ft_putstr_fd("SURROUND", in->fd);
//	else if (strategy == 2)// approached
//		conquer(in);
//	else
//		fill(in);
}
