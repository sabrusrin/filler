/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:18:33 by chermist          #+#    #+#             */
/*   Updated: 2019/08/28 03:54:56 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	del_img(t_mlx *mlx, t_img *img)
{
	if (img->ptr != NULL)
		mlx_destroy_image(mlx->iptr, img->ptr);
}

void	flush_img(t_img *img)
{
	ft_bzero(img->px, WIDTH * HEIGHT * sizeof(unsigned int));
}

t_img	*create_img(t_mlx *mlx, t_img *img)
{
	int bpp;
	int endi;

//	if (!(mlx->img = malloc(sizeof(t_img))))
//		return (NULL);
	if (!(img->ptr = mlx_new_image(mlx->iptr,
		 mlx->visu.xy[0] * mlx->visu.sq, mlx->visu.xy[1] * mlx->visu.sq)))
	{
		del_img(mlx, img);
		return (NULL);
	}
	img->px = mlx_get_data_addr(img->ptr, \
						&bpp, &img->lsize, &endi);
	img->lsize = img->lsize / sizeof(unsigned int);
	return (mlx->img);
}

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	((int*)img->px)[x + (y * img->lsize)] = color;
}
