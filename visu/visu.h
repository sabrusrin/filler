/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:05:00 by chermist          #+#    #+#             */
/*   Updated: 2019/08/26 00:21:29 by chermist         ###   ########.fr       */
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

# define CLR_TWO	0x2092F5
# define CLR_TW		0x8FC8FA //light
# define CLR_ONE	0xF58320	
# define CLR_ON		0xFAC18F //ligth

typedef struct		s_visu
{
	int				**map;
	int				**color;
	int				width;
	int				height;
	int				scale[3];
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

typedef struct		s_fig
{
	char			**map;
	char			**fig;
	char			player;
	int				colors[3];//light color/saturated/black(to cover light color)
	typedef struct	*prev;
	typedef struct	*next;
}					t_fig;

typedef struct		s_game
{
	int				xy[2];
	char			*p[2];
	char			**map;
	char			**token;
	char			*status;
}					t_game;

typedef struct		s_mlx
{
	void			*iptr;
	void			*wptr;
	t_img			*img;
	t_fig			*logs;
	t_game			*info;
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
