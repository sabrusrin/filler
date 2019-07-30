/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:30 by chermist          #+#    #+#             */
/*   Updated: 2019/07/30 20:42:51 by chermist         ###   ########.fr       */
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
	if (init_game(&in))
		play(&in);
	else
		return (1);
	return (0);
}
