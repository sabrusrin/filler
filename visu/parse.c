/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:09:30 by chermist          #+#    #+#             */
/*   Updated: 2019/08/28 03:54:54 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	dims(char **line, int *x, int *y, int flag)
{
	char	*tmp;

	tmp = *line;
	*line += flag;
	*y = atoi_move(line);
	*line += 1;
	*x = atoi_move((line));
	*line = tmp;
}

void	parse(t_game *visu)
{
	int		i;
	int		j;
	char	*line;


	i = 0;
	while (i < 10 && get_next_line(1, fd))
	{
		if (ft_strstr(line, "$$$ exec p1 :"))
			if (visu->p[0] = (char*)malloc(sizeof(char) * ft_strlen(line[14])))
				ft_strcpy(&visu->p[0], &line[14]);
		if (ft_strstr(line, "$$$ exec p2 :"))
			if (visu->p[0] = (char*)malloc(sizeof(char) * ft_strlen(line[14])))
				ft_strcpy(&visu->p[0], &line[14]);
		if (ft_strstr(line, "Plateau"))
			dims(&line, &visu->xy[0], &visu->xy[1], 8);
		ft_strdel(&line);
		i++
	}
}
