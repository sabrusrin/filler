/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:27:01 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/02 19:54:30 by chermist         ###   ########.fr       */
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

	win = (t_win*)malloc(sizeof(t_win));
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, W, H, s);
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
		while (win->start->field[y][++x] && (win->dat.height = -1))
		{
			height = -1;
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
			while (++height < (win->dat.net - 1) && (width = -1))
				while (++width < (win->dat.net - 1))
					win->addr[((x + width) + (x * (win->dat.net - 1))) + (((y + height)
								+ (y * (win->dat.net - 1))) * win->dat.width * win->dat.net)] = color;
		}
}
void		draw_net(t_win *win)
{
	int		y;
	int		x;
	int		count_y;

	y = 0;
	count_y = 1;
	while (y < win->dat.height * win->dat.net)
	{
		x = 0;
		while (x < win->dat.width * win->dat.net)
		{
			if (!(count_y % win->dat.net) || count_y == 1) 
				win->addr[x + (win->dat.width * win->dat.net * y)] = 0xCC33CC;
			if (!((x + 1) % win->dat.net) || !x)
				win->addr[x + (win->dat.width * win->dat.net * y)] = 0xCC33CC;
			x++;
		}
		y++;
		count_y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, win->dat.loc_x, win->dat.loc_y);
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
	return (0);
}

int		loop_hook(t_win *win)
{
	char	*str;
	
	if (get_next_line(0, &str))
	{
		if (ft_isdigit(*str))
			win->block = new_img(win->dat.height, &str, win->block);
		if (str)
			ft_strdel(&str);
	}
	if (win->keys.right || win->keys.left)
	{
		ft_bzero(win->addr, win->dat.height * win->dat.net * win->dat.width * 4);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, win->dat.loc_x, win->dat.loc_y);
		if (win->keys.right)
		{
			print_square(win);
			if(win->start->next)
				win->start = win->start->next;
		}
		if (win->keys.left)
		{
			if(win->start->prev)
				win->start = win->start->prev;
			print_square(win);
		}
		draw_net(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, win->dat.loc_x, win->dat.loc_y);
	}
	return (0);
}

void	fig_size(t_win *win)
{
	if (win->dat.height == 15)
	{
		win->dat.net = 58;
		win->dat.loc_y = (H / 2) - ((win->dat.height * 58) / 2);
		win->dat.loc_x = (W / 2) - ((win->dat.width * 58) / 2);
	}
	if (win->dat.height == 24)
	{
		win->dat.net = 25;
		win->dat.loc_y = (H / 2) - ((win->dat.height * 25) / 2);
		win->dat.loc_x = (W / 2) - ((win->dat.width * 25) / 2);
	}
	if (win->dat.height == 100)
	{
		win->dat.net = 10;
		win->dat.loc_y = (H / 2) - ((win->dat.height * 10) / 2);
		win->dat.loc_x = (W / 2) - ((win->dat.width * 10) / 2);
	}
}

void	img_create(t_win *win)
{
	int			endian;
	int			bits;
	int			size;

	win->img_ptr = (int*)mlx_new_image(win->mlx_ptr, win->dat.width * win->dat.net,
			win->dat.height * win->dat.net);
	win->addr = (int*)mlx_get_data_addr(win->img_ptr, &bits, &size, &endian);
}

int		main()
{
	t_win		*win;
	t_img		*start_list;

	win = win_init("Welcome to filler!");
	win->dat.height = map_count(win);
	fig_size(win);
	img_create(win);
	win->block = create_first(win->dat.height);
	win->start = win->block;
	//win->start = make_list(win);
	win->save = win->start;
	draw_net(win);
//	print_strings(win);
	mlx_key_hook(win->win_ptr, key_hook, win);
	mlx_loop_hook(win->mlx_ptr, loop_hook, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
/*	ft_putnbr(win->dat.loc_y);
	ft_putchar(' ');
	ft_putnbr(win->dat.loc_x);
	ft_putchar(' ');
	ft_putnbr(win->dat.width * win->dat.net);
	ft_putchar(' ');
	ft_putnbr(win->dat.height * win->dat.net);
	ft_putchar(' ');
	ft_putnbr(win->dat.net);
	ft_putchar('\n');
*/
