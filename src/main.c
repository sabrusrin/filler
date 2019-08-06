/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:30 by chermist          #+#    #+#             */
/*   Updated: 2019/08/07 01:16:08 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_game in;

	in.fd = open("trace", O_WRONLY);
	in.fdm = open("rdmap", O_RDONLY);
	if (init_game(&in))
		play(&in);
	else
		return (1);
	if (in.board.data)
		free_token(&(in.board));
	if (in.tile.data)
		free_token(&(in.tile));
	return (0);
}
