/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:50:52 by chermist          #+#    #+#             */
/*   Updated: 2019/08/22 17:11:31 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minilibx_macos/mlx.h"
#include "mlx_keys.h"
#include <stdlib.h>

int		key_press(int key, void *ptr)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(&ptr[0], &ptr[1]);
		exit(1);
	}
	return (0);
}

int		main(void)
{
	void	*ptr[2];

	ptr[0] = mlx_init();
	ptr[1] = mlx_new_window(ptr[0], 1920, 1080, "FILLER VISU");
	
	mlx_hook(ptr[1], 2, 0, key_press, ptr);
	mlx_loop(ptr[0]);
}
