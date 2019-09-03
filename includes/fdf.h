/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:19:48 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/03 13:28:27 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# define H	1080
# define W	1920
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

char				*ft_strcccpy(char *src, char n);

t_win				*win_init(char *s);
void				purge(t_win *win);
void				img_create(t_win *win);

void				draw_net(t_win *win);
void				draw(t_win	*win);
void				print_strings(t_win *win);
void				print_square(t_win *win);

#endif
