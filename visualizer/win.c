/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:20:24 by chermist          #+#    #+#             */
/*   Updated: 2019/09/03 18:04:24 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

char	**free_token(char **token)
{
	int	y;

	y = 0;
	if (token && *token)
	{
		while (token[y])
			ft_strdel(&(token[y++]));
		free((token));
		token = NULL;
	}
	return (token);
}

void	free_dlist(t_img *lst)
{
	t_img	*ptr;

	while (lst->next)
	{
		lst->field = free_token(lst->field);
		ptr = lst;
		lst = lst->next;
		ptr->next = NULL;
		free(lst->prev);
		lst->prev = NULL;
	}
	if (lst && lst->next == NULL)
	{
		free(lst->prev);
		lst->prev = NULL;
		free(lst);
		lst = NULL;
	}
}

void	purge(t_win *win)
{
	if (!(win->mlx_ptr))
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->img_ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	if (win->save)
		free_dlist(win->save);
}

void	img_create(t_win *win)
{
	int			endian;
	int			bits;
	int			size;

	if (!(win->img_ptr = (int*)mlx_new_image(win->mlx_ptr,
			win->dat.img_w, win->dat.img_h)))
		purge(win);
	win->addr = (int*)mlx_get_data_addr(win->img_ptr, &bits, &size, &endian);
}

t_win	*win_init(char *s)
{
	t_win	*win;

	if (!(win = (t_win*)malloc(sizeof(t_win))) ||
		!(win->mlx_ptr = mlx_init()) ||
		!(win->win_ptr = mlx_new_window(win->mlx_ptr, W, H, s)))
		purge(win);
	win->keys.right = 0;
	win->keys.left = 0;
	win->fin[0] = 0;
	win->fin[1] = 0;
	return (win);
}
