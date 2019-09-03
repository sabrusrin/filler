/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:27:01 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/03 13:28:25 by chermist         ###   ########.fr       */
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

int		key_hook(int key, t_win *win)
{
	if (key == 53)
	{
		purge(win);
		exit(0);
	}
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
		draw(win);
	return (0);
}

void	fig_size(t_win *win)
{
	if (win->dat.height == 15)
		win->dat.net = 58;
	if (win->dat.height == 24)
		win->dat.net = 25;
	if (win->dat.height == 100)
		win->dat.net = 10;
	win->dat.img_w = win->dat.width * win->dat.net;
	win->dat.img_h = win->dat.height * win->dat.net;
	win->dat.loc_y = (H / 2) - (win->dat.img_h / 2);
	win->dat.loc_x = (W / 2) - (win->dat.img_w / 2);
}

int		main(void)
{
	t_win		*win;
	t_img		*start_list;

	win = win_init("Welcome to filler!");
	win->dat.height = map_count(win);
	fig_size(win);
	img_create(win);
	win->block = create_first(win->dat.height);
	win->start = win->block;
	win->save = win->start;
	draw_net(win);
//	print_strings(win);
	mlx_key_hook(win->win_ptr, key_hook, win);
	mlx_loop_hook(win->mlx_ptr, loop_hook, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
