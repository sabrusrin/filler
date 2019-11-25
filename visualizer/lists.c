/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:13:38 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/03 18:04:20 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_img	*new_img(int height, char **first_str, t_img *start_list)
{
	t_img	*new;
	char	*str;
	int		i;

	i = -1;
	new = ft_memalloc(sizeof(t_img));
	new->next = NULL;
	new->field = ft_memalloc(sizeof(char*) * (height + 1));
	new->field[++i] = ft_strcccpy(*first_str + 4, '\n');
	if (*first_str)
		ft_strdel(first_str);
	while (get_next_line(0, &str) && ft_isdigit(*str))
	{
		new->field[++i] = ft_strcccpy(str + 4, '\n');
		ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	new->field[++i] = NULL;
	new->prev = start_list;
	start_list->next = new;
	return (new);
}

int		map_count(t_win *win)
{
	int		height;
	char	*str;
	char	*tmp;

	while (get_next_line(0, &str))
	{
		tmp = str;
		if (ft_strstr(str, "$$$ exec p1"))
			win->pl[0] = ft_strcccpy(str + 23, ']');
		if (ft_strstr(str, "$$$ exec p2"))
			win->pl[1] = ft_strcccpy(str + 23, ']');
		if (ft_strstr(str, "Plateau"))
		{
			str += 8;
			height = ft_atoi(str);
			while (ft_isdigit(*str++))
				;
			win->dat.width = ft_atoi(str);
			ft_strdel(&tmp);
			return (height);
		}
		str = tmp;
		ft_strdel(&str);
	}
	return (0);
}

t_img	*create_first(int height)
{
	t_img	*new;
	char	*str;
	int		i;

	i = -1;
	new = ft_memalloc(sizeof(t_img));
	new->next = NULL;
	new->field = ft_memalloc(sizeof(char*) * (height + 1));
	get_next_line(0, &str);
	if (str)
		ft_strdel(&str);
	while (get_next_line(0, &str) && ft_isdigit(*str))
	{
		new->field[++i] = ft_strcccpy(str + 4, '\n');
		ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	new->field[++i] = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
