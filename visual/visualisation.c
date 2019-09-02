/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:27:01 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/02 15:27:54 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../includes/fdf.h"

char	*ft_strcccpy(char *src, char n)
{
	int		i;
	int		count;
	char	*dst;

	count = 0;
	i = -1;
	while (src[++i] && src[i] != n)
		count++;
	dst = (char*)malloc(sizeof(char) * (count + 1));
	ft_memcpy(dst, src, count);
	dst[count] = '\0';
	return (dst);
}

t_win		*win_init(char *s)
{
	t_win		*win;
	int			size;
	int			endian;
	int			bits;

	win = (t_win*)malloc(sizeof(t_win));
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, W, H, s);
	win->img_ptr = (int*)mlx_new_image(win->mlx_ptr, W, H);
	win->addr = (int*)mlx_get_data_addr(win->img_ptr, &bits, &size, &endian);
	win->keys.right = 1;
	win->keys.left = 0;
	return (win);
}

void print_square(t_win *win)
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
			if (win->start->field[y][x] == 'O')
				color = 0x216900;
			else if (win->start->field[y][x] == 'o')
				color = 0x45f500;
			else if (win->start->field[y][x] == 'X')
				color = 0x0e5df0;
			else if (win->start->field[y][x] == 'x')
				color = 0x0ec6f0;
			else if (win->start->field[y][x] == '.')
				color = 0x000000;
			while (++height < (NET - 1) && (width = -1))
				while (++width < (NET - 1))
					win->addr[((x + width) + (x * (NET - 1))) + (((y + height) + (y * (NET - 1))) * W)] = color;
		}
}
void		draw_net(t_win *win)
{
	int		y;
	int		x;
	int		count_y;

	y = 0;
	count_y = 1;
	while (y < win->height * NET)
	{
		x = 0;
		while (x < win->width * NET)
		{
			if (!(count_y % NET) || count_y == 1) 
				win->addr[x + (W * y)] = 0xCC33CC;
			if (!((x + 1) % NET) || !x)
				win->addr[x + (W * y)] = 0xCC33CC;
			x++;
		}
		y++;
		count_y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
} 

void print_strings(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 300, 0xFF3300, "Press:");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 350, 0xFF3300, "Right to set the figure");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 400, 0xFF3300, "Left to roll back");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 450, 0xFF3300, "R for restart");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1000, 500, 0xFF3300, "Esc for exit");
}

int key_hook(int key, t_win *win)
{
	if (key == 53)
		exit(0);
	if (key == 124)
	{
		win->keys.right = (win->keys.right) ? 0 : 1;
		win->keys.left = 0;
	}
	if (key == 123)
	{	
		win->keys.left = (win->keys.left) ? 0 : 1;
		win->keys.right = 0;
	}
	if (key == 15)
	{
		win->start = win->save;
		print_square(win);
	}
	if (key == 49)
	{
		win->keys.space = (win->keys.space) ? 0 : 1;
	}
	return (0);
}

int		loop_hook(t_win *win)
{
	char	*str;
	
	if (get_next_line(0, &str))
	{
		if (ft_isdigit(*str))
			win->block = new_img(win->height, str, win->block);
		if (str)
			ft_strdel(&str);
	}
	if (win->keys.space && (win->keys.right || win->keys.left))
	{
		//add here some key logic and everything will work!
		ft_bzero(win->addr, H * W * 4);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
		
		if (win->keys.right)
		{
			print_square(win);
			if(win->start->next)
				win->start = win->start->next;
		}
		if (win->keys.light)
		{
			if(win->start->prev)
				win->start = win->start->prev;
			print_square(win);
		}
		draw_net(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
		print_strings(win);
	}
}

int		main()
{
	t_win		*win;
	t_img		*block;
	t_img		*start_list;

	win = win_init("Welcome to filler!");
	win->height = map_count(win);
	win->block = create_first(win->height);
	win->start = win->block;
	//win->start = make_list(win);
	win->save = win->start;
	draw_net(win);
//	print_strings(win);
	mlx_key_hook(win->win_ptr, key_hook, win);
	mlx_loop_hook(loop_hook, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
