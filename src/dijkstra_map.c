/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:57:25 by chermist          #+#    #+#             */
/*   Updated: 2019/07/30 00:04:09 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	heat_map(t_game *in)
{
	int			x;
	int			y;
	static int inited = 0;

	y = 0;
	if (!inited)
	{
		if (!(in->heat_map = (int**)malloc(sizeof(int *) * in->board.y)))
			exit (1);
		while (y < in->board.y)
			if (!(in->heat_map[y++] = (int *)malloc(sizeof(int) * in->board.x)))
				exit (1);
	}
	locate_players(in);

		

}
