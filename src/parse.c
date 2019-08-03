/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:33 by chermist          #+#    #+#             */
/*   Updated: 2019/08/03 01:00:22 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_data(t_data *save, int flag, int fd, int fdm)
{
	char	*line;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = (!flag) ? save->y : save->y + 1;
	free_token(save, flag);
	save->data = (char **)malloc(sizeof(char *) * save->y);
	while (j--)
	{
		get_next_line(0, &line);
		if (line && (line[0] != ' ' || flag == 0))
		{
			save->data[i] = ft_strnew(sizeof(char) * save->x);
			ft_strncpy(&((save->data)[i][0]), line + flag, save->x + 1);
			i++;
		}
		if (line)
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
