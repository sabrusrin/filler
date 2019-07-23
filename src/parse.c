/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:33 by chermist          #+#    #+#             */
/*   Updated: 2019/07/23 20:57:10 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_data(char ***save, int x, int y, int flag, int fd)
{
	char	*line;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flag)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	while (j++ < y)
	{
		get_next_line(0, &line);
		tmp = line;
		if (!line)		
			continue ;
		if (line && (line[0] != ' ' || flag == 0))
		{
			(*save)[i] = line + flag;
		ft_putchar_fd('<', fd);
		ft_putstr_fd(*(save)[i], fd);
		ft_putnbr_fd(j, fd);
		ft_putchar_fd('>', fd);
		ft_putchar_fd('\n', fd);
		i++;
		}
		line = tmp;
		ft_strdel(&line);
	}
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
