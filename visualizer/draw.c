/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:54:58 by chermist          #+#    #+#             */
/*   Updated: 2019/11/25 21:01:49 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	print_strings(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 530,
					P_ONE, win->pl[0]);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 550,
					P_TWO, win->pl[1]);
	if (!win->start->next && (win->fin[0] || win->fin[1]))
	{
		mlx_string_put(win->mlx_ptr, win->win_ptr, 350, 530,
					P_ONE, ft_itoa(win->fin[0]));
		mlx_string_put(win->mlx_ptr, win->win_ptr, 350, 550,
					P_TWO, ft_itoa(win->fin[1]));
	}
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1570, 400,
					0xFF0000, "USAGE:");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1570, 450,
					0xFFFFFF, "KEY_RIGHT: start/pause");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1570, 500,
					0xFFFFFF, "KEY_LEFT: roll back/pause");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1570, 550,
					0xFFFFFF, "R for restart");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1570, 600,
					0xFFFFFF, "KEY_ESCAPE: exit");
}

void	print_square(t_win *win)
{
	int height;
	int width;
	int x;
	int y;
	int color;

	y = -1;
	while (win->start->field[++y] && (x = -1))
		while (win->start->field[y][++x] && (height = -1))
		{
			color = 0x000000;
			if (win->start->field[y][x] == 'O')
				color = P_ONE;
			else if (win->start->field[y][x] == 'o')
				color = P_ONE_L;
			else if (win->start->field[y][x] == 'X')
				color = P_TWO;
			else if (win->start->field[y][x] == 'x')
				color = P_TWO_L;
			while (++height < (win->dat.net - 1) && (width = -1))
				while (++width < (win->dat.net - 1))
					win->addr[((x + width) + (x * (win->dat.net - 1))) +
					(((y + height) + (y * (win->dat.net - 1))) *
					win->dat.img_w)] = color;
		}
}

void	draw_net(t_win *win)
{
	int		y;
	int		x;
	int		count_y;

	y = 0;
	count_y = 1;
	while (y < win->dat.img_h)
	{
		x = 0;
		while (x < win->dat.img_w)
		{
			if (!(count_y % win->dat.net) || count_y == 1)
				win->addr[x + (win->dat.img_w * y)] = 0x4C4C4C;
			if (!((x + 1) % win->dat.net) || !x)
				win->addr[x + (win->dat.img_w * y)] = 0x4C4C4C;
			x++;
		}
		y++;
		count_y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->img_ptr, win->dat.loc_x, win->dat.loc_y);
}

void	draw(t_win *win)
{
	ft_bzero(win->addr, win->dat.img_h * win->dat.img_w * 4);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->img_ptr, win->dat.loc_x, win->dat.loc_y);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	if (win->keys.right)
	{
		print_square(win);
		if (win->start->next)
			win->start = win->start->next;
	}
	if (win->keys.left)
	{
		if (win->start->prev)
			win->start = win->start->prev;
		print_square(win);
	}
	print_strings(win);
	draw_net(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->img_ptr, win->dat.loc_x, win->dat.loc_y);
}
