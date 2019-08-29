/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:10:54 by chermist          #+#    #+#             */
/*   Updated: 2019/08/28 15:13:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		loop_press(t_mlx *mlx)
{
	t_log			*tmp;
	static t_log	*rewind;
	if (!mlx->log)
	{
		mlx->log = (t_log*)malloc(sizeof(t_log) * 1);
		create_image(mlx, &mlx->log.img[0]);
		mlx->log->next = NULL;
		mlx->log->prev = NULL;
	}
	else
	{
		tmp = mlx->log;
		mlx->log = (t_log*)malloc(sizeof(t_log) * 1);
		tmp->next = mlx->log;
		mlx->log->prev = tmp;
		create_image(mlx, &mlx->log.img[0]);
		mlx->log->next = NULL;
	}
	// read the map and put it to the image
	// put image of a map  to the window
	// put image of a figures to the window
	create_image(mlx, &mlx->log.img[1]);
	if (mlx->act.space)
	{
		mlx->tlog = mlx->log;
		if (mlx->act.left)
			mlx->tlog =  prev;

		mlx_put_image_to_window(mlx->iptr, mlx->wptr, mlx->tlog.img[0].ptr, x, y);
		mlx_put_image_to_window(mlx->iptr, mlx->wptr, mlx->tlog.img[0].ptr, x, y);

	}

}

int		key_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESCAPE)
	{
		purge(mlx);
		exit(1);
	}
	else if (key == KEY_SPACEBAR)
		mlx->act.space = (mlx->act.space) ? 0 : 1;
	else if (key == KEY_RIGHT)
		mlx->act.right = (mlx->act.right) ? 0 : 1;
	else if (key == KEY_LEFT)
		mlx->act.left = (mlx->act.left) ? 0 : 1;
	return (0);
}

int		main(void)
{
//	t_game visu;
	t_mlx mlx;

	parse(&mlx.visu);
	do_init(&mlx);
//	draw(&visu, &mlx);
	mlx_hook(mlx.wptr, 2, 0, key_press, &mlx);
	mlx_loop_hook(mlx.iptr, loop_press, &mlx);
	mlx_loop(mlx.iptr)
}
