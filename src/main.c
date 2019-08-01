/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:30 by chermist          #+#    #+#             */
/*   Updated: 2019/08/02 01:38:35 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int		i;
	int 	j;
	char	*line;
	t_game 	in;

	in.fd = open("trace", O_WRONLY);
	in.fdm = open("rdmap", O_RDONLY);
	if (init_game(&in))
		play(&in);
	else
		return (1);
	if (in.heat_map)
		ft_arrdel((void**)in.heat_map);
	if (in.board.data)
		ft_arrdel((void**)in.board.data);
	if (in.tile.data)
		ft_arrdel((void**)in.tile.data);
	return (0);
}
