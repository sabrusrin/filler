/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 23:01:43 by chermist          #+#    #+#             */
/*   Updated: 2019/08/29 19:44:46 by chermist         ###   ########.fr       */
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
//	mlx->act.space = 0;
	mlx->act.right = 0;
	mlx->act.left = 0;
	mlx->logs = NULL;
//	create_image(mlx, &mlx->log.img[0]);
//	mlx->logs->next = NULL;
//	mlx->logs->prev = NULL;
	if (mlx->visu.xy[0] == 15)
		mlx->visu.sq = 40;
	if (mlx->visu.xy[0] == 24)
		mlx->visu.sq = 25;
	if (mlx->visu.xy[0] == 100)
		mlx->visu.sq = 8;
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
		|| !(mlx->view = malloc(sizeof(t_view))))
	{
		purge(mlx);
		err_handle("Initialization failed!\a");
	}
//		|| !(create_img(mlx)))
	set_default(mlx);
}
