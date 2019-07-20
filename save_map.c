/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:38:43 by chermist          #+#    #+#             */
/*   Updated: 2019/07/21 01:45:59 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		y = 8, x = 2;

	fd = open("rdmap", O_WRONLY);
	while (-1 < (get_next_line(0, &line)))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		ft_putnbr(y);
		ft_putchar(' ');
		ft_putnbr(x);
		ft_putchar('\n');
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
