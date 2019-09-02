/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:32:25 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/02 10:54:42 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include <stddef.h>
# include "../srcs/libft/libft.h"
# include "./fdf.h"

typedef	struct		s_img
{
	char			**fig;
	char			**field;
	struct s_img	*next;
	struct s_img	*prev;
}					t_img;

t_img	*make_list(t_win *win);

#endif
