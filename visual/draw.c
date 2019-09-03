/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:54:58 by chermist          #+#    #+#             */
/*   Updated: 2019/09/03 13:28:26 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_strings(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 300,
					0xFF3300, "Press:");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 350,
					0xFF3300, "Right to set the figure");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 400,
					0xFF3300, "Left to roll back");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 450,
					0xFF3300, "R for restart");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 500,
					0xFF3300, "Esc for exit");
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
				color = 0x216900;
			else if (win->start->field[y][x] == 'o')
				color = 0x45f500;
			else if (win->start->field[y][x] == 'X')
				color = 0x0e5df0;
			else if (win->start->field[y][x] == 'x')
				color = 0x0ec6f0;
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
				win->addr[x + (win->dat.img_w * y)] = 0xCC33CC;
			if (!((x + 1) % win->dat.net) || !x)
				win->addr[x + (win->dat.img_w * y)] = 0xCC33CC;
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
	draw_net(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->img_ptr, win->dat.loc_x, win->dat.loc_y);
}
