/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:16:34 by chermist          #+#    #+#             */
/*   Updated: 2019/08/03 00:59:27 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	play_token(t_game *in)
{
	int		fd;
	int		y = 12, x = 14;
	int		height;
	static int i = 0;

	height = 0;
	write(in->fd, "Z\n", 2);
//	fd = open("rdmap", O_WRONLY);
/*	ft_putchar_fd('|', in->fd);
	ft_putchar_fd('|', in->fd);*/
	ft_putchar_fd('&', in->fd);
	write(in->fd, "\n", 1);
	heat_map(in);
	write(in->fd, "\n", 1);
	ft_putchar_fd('&', in->fd);
//	place_it(in);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	free_token(t_data *token, int flag)
{
	int	y;

	if (token->data && *(token->data))
		while (y < token->y)
			ft_strdel(&(token->data[y++]));
	free((token->data));
	token->data = NULL;
}

void	play(t_game *in)
{
	char	*line;
	char	**tmp;
	int		y;

	while (-1 < (get_next_line(0,  &line)))
	{
		if (!line)
			continue ;
		if (ft_strstr(line, "Plateau"))
		{
		write(in->fd, "3\n", 2);
			if (in->board.x == 0 && in->board.y == 0)
				dims(&line, &in->board.x, &in->board.y, 8);
			write(in->fd, "here\n", 5);
			save_data(&(in->board), 4, in->fd, in->fdm);
		}
		if (ft_strstr(line, "Piece"))
		{
		write(in->fd, "4\n", 2);
			dims(&line, &in->tile.x, &in->tile.y, 6);
			save_data(&(in->tile), 0, in->fd, in->fdm);
			play_token(in);
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
