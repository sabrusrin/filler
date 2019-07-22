/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/07/22 19:03:01 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_token(t_map *in)
{
	int		fd;
	int		y = 8, x = 2;
	static int i = 0;

	write(in->fd, "Z\n", 2);
	fd = open("rdmap", O_WRONLY);
	ft_putchar_fd('&', in->fd);
	write(in->fd, in->board, in->x * in->y);
	ft_putnbr_fd(i, in->fd);
	ft_putchar_fd('&', in->fd);
	write(in->fd, "\n", 1);
	ft_putchar_fd('&', in->fd);
	write(in->fd, in->tile, in->tx * in->ty);
	ft_putchar_fd('&', in->fd);
	write(in->fd, "\n", 1);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
//	close(fd);
	close(in->fd);
}


void	play(t_map *in)
{
	char	*line;

	while (-1 < (get_next_line(0,  &line)))
	{
		if (ft_strstr(line, "Plateau"))
		{
		write(in->fd, "3\n", 2);
			if (in->x == 0 && in->y == 0)
				dims(&line, &in->x, &in->y, 8);
			if (in->board)
				ft_strdel(&(in->board));
			if (!(in->board = ft_strnew(in->x * in->y)))
				exit (1);//have to free everything
			save_data(&(in->board), in->x, in->y, 4, in->fd);
		}
		if (ft_strstr(line, "Piece"))
		{
		write(in->fd, "4\n", 2);
			dims(&line, &in->tx, &in->ty, 6);
			if (!(in->tile = ft_strnew(in->tx * in->ty)))
				exit (1);
			save_data(&(in->tile), in->tx, in->ty, 0, in->fd);
			place_token(in);
		}
		if (in->tile)
			ft_strdel(&(in->tile));
		if (line)
			ft_strdel(&line);
	}
	if (in->board)
		ft_strdel(&(in->board));
}

int		init_game(t_map *in)
{
	char *line;

	get_next_line(0,  &line);
	if (line && (line[10] == '1' || line[10] == '2'))
	{
		in->player[0] = (ft_strstr(line, "p1")) ? 'O' : 'X';
		in->player[1] = (ft_strstr(line, "p1")) ? 'X' : 'O';
		ft_strdel(&line);
		in->board = NULL;
		in->tile = NULL;
		in->y = 0;
		in->x = 0;
		return (1);
	}
	return (0);
}
