/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:44:01 by chermist          #+#    #+#             */
/*   Updated: 2019/08/26 18:57:41 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_grid(t_game *visu)
{

}	

void	
// create an image for a map each time it renews
// create an image for a token
// read output in realtime
// and put stuff to the image
// 

void	scale_game(t_mlx *mlx, t_game *visu)
{
	if (visu->info.xy[0] == 15)	
	{
		visu->scale[0] = 600;
		visu->scale[1] = 680;
		visu->scale[2] = 40;
	}
	if (visu->info.xy[0] == 24)	
	{
		visu->scale[0] = 600;
		visu->scale[1] = 1000;
		visu->scale[2] = 25;
	}
	if (visu->info.xy[0] == 15)	
	{
		visu->scale[0] = 800;
		visu->scale[1] = 792;
		visu->scale[2] = 8;
	}
}
