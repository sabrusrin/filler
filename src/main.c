/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:30 by chermist          #+#    #+#             */
/*   Updated: 2019/09/01 20:06:10 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	err_handle(int i, t_game *in)
{
	if (i == 1)
		ft_putstr_fd("Cannot allocate memory!", 2);
	if (i == 2)
		ft_putstr_fd("Error, on reading!", 2);
	if (in->heat)
		free_wave(in);
	if (in->board.data)
		free_token(&(in->board));
	if (in->tile.data)
		free_token(&(in->tile));
	exit(1);
}

int		main(void)
{
	t_game in;

	if (init_game(&in))
		play(&in);
	else
		return (1);
	if (in.board.data)
		free_token(&(in.board));
	if (in.tile.data)
		free_token(&(in.tile));
	if (in.heat)
		free_wave(&in);
	return (0);
}
