/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:05:00 by chermist          #+#    #+#             */
/*   Updated: 2019/08/19 23:27:13 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "mlx_keys.h"

# define ABS(Value) (Value < 0) ? (-Value) : (Value)
# define WIDTH  	1920
# define HEIGHT 	1080

typedef struct		s_visu
{
	int				**map;
	int				**color;
	int				width;
	int				height;
	int				scale;
}					t_visu;

typedef struct		s_img
{
	void			*ptr;
	void			*px;
	int				lsize;
}					t_img;

typedef	struct		s_pt
{
	int				x;
	int				y;
	int				z;
	t_color			color;
}					t_pt;

typedef struct		s_view
{
	float			offsetx;
	float			offsety;
	float			hz;
	int				scale;
	int				clr;
}					t_view;

typedef struct		s_mlx
{
	void			*iptr;
	void			*wptr;
	t_img			*img;
	t_view			*view;
	t_mtx			*mtx;
}					t_mlx;

void				err_handle(char *reason);
void				set_default(t_mlx *mlx);
void				draw_line(t_pt p1, t_pt p2, t_img *img);
void				cell_draw(t_pt p1, t_pt p2, t_img *img);
void				parse(t_mtx *visu);
int					atoi_move(char **str);
void				draw(t_mtx *visu, t_mlx *mlx);
void				flush_img(t_img *img);
void				del_img(t_mlx *mlx);
void				do_init(t_mlx *mlx);
void				purge(t_mlx *mlx);
void				put_pixel_to_img(t_img *img, int x, int y, int color);
t_img				*create_img(t_mlx *mlx);

#endif
