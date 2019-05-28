/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/05/28 23:24:23 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_data(int flag, t_map *in, char *line)
{
	
}

void	parse(t_map *in)
{
	char	*line;

	while (get_next_line(0,  &line))
	{
		if (ft_strstr(line, "$$$"))
			save_data(0, in, line);
		if (ft_strstr(line, "Plateau"))
			save_data(1, in, line);
			
		free(line);
	}
}

int main(void)
{
	int	i;
	int j;
	t_map in;

	parse(&in);

	free(&in);
	return (0);
}
