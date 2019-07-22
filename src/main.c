/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:30 by chermist          #+#    #+#             */
/*   Updated: 2019/07/22 19:03:03 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int		i;
	int 	j;
	char	*line;
	t_map 	in;
	
	in.fd = open("trace", O_WRONLY);
	if (init_game(&in))
		play(&in);
	else
		return (1);
	return (0);
}
