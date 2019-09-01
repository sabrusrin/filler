/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:19:48 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/01 20:44:09 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "fdf_prms.h"
# include "../minilibx_macos/mlx.h"

typedef	struct		s_img
{
	char			**field;
	struct s_img	*next;
	struct s_img	*prev;
}					t_img;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*img_ptr;
	int			*addr;
	int			height;
	int			width;
	t_img		*start;
	t_img		*save;
}				t_win;

t_img	*make_list(t_win *win);
char	*ft_strcccpy(char *src, char n);

#endif
