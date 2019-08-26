/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 23:01:43 by chermist          #+#    #+#             */
/*   Updated: 2019/08/26 18:57:44 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	purge(t_mlx *mlx)
{
	if (!(mlx->iptr))
		mlx_destroy_window(mlx->iptr, mlx->wptr);
	if (!(mlx->view))
		ft_memdel((void**)&(mlx->view));
	if (!(mlx->img))
		del_img(mlx);
}

void	set_default(t_mlx *mlx)
{//set default values here
	mlx->act.space = 0;
	mlx->act.right = 0;
	mlx->act.left = 0;
/*	mlx->view->offsetx = WIDTH / 2;
	mlx->view->offsety = HEIGHT / 5;
	mlx->view->scale = 0.2;
	mlx->view->clr = 1;
	mlx->view->hz = 1;
	mlx->view->line = dot_draw;
	mlx->proj = iso;*/
}

void	do_init(t_mlx *mlx)
{
	if (!(mlx->iptr = mlx_init())
		|| !(mlx->wptr = mlx_new_window(mlx->iptr,
				WIDTH, HEIGHT, "FDF"))
		|| !(mlx->view = malloc(sizeof(t_view)))
		|| !(create_img(mlx)))
	{
		purge(mlx);
		err_handle("Initialization failed!\a");
	}
	set_default(mlx);
}
