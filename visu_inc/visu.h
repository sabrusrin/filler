/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:19:48 by chermist          #+#    #+#             */
/*   Updated: 2019/09/03 18:10:07 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_keys.h"
# define H	1080
# define W	1920
# define P_ONE 0xF58320
# define P_ONE_L 0xFBCDA5
# define P_TWO 0x2092F5
# define P_TWO_L 0xBCDEFC
# define SYM "1234567890 \n"

typedef	struct		s_img
{
	char			**field;
	struct s_img	*next;
	struct s_img	*prev;
}					t_img;

typedef struct		s_key
{
	int				right;
	int				left;
	int				space;
}					t_key;

typedef struct		s_dat
{
	int				height;
	int				width;
	int				net;
	int				loc_y;
	int				loc_x;
	int				img_w;
	int				img_h;
}					t_dat;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*img_ptr;
	int				*addr;
	char			*pl[2];
	int				fin[2];
	t_dat			dat;
	t_key			keys;
	t_img			*block;
	t_img			*start;
	t_img			*save;
}					t_win;

t_img				*make_list(t_win *win);
t_img				*new_img(int height, char **first_str, t_img *start_list);
t_img				*create_first(int height);
int					map_count(t_win *win);
void				free_dlist(t_img *lst);

char				*ft_strcccpy(char *src, char n);

t_win				*win_init(char *s);
void				purge(t_win *win);
void				img_create(t_win *win);

void				draw_net(t_win *win);
void				draw(t_win	*win);
void				print_strings(t_win *win);
void				print_square(t_win *win);

#endif
