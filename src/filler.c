/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/07/30 20:42:45 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	play_token(t_game *in)
{
	int		fd;
	int		y = 12, x = 14;
	static int i = 0;

	write(in->fd, "Z\n", 2);
	fd = open("rdmap", O_WRONLY);
	ft_putchar_fd('&', in->fd);
	write(in->fd, "\n", 1);
	heat_map(in);
	write(in->fd, "\n", 1);
	ft_putchar_fd('&', in->fd);
//	heat_map(in);
//	place_it(in);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
//	close(fd);
//	close(in->fd);
}

void	play(t_game *in)
{
	char	*line;

	while (-1 < (get_next_line(0,  &line)))
	{
		if (!line)
			continue ;
		if (ft_strstr(line, "Plateau"))
		{
		write(in->fd, "3\n", 2);
			if (in->board.x == 0 && in->board.y == 0)
				dims(&line, &in->board.x, &in->board.y, 8);
			if (!(in->board.data = (char**)malloc(sizeof(char*) * in->board.y)))
				exit (1);//have to free everything
			save_data(&(in->board), 4, in->fd);
		}
		if (ft_strstr(line, "Piece"))
		{
		write(in->fd, "4\n", 2);
			dims(&line, &in->tile.x, &in->tile.y, 6);
			if (!(in->tile.data = (char**)malloc(sizeof(char*) * in->tile.y)))
				exit (1);
			save_data(&(in->tile), 0, in->fd);
			play_token(in);
			ft_arrdel((void**)(in->board.data));
			ft_arrdel((void**)(in->tile.data));
		}
		ft_strdel(&line);
	}
}

int		init_game(t_game *in)
{
	char *line;

	get_next_line(0,  &line);
	if (line && (line[10] == '1' || line[10] == '2'))
	{
		in->player[0] = (ft_strstr(line, "p1")) ? 'O' : 'X';
		in->player[1] = (ft_strstr(line, "p1")) ? 'X' : 'O';
		ft_strdel(&line);
		in->board.data = NULL;
		in->tile.data = NULL;
		in->board.x = 0;
		in->board.y = 0;
		return (1);
	}
	return (0);
}
