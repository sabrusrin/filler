/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:13:38 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/02 20:01:23 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_img	*new_img(int height, char **first_str, t_img *start_list)
{
	t_img	*new;
	char	*str;
	int 	i;

	i = -1;
	new = ft_memalloc(sizeof(t_img));
	new->next = NULL;
	new->field = ft_memalloc(sizeof(char*) * (height + 1));
	new->field[++i] = ft_strcccpy(*first_str + 4, '\n');
	if (*first_str)
		ft_strdel(first_str);
	while(get_next_line(0, &str) && ft_isdigit(*str))
	{
		new->field[++i] = ft_strcccpy(str + 4, '\n');
		ft_strdel(&str);
	}	
	new->field[++i] = NULL;
	new->prev = start_list;
	start_list->next = new;
	return (new);
}

int	map_count(t_win *win)
{
	int			height;
	char		*str;
	
	while (get_next_line(0, &str))
	{
		if (ft_strstr(str, "Plateau"))
		{
			str += 8;
			height = ft_atoi(str);
			while (ft_isdigit(*str++))
				;
			win->width = ft_atoi(str);
			return (height);
		}
		ft_strdel(&str);
	}
	return (0);
}
t_img	*create_first(int height)
{
	t_img	*new;
	char	*str;
	int 	i;

	i = -1;
	new = ft_memalloc(sizeof(t_img));
	new->next = NULL;
	new->field = ft_memalloc(sizeof(char*) * (height + 1));
	get_next_line(0, &str);
	ft_strdel(&str);
	while(get_next_line(0, &str) && ft_isdigit(*str))
	{
		new->field[++i] = ft_strcccpy(str + 4, '\n');
		ft_strdel(&str);
	}	
	new->field[++i] = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
/*
t_img	*make_list(t_win *win)
{
	int			height;
	t_img		*block;
	t_img		*start_list;
	char		*str;
	
	height = map_count(win);
	win->dat.height = height;
	block = create_first(height);
	start_list = block;
	while (get_next_line(0, &str))
	{
		if (ft_isdigit(*str))
			block = new_img(height, str, block);
		ft_strdel(&str);
	}
	return (start_list);
}*/
