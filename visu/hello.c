/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:50:52 by chermist          #+#    #+#             */
/*   Updated: 2019/08/25 21:40:59 by chermist         ###   ########.fr       */
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
	void	*ptr[3];

/*	static char *green_simple_cross_xpm[] = {
		" 36 36 5 1",
		"` c #ffffff",
		". c #00ff00",
		"# c #ff0000",
		"a c #97b8fd",
		"b c #0000ff",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"``````````````............############",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"....................................",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb",
		"aaaaaaaaaaaa............bbbbbbbbbbbb"
	};*/
	static char *six_px_xpm[] = {
		/* width height num_colors chars_per_pixel */
		" 7 14 2 0.16",
		/* colors */
		"` c #ffffff",
		"# c #ff0000",
		/* pixels */
		"``````````````",
		"```#``````````",
		"``````````````",
		"```````#``````",
		"``````````````",
		"``````````#```",
		"``````````````",
	};

	int	w;
	int	h;

	w = 7 * 6;
	h = 14 * 6;

	ptr[0] = mlx_init();
	ptr[1] = mlx_new_window(ptr[0], 1300, 750, "FILLER VISU");
	ptr[2] = mlx_xpm_to_image(ptr[1], six_px_xpm, &w, &h);
//	ptr[2] = mlx_xpm_file_to_image(ptr[1], "ilya.XPM", &w, &h);

	mlx_put_image_to_window (ptr[0], ptr[1], ptr[2], 30, 30);
	mlx_hook(ptr[1], 2, 0, key_press, ptr);
	mlx_loop(ptr[0]);
}
