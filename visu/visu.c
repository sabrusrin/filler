/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:10:54 by chermist          #+#    #+#             */
/*   Updated: 2019/08/26 18:57:29 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		loop_press(t_mlx *mlx)
{
	if (mlx->act.space == 0)

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
	t_game visu;
	t_mlx mlx;

	parse(&visu);
	do_init(&mlx);
	draw(&visu, &mlx);
	mlx_hook(mlx.wptr, 2, 0, key_press, &mlx);
	mlx_loop_hook(mlx.iptr, loop_press, )
	mlx_loop(mlx.iptr)
}
