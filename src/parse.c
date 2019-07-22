/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:33 by chermist          #+#    #+#             */
/*   Updated: 2019/07/22 19:02:59 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_data(char **save, int x, int y, int flag, int fd)
{
	char	*line;
	char	*tmp;
	char	*stmp;
	int		i;
	int		j;

	i = 0;
	j = (flag == 0) ? y : y + 1;
	line = NULL;
	stmp = *save;
	while (j--)
	{
		get_next_line(0, &line);
		tmp = line;
		
//		ft_putchar_fd('*', fd);
//		ft_putstr_fd(line, fd);
//		ft_putchar_fd('*', fd);
//		ft_putchar_fd('\n', fd);
		if (line && (line[0] != ' ' || flag == 0))
		{
			*save += i;
			ft_memmove(*save, &(line[flag]), x);
			i += x;
		}
		line = tmp;
		if (line)
			ft_strdel(&line);
	}
	*save = stmp;
}

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
